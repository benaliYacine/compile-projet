flex lexical.l
Bison -d syntaxique.y -v
gcc lex.yy.c syntaxique.tab.c -lfl -ly -o tp.exe