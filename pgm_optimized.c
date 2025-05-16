#include "pgm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qc; // Define the global variable qc

// convert interger to string
char *IntToSTR(int i)
{
	char s[15];
	sprintf(s, "%d", i);
	return strdup(s);
}

char *FloatToSTR(int i)
{
	char s[15];
	sprintf(s, "%g", i);
	return strdup(s);
}

void quadr(char opr[], char op1[], char op2[], char res[])
{
	strcpy(quad[qc].oper, opr);
	strcpy(quad[qc].op1, op1);
	strcpy(quad[qc].op2, op2);
	strcpy(quad[qc].res, res);
	qc++;
}

// creation d'1 quad arithmeitque
void createQuadCompare(int type, char *cond1, char *cond2, char *res)
{
	char *TypeBR;
	switch (type)
	{
	case 1:
	{ // 1==> "==" (égale)
		TypeBR = strdup("BNE");
	}
	break;
	case 2:
	{ // 2==> "!=" (different)
		TypeBR = strdup("BE");
	}
	break;
	case 3:
	{ // 3==> ">=" higher Or Equal
		TypeBR = strdup("BL");
	}
	break;
	case 4:
	{ // 4==> "<=" lower Or Equal
		TypeBR = strdup("BG");
	}
	break;
	case 5:
	{ // 5==> "<" lower
		TypeBR = strdup("BGE");
	}
	break;
	case 6:
	{ // 6==> ">" higher
		TypeBR = strdup("BLE");
	}
	break;
	}
	quadr(TypeBR, IntToSTR(qc + 3), cond1, cond2);
	quadr("=", "1", "vide", res);
	quadr("BR", IntToSTR(qc + 2), "vide", "vide");
	quadr("=", "0", "vide", res);
}

// creation d'1 quad logique
void createQuadLogic(int type, char *cond1, char *cond2, char *res)
{
	switch (type)
	{
	case 1:
	{ // 1==> not
		quadr("BNZ", IntToSTR(qc + 3), cond1, "vide");
		quadr("=", "1", "vide", res);
		quadr("BR", IntToSTR(qc + 2), "vide", "vide");
		quadr("=", "0", "vide", res);
	}
	break;
	case 2:
	{ // 2==> or
		quadr("BNZ", IntToSTR(qc + 4), cond1, "vide");
		quadr("BNZ", IntToSTR(qc + 3), cond2, "vide");
		quadr("=", "0", "vide", res);
		quadr("BR", IntToSTR(qc + 2), "vide", "vide");
		quadr("=", "1", "vide", res);
	}
	break;
	case 3:
	{ // 3==> and
		quadr("BZ", IntToSTR(qc + 4), cond1, "vide");
		quadr("BZ", IntToSTR(qc + 3), cond2, "vide");
		quadr("=", "1", "vide", res);
		quadr("BR", IntToSTR(qc + 2), "vide", "vide");
		quadr("=", "0", "vide", res);
	}
	break;
	}
}

void ajour_quad(int num_quad, int colon_quad, char val[])
{
	if (colon_quad == 0)
		strcpy(quad[num_quad].oper, val);
	else if (colon_quad == 1)
		strcpy(quad[num_quad].op1, val);
	else if (colon_quad == 2)
		strcpy(quad[num_quad].op2, val);
	else if (colon_quad == 3)
		strcpy(quad[num_quad].res, val);
}

