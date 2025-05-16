%token idf str character inti real mc_logi mc_data mc_end mc_code mc_integer verg mc_float mc_char mc_string mc_const mc_vector mc_read mc_display mc_if mc_else mc_for mc_not mc_true mc_false mc_and mc_or mc_g mc_l mc_ge mc_le mc_eq mc_di add sub mul divi aff mc_dowhile mc_enddo pvg deux_points crochet_ouv crochet_ferm po pf virg barre arobase err

%left mc_or mc_and
%left mc_l mc_g mc_ge mc_eq mc_di mc_le
%left add sub
%left mul divi

%type <str> TAILLE
%type <str> partie_gauch_affectation
%type <str> valeur
%type <str> EXPRE
%type <str> TERM
%type <str> OPERAND
%type <str> FACTOR
%type <str> EXPREt
%type <str> CONDI
%type <str> CONDIT
%type <str> LOGI
%type <str> var
%type <str> assignment
%type <str> for_statement

%%

s: idf mc_data DECS mc_end mc_code INSTS mc_end mc_end
;

VIDE:
;

TYPE: mc_integer | mc_float | mc_char | mc_logi | mc_string 
;

DECS: VIDE | ENSDEC
;

ENSDEC: ENSDEC DEC | DEC
;

DEC: TYPE deux_points ENSIDF_dec pvg
    | mc_const deux_points idf partie_gauch_affectation pvg
    | mc_vector deux_points idf crochet_ouv TAILLE two_points TYPE crochet_ferm pvg
;

partie_gauch_affectation: aff valeur | VIDE
;

ENSIDF_dec: ENSIDF_dec barre idf partie_gauch_affectation
           | idf partie_gauch_affectation
; 

EXPRE: EXPRE mc_or CONDIT
     | EXPRE mc_and CONDIT
     | CONDIT
;

CONDIT: CONDIT mc_l EXPREt
      | CONDIT mc_g EXPREt
      | CONDIT mc_ge EXPREt
      | CONDIT mc_eq EXPREt
      | CONDIT mc_di EXPREt
      | CONDIT mc_le EXPREt
      | EXPREt
;

EXPREt: EXPREt add TERM
      | EXPREt sub TERM
      | TERM
;

TERM: TERM mul FACTOR
    | TERM divi FACTOR
    | FACTOR
;

FACTOR: po EXPRE pf
      | OPERAND
      | mc_not FACTOR
;

OPERAND: idf
       | LOGI
       | inti
       | real
       | idf crochet_ouv TAILLE crochet_ferm
;

TAILLE: TAILLE verg valeur
      | valeur
;

LOGI: mc_true
    | mc_false
;

INSTS: VIDE | ENSINST
;

ENSINST: ENSINST INST | INST
;

INST: if_statement | read_statement | write_statement | dowhile_statement | assignment | for_statement
;

var: idf
   | idf po TAILLE pf
;

if_statement: B_if else_clause mc_end
;

B_if: A_if deux_points INSTS
;

A_if: mc_if po CONDI pf
;

else_clause: mc_else deux_points INSTS | VIDE
;

assignment: var aff valeur pvg
;

valeur: str
      | character
      | EXPRE
;

read_statement: mc_read po str deux_points arobase var pf pvg
{
    // Check if $3 is exactly one of the format strings
    char* format = $3;
    if (strcmp(format, "\"$\"") != 0 && 
        strcmp(format, "\"%\"") != 0 && 
        strcmp(format, "\"#\"") != 0 && 
        strcmp(format, "\"&\"") != 0) {
        yyerror("Semantic error", format, "is not a valid format sign. Use $ % # or &");
    }
    
    // Then check if the format matches variable type
    char* varType = GetTypeFromTS($6);
    if ((strcmp(format, "\"$\"") == 0 && strcmp(varType, "INTEGER") != 0) ||
        (strcmp(format, "\"%\"") == 0 && strcmp(varType, "FLOAT") != 0) ||
        (strcmp(format, "\"#\"") == 0 && strcmp(varType, "STRING") != 0) ||
        (strcmp(format, "\"&\"") == 0 && strcmp(varType, "CHAR") != 0)) {
        yyerror("Semantic error", format, "does not match variable type");
    }
}
;

write_statement: mc_display po str deux_points var pf pvg 
{
    // Check if the string contains one of the format signs at the end
    char* message = $3;
    int len = strlen(message);
    
    // Check if string ends with a format sign
    if (len < 3) {
        yyerror("Semantic error", message, "does not contain a format sign");
    }
    
    char formatChar = message[len-2]; // Get the character before the closing quote
    
    // Verify format sign is valid
    if (formatChar != '$' && formatChar != '%' && formatChar != '#' && formatChar != '&') {
        yyerror("Semantic error", message, "does not end with a valid format sign ($ % # &)");
    }
    
    // Then check if the format matches variable type
    char* varType = GetTypeFromTS($5);
    if ((formatChar == '$' && strcmp(varType, "INTEGER") != 0) ||
        (formatChar == '%' && strcmp(varType, "FLOAT") != 0) ||
        (formatChar == '#' && strcmp(varType, "STRING") != 0) ||
        (formatChar == '&' && strcmp(varType, "CHAR") != 0)) {
        yyerror("Semantic error", "Format sign", "does not match variable type");
    }
}
| mc_display po str pf pvg
;

dowhile_statement: B_while INSTS mc_enddo
;

B_while: A_while po CONDI pf
;

A_while: mc_dowhile
;

CONDI: EXPRE
;

for_statement: A_for INSTS mc_end
;

A_for: mc_for po idf deux_points valeur deux_points CONDI pf
;