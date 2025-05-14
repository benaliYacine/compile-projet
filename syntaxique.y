%{
    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include "ts_HASH_TABLE.c"
    #include "int_pile.c"
    #include "str_pile.c"
    #include "expre_pile.c"
    #include "fct_etiq.c"
    #include "pgm.c"
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    
    StackNode_int *deb_else = NULL;
    StackNode_int *deb_for = NULL;
    int qc=0;
    StackNode_int *Fin_if = NULL;
    StackNode_int *Fin_for = NULL;
    StackNode_int *fin_routine = NULL;
    StackNode* Operandes_pile = NULL;
    char tmp[20];
    int nb_argument=0;
    extern char *type;
    char taille[20];
%}

%union {
    int entier;
    char* str;
    float reel;
}

%token <str>idf eq mc_data mc_code mc_end mc_vector <entier>inti <reel>real mc_integer mc_float mc_char mc_string mc_const mc_read mc_display pvg <str>str ch mc_if mc_else mc_for mc_not deux_points crochet_ouv crochet_ferm par_ouv par_ferm virgule barre arobase plus minus mul divi err mc_and mc_or mc_g mc_l mc_ge mc_le mc_eq mc_di <str>mc_true <str>mc_false

%left mc_or
%left mc_and
%left mc_g mc_l mc_ge mc_le mc_eq mc_di
%left plus minus
%left mul divi
%right mc_not

%type <str> TYPE
%type <str> EXPRESSION
%type <str> TERM
%type <str> FACTOR
%type <str> PRIMARY
%type <str> CONDITION
%type <str> VALUE
%type <str> VAR

%%

PROGRAM: PROGRAM_NAME mc_data DECLARATIONS mc_end mc_code INSTRUCTIONS mc_end mc_end 
        { printf("Programme syntaxiquement correct!\n"); YYACCEPT; }
;

PROGRAM_NAME: idf {
    if(Declarer($1)){
        yyerror("Semantic error", $1, "already declared");
    }
    rechercher($1, "PROGRAM", " ", " ", 0, " ", 0);
}
;

DECLARATIONS: /* vide */ 
            | DECLARATIONS DECLARATION
;

DECLARATION: VARIABLE_DECLARATION
           | VECTOR_DECLARATION
           | CONSTANT_DECLARATION
;

VARIABLE_DECLARATION: TYPE deux_points LIST_VARIABLES pvg
;

LIST_VARIABLES: VAR
              | LIST_VARIABLES barre VAR
;

VECTOR_DECLARATION: mc_vector deux_points idf crochet_ouv EXPRESSION virgule EXPRESSION deux_points TYPE crochet_ferm pvg {
    if(Declarer($3)){
        yyerror("Semantic error", $3, "already declared");
    }
    
    // Verify array bounds
    if(!isInteger($5) || !isInteger($7)){
        yyerror("Semantic error", "", "array bounds must be integers");
    }
    
    // Create array size string for table
    char arraySize[50];
    sprintf(arraySize, "%s,%s", $5, $7);
    
    // Add to symbol table as TABLEAU
    rechercher($3, "IDF", $9, "", 0, arraySize, 0);
    
    // Initialize array
    initiali_tab($3, arraySize);
    
    // Generate quadruples for array bounds
    StackNode* operande_high = pop(&Operandes_pile);
    StackNode* operande_low = pop(&Operandes_pile);
    
    quadr("Bounds", "0", strdup(operande_low->operande_name), "vide");
    quadr("Bounds", "0", strdup(operande_high->operande_name), "vide");
    quadr("ADEC", $3, "vide", "vide");
}
;

CONSTANT_DECLARATION: mc_const deux_points idf eq VALUE pvg {
    if(Declarer($3)){
        yyerror("Semantic error", $3, "already declared");
    }
    
    // Mark as constant in symbol table
    char constType[30];
    sprintf(constType, "CONST_%s", GetTypeFromVal($5));
    
    // Set value directly in symbol table
    rechercher($3, "IDF", constType, $5, 0, "", 0);
    
    // Generate quadruple for constant initialization
    StackNode* poppedElement = pop(&Operandes_pile);
    quadr("=", poppedElement->operande_name, "vide", $3);
}
;

TYPE: mc_integer { $$ = strdup("INTEGER"); strcpy(type, "INTEGER"); }
    | mc_float { $$ = strdup("FLOAT"); strcpy(type, "FLOAT"); }
    | mc_char { $$ = strdup("CHAR"); strcpy(type, "CHAR"); }
    | mc_string { $$ = strdup("STRING"); strcpy(type, "STRING"); }
