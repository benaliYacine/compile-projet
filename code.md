# Comparison: PHYLOG vs. TP_Lang (Unnamed Language from TP Compil)

This document outlines the main differences between the **PHYLOG** language (from the first specification) and the language described in the **TP Compil** document (referred to here as **TP_Lang**).

## 1. Overall Program Structure & Modularity

**\*PHYLOG:**
*A single monolithic block: `nom_du_programme DATA ... END CODE ... END END`.
*No explicit syntax shown for defining user functions or procedures within this structure.
**\*TP_Lang:**
*Supports modularity with functions/routines: `Fonction_1 Fonction_2 ... Fonction_n Programme_principal`.
*Main program: `PROGRAM nom_programme_principal ... END`.
\*Functions/Routines: `type ROUTINE nom_fonction (liste_paramètres) ... nom_fonction = valeur retournée ENDR`.

## 2. Comments

**\*PHYLOG:** `§ commentaire`
**\*TP_Lang:** `% commentaire`

## 3. Data Types

**\*PHYLOG:** `INTEGER`, `CHAR`, `STRING`, `FLOAT`.
**\*TP_Lang:** `INTEGER`, `CHARACTER`, `REAL`, `LOGICAL`. \*_Note:_ `CHAR` vs `CHARACTER`, `FLOAT` vs `REAL`. TP_Lang has a `LOGICAL` type, which PHYLOG doesn't explicitly list. PHYLOG has `STRING` as a distinct type, while TP_Lang handles strings via `CHARACTER nom_variable*size`.

## 4. Declarations

**\*Simple Variables:**
*PHYLOG: `TYPE: list_variables ;` (e.g., `integer: var1 | var2 ;`)
*TP_Lang: `type nom_variable1 ;` or `type nom_variable1, nom_variable2 ;`
**\*Arrays/Vectors:**
*PHYLOG: `VECTOR : nom [borne_inf, taille : type] ;`
*TP_Lang: `type nom_variable DIMENSION (size) ;` or `type nom_variable DIMENSION (size1, size2) ;` (for 1D or 2D arrays/matrices).
**\*Constants:**
*PHYLOG: `CONST: idf = valeur ;`
*TP_Lang: No explicit `CONST` keyword shown for declaration. Constants are used directly.
**\*Strings:**
*PHYLOG: `STRING` type. Values: `"chaine de caractères"`
*TP_Lang: `CHARACTER nom_variable*length`. Values: `"compilation"` (Example: `CHARACTER C*20; C = "L3";`)

## 5. Identifiers (IDF)

**\*PHYLOG:** Starts with an uppercase letter, followed by lowercase letters/digits. Maximum 8 characters.
**\*TP_Lang:** Starts with a letter, followed by letters/digits. Maximum 10 characters (a warning is issued if >10). Case-sensitive.

## 6. Operators

**\*Logical:**
*PHYLOG: `(expr1 .AND. expr2)`, `(expr1 .OR. expr2)`, `(NOT expr)`
*TP*Lang: Similar, but its table also shows `AND (et)`, `OR (ou)`.
**\*Comparison:**
*PHYLOG: `.GE.` (≥), `.L.` (<), `.LE.` (≤), `.EQ.` (=), `.DI.` (≠). (Note: `.GE.` is also mentioned for > in the text, but the table shows ≥).

* TP_Lang: `.EQ.`, `.LT.`, `.GT.`, `.GE.`, `.NE.`, `.LE.`. Its table also shows symbolic versions: `==`, `<`, `>`, `>=`, `!=`, `<=`. \*\_Key difference:* PHYLOG uses `.L.` for less than, while TP_Lang uses `.LT.`. PHYLOG uses `.DI.` for not equal, while TP_Lang uses `.NE.`.

## 7. Control Flow Statements

**\*Conditional (IF):**
*PHYLOG: `IF(condition): ... ELSE: ... END`
*TP*Lang: `IF (condition) THEN ... ELSE ... ENDIF`
**\*Looping:**
*PHYLOG: `FOR (idf: PAS: Condition_d'arrêt) ... END` (Appears to be a counted loop with a step value `PAS`).
*TP_Lang: `DOWHILE (expression conditionnelle) ... ENDDO` (A pre-test conditional loop). \*\_Different types of loops are primarily highlighted in each language's specification.\*

## 8. Input/Output

**\*PHYLOG:**
*Input: `READ ("signe de formatage": @ idf);` (e.g., `READ ("$":@ idf_entier);`)
*Output: `DISPLAY("chaîne ... signe de formatiage": idf);` (e.g., `DISPLAY ("c'est un entire $": idf_entier );`)
**\*TP_Lang:**
*Input: `READ (nom_variable);`
*Output: `WRITE ("...", nom_variable, "...");`

## 9. Function Calls

**\*PHYLOG:** No explicit user function definition is shown. Built-in functions or expressions are used directly in assignments (e.g., `A=(X+7+B)/(5,3-(-2))`).
**\*TP_Lang:** `nom_variable = CALL nom_fonction (liste_paramètres);`

## 10. Special Statements

**\*PHYLOG:** None explicitly mentioned beyond standard constructs.
**\*TP_Lang:** `EQUIVALENCE (liste_variables), (liste_variables);` for memory sharing.

## 11. Instruction Termination

\*Both languages use a semicolon (`;`) to terminate instructions.

## 12. Specific Literal Formatting

**\*PHYLOG Integers/Floats (signed):** Signed constants must be enclosed in parentheses (e.g., `(-6)`, `(-0.24)`).
**\*TP_Lang Integers/Floats (signed):** Uses standard notation (e.g., `-2084`, `0.24`).

## Summary Table

| Feature                 | PHYLOG                               | TP_Lang                                     |
| :---------------------- | :----------------------------------- | :------------------------------------------ |
| **Program Structure**   | Monolithic (`DATA`/`CODE` blocks)    | Modular (Functions/Routines + Main Program) |
| **Comments**            | `§`                                  | `%`                                         |
| **Types**               | `INTEGER, CHAR, STRING, FLOAT`       | `INTEGER, CHARACTER, REAL, LOGICAL`         |
| **Variable Decl.**      | `TYPE: list \| list ;`               | `type var1, var2`                           |
| **Array Decl.**         | `VECTOR : nom [inf,taille : type] ;` | `type nom DIMENSION (size) ;`               |
| **Constant Decl.**      | `CONST: idf = valeur ;`              | Not explicitly defined (used directly)      |
| **Identifier Rules**    | Uppercase start, max 8 chars         | Letter start, max 10 chars, case-sensitive  |
| **IF Statement**        | `IF(cond): ... ELSE: ... END`        | `IF (cond) THEN ... ELSE ... ENDIF`         |
| **Loop Statement**      | `FOR (idf: PAS: Cond) ... END`       | `DOWHILE (cond) ... ENDDO`                  |
| **Input**               | `READ ("fmt": @ idf);`               | `READ (var);`                               |
| **Output**              | `DISPLAY("msg fmt": idf);`           | `WRITE ("msg", var, "msg");`                |
| **Function Definition** | Not shown                            | `type ROUTINE name(params) ... ENDR`        |
| **Function Call**       | Implicit in expressions              | `var = CALL name(params);`                  |
| **Memory Sharing**      | Not shown                            | `EQUIVALENCE (vars1), (vars2);`             |
| **Signed Literals**     | `(-6)`, `(-0.24)`                    | `-2084`, `0.24` (standard)                  |
