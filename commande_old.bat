flex lexical_old.l
Bison -d syntaxique_old.y -v
gcc lex.yy.c syntaxique_old.tab.c -lfl -ly -o compiler_old.exe