;

INSTRUCTIONS: /* vide */
            | INSTRUCTIONS INSTRUCTION
;

INSTRUCTION: AFFECTATION
           | INPUT
           | OUTPUT
           | IF_STATEMENT
           | FOR_STATEMENT
;

AFFECTATION: VAR eq EXPRESSION pvg {
    // Check if variable is declared
    if(!Declarer($1)){
        yyerror("Semantic error", $1, "not declared");
    }
    
    // Check if it's a constant - cannot reassign
    if(strstr(GetTypeFromTS($1), "CONST_") != NULL){
        yyerror("Semantic error", $1, "is a constant and cannot be reassigned");
    }
    
    // Check type compatibility
    if(!areCompatible(GetTypeFromTS($1), $3)){
        yyerror("Semantic error", "", "incompatible types in assignment");
    }
    
    // Handle array assignment or regular variable assignment
    if(strstr(GetTypeFromTS($1), "TABLEAU") != NULL){
        A_M_tab($1, taille, $3);
    } else {
        if(!SetValInTS($1, $3)){
            yyerror("Semantic error", $1, "assignment not accepted");
        }
    }
    
    // Generate quadruple for assignment
    StackNode* operande_expr = pop(&Operandes_pile);
    StackNode* operande_var = pop(&Operandes_pile);
    
    quadr("=", operande_expr->operande_name, "vide", operande_var->operande_name);
}
;

VAR: idf {
    if(!Declarer($1)){
        yyerror("Semantic error", $1, "not declared");
    }
    
    // Push identifier to operand stack
    char *type = strdup(GetTypeFromTS($1));
    push(&Operandes_pile, "VAR", strdup($1), type);
    
    $$ = $1;
}
| idf crochet_ouv EXPRESSION crochet_ferm {
    if(!Declarer($1)){
        yyerror("Semantic error", $1, "not declared");
    }
    
    // Check if it's an array
    if(strstr(GetTypeFromTS($1), "TABLEAU") == NULL){
        yyerror("Semantic error", $1, "is not an array");
    }
    
    // Check if index is an integer
    if(!isInteger($3)){
        yyerror("Semantic error", "", "array index must be an integer");
    }
    
    // Create indexed var representation
    char indexed_var[100];
    StackNode* operande_index = pop(&Operandes_pile);
    sprintf(indexed_var, "%s[%s]", $1, operande_index->operande_name);
    
    // Push to operand stack
    push(&Operandes_pile, "VAR", indexed_var, GetTypeFromTS($1));
    
    // Store array index for potential use in quadruple generation
    strcpy(taille, $3);
    
    $$ = $1;
}
;

INPUT: mc_read par_ouv str deux_points arobase idf par_ferm pvg {
    if(!Declarer($6)){
        yyerror("Semantic error", $6, "not declared");
    }
    
    // Get type of variable for compatibility check with format string
    char* varType = GetTypeFromTS($6);
    char* formatType = NULL;
    
    // Extract format from string literal (remove quotes)
    char* format = strdup($3);
    format++; // Skip opening quote
    format[strlen(format)-1] = '\0'; // Remove closing quote
    
    // Check format compatibility with variable type
    if(strcmp(format, "$") == 0) formatType = "INTEGER";
    else if(strcmp(format, "%") == 0) formatType = "FLOAT";
    else if(strcmp(format, "#") == 0) formatType = "STRING";
    else if(strcmp(format, "&") == 0) formatType = "CHAR";
    else yyerror("Semantic error", format, "invalid format specifier");
    
    if(strstr(varType, formatType) == NULL){
        yyerror("Semantic error", "", "format specifier doesn't match variable type");
    }
    
    // Generate quadruple for input
    quadr("READ", format, "vide", $6);
}
;

OUTPUT: mc_display par_ouv str deux_points EXPRESSION par_ferm pvg {
    // Extract format from string literal (remove quotes)
    char* format = strdup($3);
    format++; // Skip opening quote
    format[strlen(format)-1] = '\0'; // Remove closing quote
    
    // Determine expected type from format
    char* formatType = NULL;
    if(strstr(format, "$") != NULL) formatType = "INTEGER";
    else if(strstr(format, "%") != NULL) formatType = "FLOAT";
    else if(strstr(format, "#") != NULL) formatType = "STRING";
    else if(strstr(format, "&") != NULL) formatType = "CHAR";
    
    // Generate quadruple for output
    StackNode* operande_expr = pop(&Operandes_pile);
    
    // Check type compatibility with format
    if(formatType != NULL && !areCompatible(formatType, operande_expr->operande_type)){
        yyerror("Semantic error", "", "expression type doesn't match format specifier");
    }
    
    quadr("DISPLAY", format, operande_expr->operande_name, "vide");
}
;