void afficher_qdr()
{
	printf("*********************LesQuadruplets***********************\n");
	int i;
	for (i = 0; i < qc; i++)
	{
		printf("\n %d - ( %s , %s , %s , %s )", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
		printf("\n---------------------------------------------------\n");
	}
}

void apply_copy_propagation();
void apply_expression_propagation();
void apply_redundant_expression_elimination();
void apply_algebraic_simplification();
void apply_dead_code_elimination();

// Optimization Passes
// Optimization Passes
void apply_copy_propagation()
{
	int i, j;
	for (i = 0; i < qc; i++)
	{
		if (strcmp(quad[i].oper, "=") == 0 && strcmp(quad[i].op2, "vide") == 0)
		{
			char *source = quad[i].op1;
			char *target = quad[i].res;

			for (j = i + 1; j < qc; j++)
			{
				if (strcmp(quad[j].op1, target) == 0)
					strcpy(quad[j].op1, source);
				if (strcmp(quad[j].op2, target) == 0)
					strcpy(quad[j].op2, source);
				if (strcmp(quad[j].res, target) == 0)
					break;
			}
		}
	}
}

void apply_expression_propagation()
{
	int i, j;
	for (i = 0; i < qc; i++)
	{
		// Look for expressions like t1 = 2 + 3
		if (strcmp(quad[i].oper, "+") == 0 &&
			atoi(quad[i].op1) > 0 && atoi(quad[i].op2) > 0)
		{
			// Compute the result
			int result = atoi(quad[i].op1) + atoi(quad[i].op2);
			char resultStr[20];
			sprintf(resultStr, "%d", result);

			// Find usages of the temp variable and replace them with the computed value
			char *temp = quad[i].res;
			for (j = i + 1; j < qc; j++)
			{
				if (strcmp(quad[j].op1, temp) == 0)
					strcpy(quad[j].op1, resultStr);
				if (strcmp(quad[j].op2, temp) == 0)
					strcpy(quad[j].op2, resultStr);
			}
		}
	}
}

void apply_redundant_expression_elimination()
{
	int i, j;
	for (i = 0; i < qc; i++)
	{
		// Skip assignments and special cases
		if (strcmp(quad[i].oper, "=") == 0 ||
			strcmp(quad[i].res, "_deleted") == 0 ||
			strcmp(quad[i].res, "vide") == 0)
			continue;

		for (j = i + 1; j < qc; j++)
		{
			// Skip assignments and special cases
			if (strcmp(quad[j].oper, "=") == 0 ||
				strcmp(quad[j].res, "_deleted") == 0 ||
				strcmp(quad[j].res, "vide") == 0)
				continue;

			// Check if operations are the same
			if (strcmp(quad[i].oper, quad[j].oper) == 0 &&
				strcmp(quad[i].op1, quad[j].op1) == 0 &&
				strcmp(quad[i].op2, quad[j].op2) == 0)
			{
				// Replace the redundant operation with an assignment
				strcpy(quad[j].oper, "=");
				strcpy(quad[j].op1, quad[i].res);
				strcpy(quad[j].op2, "vide");
			}
		}
	}
}

void apply_algebraic_simplification()
{
	int i;
	for (i = 0; i < qc; i++)
	{
		if (strcmp(quad[i].oper, "+") == 0)
		{
			if (strcmp(quad[i].op1, "0") == 0)
				strcpy(quad[i].oper, "=");
			else if (strcmp(quad[i].op2, "0") == 0)
				strcpy(quad[i].oper, "=");
		}
		if (strcmp(quad[i].oper, "*") == 0)
		{
			if (strcmp(quad[i].op1, "1") == 0 || strcmp(quad[i].op2, "1") == 0)
				strcpy(quad[i].oper, "=");
		}
	}
}

void apply_dead_code_elimination()
{
	int used[1000] = {0}; // Track which assignments are used
	int i, j;

	// First, mark all result variables or variables used in operations with side effects
	for (i = 0; i < qc; i++)
	{
		if (strcmp(quad[i].res, "result") == 0 ||
			strncmp(quad[i].oper, "B", 1) == 0)
		{
			used[i] = 1;
		}
	}

	// Now, work backwards to mark all assignments that contribute to used results
	int changes = 1;
	while (changes)
	{
		changes = 0;
		for (i = qc - 1; i >= 0; i--)
		{
			if (used[i])
			{
				// If this quad is used, mark all quads that define its operands
				for (j = i - 1; j >= 0; j--)
				{
					if (!used[j] &&
						(strcmp(quad[j].res, quad[i].op1) == 0 ||
						 strcmp(quad[j].res, quad[i].op2) == 0))
					{
						used[j] = 1;
						changes = 1;
					}
				}
			}
		}
	}

	// Compact the quad array by removing dead code
	int new_qc = 0;
	for (i = 0; i < qc; i++)
	{
		if (used[i])
		{
			// Move the quad if necessary
			if (i != new_qc)
				quad[new_qc] = quad[i];
			new_qc++;
		}
	}

	qc = new_qc;
}

void test_optimizations()
{
	// Test copy propagation
	printf("\n\n=== TESTING COPY PROPAGATION ===\n");
	qc = 0;
	quadr("=", "a", "vide", "t1");
	quadr("=", "t1", "vide", "t2");
	quadr("+", "t1", "b", "t3");
	quadr("*", "t2", "c", "t4");

	printf("Before Copy Propagation:\n");
	afficher_qdr();

	apply_copy_propagation();
	printf("\nAfter Copy Propagation:\n");
	afficher_qdr();

	// Test expression propagation
	printf("\n\n=== TESTING EXPRESSION PROPAGATION ===\n");
	qc = 0;
	quadr("+", "5", "3", "t1");	 // t1 = 5 + 3
	quadr("*", "t1", "b", "t2"); // t2 = t1 * b
	quadr("+", "t1", "c", "t3"); // t3 = t1 + c

	printf("Before Expression Propagation:\n");
	afficher_qdr();

	apply_expression_propagation();
	printf("\nAfter Expression Propagation:\n");
	afficher_qdr();

	// Test redundant expression elimination
	printf("\n\n=== TESTING REDUNDANT EXPRESSION ELIMINATION ===\n");
	qc = 0;
	quadr("*", "4", "i", "t1");
	quadr("+", "j", "k", "t2");
	quadr("*", "4", "i", "t3");
	quadr("+", "j", "k", "t4");

	printf("Before Redundant Expression Elimination:\n");
	afficher_qdr();

	apply_redundant_expression_elimination();
	printf("\nAfter Redundant Expression Elimination:\n");
	afficher_qdr();

	// Test algebraic simplification
	printf("\n\n=== TESTING ALGEBRAIC SIMPLIFICATION ===\n");
	qc = 0;
	quadr("+", "x", "0", "t1");
	quadr("*", "y", "1", "t2");
	quadr("+", "0", "z", "t3");
	quadr("*", "1", "w", "t4");

	printf("Before Algebraic Simplification:\n");
	afficher_qdr();

	apply_algebraic_simplification();
	printf("\nAfter Algebraic Simplification:\n");
	afficher_qdr();

	// Test dead code elimination
	printf("\n\n=== TESTING DEAD CODE ELIMINATION ===\n");
	qc = 0;
	quadr("=", "a", "vide", "t1");	  // t1 is used in t4, should be kept
	quadr("=", "b", "vide", "t2");	  // t2 is used in t4, should be kept
	quadr("=", "c", "vide", "t3");	  // t3 is not used (dead code), should be removed
	quadr("=", "d", "vide", "t5");	  // t5 is not used (dead code), should be removed
	quadr("+", "t1", "t2", "t4");	  // t4 is used in result, should be kept
	quadr("*", "t4", "10", "result"); // result is important, should be kept

	printf("Before Dead Code Elimination:\n");
	afficher_qdr();

	apply_dead_code_elimination();
	printf("\nAfter Dead Code Elimination:\n");
	afficher_qdr();
}

int main()
{
	printf("\n=== COMPILER OPTIMIZATION DEMONSTRATION ===\n");
	printf("This program demonstrates various compiler optimizations.\n");
	printf("Each optimization is tested separately with a fresh set of quadruples.\n\n");

	test_optimizations();
	return 0;
}