IF_STATEMENT: IF_START INSTRUCTIONS ELSE_PART mc_end {
    // Complete IF statement - set jump destination for the end of IF
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_if), 1, tmp);
}
;

IF_START: mc_if par_ouv CONDITION par_ferm deux_points {
    // Start of IF - create conditional jump
    StackNode* operande_cond = pop(&Operandes_pile);
    
    // Save current quadruple position for the conditional jump
    push_int(&deb_else, qc);
    
    // Generate BZ (branch if zero/false) quadruple
    quadr("BZ", "", strdup(operande_cond->operande_name), "vide");
}
;

ELSE_PART: /* vide */ {
    // No ELSE part - just set the branch target to current position
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&deb_else), 1, tmp);
}
| mc_else deux_points {
    // ELSE part exists - generate unconditional jump to skip ELSE when IF is taken
    push_int(&Fin_if, qc);
    quadr("BR", "", "vide", "vide");
    
    // Set the target for the conditional jump at the beginning of ELSE
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&deb_else), 1, tmp);
} INSTRUCTIONS
;

FOR_STATEMENT: FOR_START INSTRUCTIONS mc_end {
    // End of FOR loop - create back jump to condition check
    sprintf(tmp, "%d", pop_int(&deb_for));
    quadr("BR", tmp, "vide", "vide");
    
    // Set jump destination for loop exit
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_for), 1, tmp);
}
;

FOR_START: mc_for par_ouv idf deux_points EXPRESSION deux_points CONDITION par_ferm {
    // Initialize loop counter
    if(!Declarer($3)){
        yyerror("Semantic error", $3, "not declared");
    }
    
    if(!isInteger($5)){
        yyerror("Semantic error", "", "loop step must be an integer");
    }
    
    // Initialize loop counter with the initial value
    StackNode* operande_step = pop(&Operandes_pile);
    quadr("=", operande_step->operande_name, "vide", $3);
    
    // Save current position for loop condition check
    push_int(&deb_for, qc);
    
    // Evaluate loop condition
    StackNode* operande_cond = pop(&Operandes_pile);
    
    // Generate conditional jump to exit loop if condition is false
    push_int(&Fin_for, qc);
    quadr("BZ", "", strdup(operande_cond->operande_name), "vide");
    
    // Increment loop counter at the end of each iteration
    // Will be done in quadruple generation at the end of the loop
}
;

CONDITION: EXPRESSION {
    // Check if expression is boolean or can be converted to boolean
    if(!isBoolean($1) && !canBeBoolean($1)){
        yyerror("Semantic error", $1, "not a boolean expression");
    }
    
    $$ = $1;
}
;

EXPRESSION: EXPRESSION mc_or TERM {
    if(!isBoolean($1) || !isBoolean($3)){
        yyerror("Semantic error", "", "OR operator requires boolean operands");
    }
    
    // Generate quadruples for logical OR
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadLogic(2, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    bool val1 = strcmp($1, "true") == 0;
    bool val2 = strcmp($3, "true") == 0;
    bool result = val1 || val2;
    
    $$ = result ? strdup("true") : strdup("false");
}
| EXPRESSION mc_and TERM {
    if(!isBoolean($1) || !isBoolean($3)){
        yyerror("Semantic error", "", "AND operator requires boolean operands");
    }
    
    // Generate quadruples for logical AND
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadLogic(3, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    bool val1 = strcmp($1, "true") == 0;
    bool val2 = strcmp($3, "true") == 0;
    bool result = val1 && val2;
    
    $$ = result ? strdup("true") : strdup("false");
}
| EXPRESSION mc_g TERM {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for greater than comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(6, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    $$ = strdup(gtEntities($1, $3));
}
| EXPRESSION mc_l TERM {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for less than comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(5, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    $$ = strdup(ltEntities($1, $3));
}
| EXPRESSION mc_ge TERM {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for greater than or equal comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(3, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    $$ = strdup(geEntities($1, $3));
}
| EXPRESSION mc_le TERM {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for less than or equal comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(4, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    $$ = strdup(leEntities($1, $3));
}
| EXPRESSION mc_eq TERM {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for equality comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(1, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    $$ = strdup(eqEntities($1, $3));
}
| EXPRESSION mc_di TERM {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for inequality comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(2, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    $$ = strdup(neEntities($1, $3));
}
| TERM {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "EXPRESSION", poppedElement->operande_name, poppedElement->operande_type);
    $$ = $1;
}
;

TERM: TERM plus FACTOR {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for addition");
    }
    
    // Generate quadruples for addition
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("+", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "TERM", T, type);
    
    // Compute result for semantic analysis
    $$ = strdup(addEntities($1, $3));
}
| TERM minus FACTOR {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for subtraction");
    }
    
    // Generate quadruples for subtraction
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("-", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "TERM", T, type);
    
    // Compute result for semantic analysis
    $$ = strdup(subEntities($1, $3));
}
| FACTOR {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "TERM", poppedElement->operande_name, poppedElement->operande_type);
    $$ = $1;
}
;

FACTOR: FACTOR mul PRIMARY {
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for multiplication");
    }
    
    // Generate quadruples for multiplication
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("*", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "FACTOR", T, type);
    
    // Compute result for semantic analysis
    $$ = strdup(mulEntities($1, $3));
}
| FACTOR divi PRIMARY {
    if(isEntityZero($3)){
        yyerror("Semantic error", "", "division by zero");
    }
    
    if(!canPerformArithmetic($1, $3)){
        yyerror("Semantic error", "", "incompatible types for division");
    }
    
    // Generate quadruples for division
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("/", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "FACTOR", T, type);
    
    // Compute result for semantic analysis
    $$ = strdup(divEntities($1, $3));
}
| PRIMARY {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
    $$ = $1;
}
;

PRIMARY: par_ouv EXPRESSION par_ferm {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "PRIMARY", poppedElement->operande_name, poppedElement->operande_type);
    $$ = $2;
}
| mc_not PRIMARY {
    if(!isBoolean($2) && !canBeBoolean($2)){
        yyerror("Semantic error", "", "NOT operator requires boolean operand");
    }
    
    // Generate quadruple for logical NOT
    StackNode* operande = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    
    quadr("NOT", operande->operande_name, "vide", res_tmp);
    
    push(&Operandes_pile, "PRIMARY", res_tmp, "LOGICAL");
    
    // Compute result for semantic analysis
    bool val = strcmp($2, "true") == 0;
    $$ = !val ? strdup("true") : strdup("false");
}
| VALUE {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "PRIMARY", poppedElement->operande_name, poppedElement->operande_type);
    $$ = $1;
}
| VAR {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "PRIMARY", poppedElement->operande_name, poppedElement->operande_type);
    $$ = $1;
}
;

VALUE: inti {
    char backToStr[20];
    sprintf(backToStr, "%d", $1);
    push(&Operandes_pile, "VALUE", strdup(backToStr), "INTEGER");
    $$ = strdup(backToStr);
}
| real {
    char backToStr[20];
    sprintf(backToStr, "%g", $1);
    push(&Operandes_pile, "VALUE", strdup(backToStr), "FLOAT");
    $$ = strdup(backToStr);
}
| ch {
    push(&Operandes_pile, "VALUE", $1, "CHAR");
    $$ = $1;
}
| str {
    push(&Operandes_pile, "VALUE", $1, "STRING");
    $$ = $1;
}
| mc_true {
    push(&Operandes_pile, "VALUE", "true", "LOGICAL");
    $$ = strdup("true");
}
| mc_false {
    push(&Operandes_pile, "VALUE", "false", "LOGICAL");
    $$ = strdup("false");
}
;

%%

int main(int argc, char** argv)
{
    if (argc > 1) {
        file_name = argv[1];
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            perror("Cannot open input file");
            return EXIT_FAILURE;
        }
        yyin = file;
    }
    
    yyparse(); // Launch syntactic analyzer
    yylex();   // Launch lexical analyzer
    
    printf("Analyse lexicale et syntaxique terminee avec succes.\n");
    printf("Affichage de la table des symboles.\n");
    afficher();
    printf("Affichage des quadruplets.\n");
    afficher_qdr();
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    printf("Affichage de la pile.\n");
    afficher_pile(Operandes_pile);
    
    return 0;
}

yywrap()
{}

int yyerror(char* msg, char* entite, char* description)
{
    printf("File \"%s\", line %d, character %d: %s, %s %s\n", file_name, nb_ligne, Col, msg, entite, description);
    
    printf("Affichage de la table des symboles.\n");
    afficher();
    printf("Affichage des quadruplets.\n");
    afficher_qdr();
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    printf("Affichage de la pile.\n");
    afficher_pile(Operandes_pile);
    
    exit(EXIT_FAILURE);
} 