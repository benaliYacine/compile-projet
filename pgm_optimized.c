#include "pgm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

static int isNumeric(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return 0;
	while (*s)
	{
		if (!isdigit((unsigned char)*s))
			return 0;
		s++;
	}
	return 1;
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

// Optimization Passes
int apply_copy_propagation()
{
	int i, j;
	int changed = 0;
	for (i = 0; i < qc; i++)
	{
		if (strcmp(quad[i].oper, "=") == 0 && strcmp(quad[i].op2, "vide") == 0)
		{
			char *source = quad[i].op1;
			char *target = quad[i].res;

			for (j = i + 1; j < qc; j++)
			{
				if (strcmp(quad[j].op1, target) == 0)
				{
					strcpy(quad[j].op1, source);
					changed = 1;
				}
				if (strcmp(quad[j].op2, target) == 0)
				{
					strcpy(quad[j].op2, source);
					changed = 1;
				}
				if (strcmp(quad[j].res, target) == 0)
					break;
			}
		}
	}
	return changed;
}

int apply_expression_propagation()
{
	int i, j;
	int changed = 0;
	for (i = 0; i < qc; i++)
	{
		if (isNumeric(quad[i].op1) && isNumeric(quad[i].op2))
		{
			int v1 = atoi(quad[i].op1);
			int v2 = atoi(quad[i].op2);
			char *resultStr = NULL;
			int result_val;

			if (strcmp(quad[i].oper, "+") == 0)
			{
				result_val = v1 + v2;
				resultStr = IntToSTR(result_val);
			}
			else if (strcmp(quad[i].oper, "-") == 0)
			{
				result_val = v1 - v2;
				resultStr = IntToSTR(result_val);
			}
			else if (strcmp(quad[i].oper, "*") == 0)
			{
				result_val = v1 * v2;
				resultStr = IntToSTR(result_val);
			}
			else if (strcmp(quad[i].oper, "/") == 0)
			{
				if (v2 != 0) // Avoid division by zero
				{
					result_val = v1 / v2;
					resultStr = IntToSTR(result_val);
				}
				else
				{
					// Handle division by zero, e.g., skip or error
					continue;
				}
			}

			if (resultStr != NULL)
			{
				// inline into later uses
				for (j = i + 1; j < qc; j++)
				{
					if (strcmp(quad[j].op1, quad[i].res) == 0)
					{
						strcpy(quad[j].op1, resultStr);
						changed = 1;
					}
					if (strcmp(quad[j].op2, quad[i].res) == 0)
					{
						strcpy(quad[j].op2, resultStr);
						changed = 1;
					}

					// If quad[j] redefines the result variable of quad[i],
					// then propagation of quad[i]'s result must stop here.
					if (strcmp(quad[j].res, quad[i].res) == 0)
					{
						break;
					}
				}
				free(resultStr);
			}
		}
	}
	return changed;
}

int apply_redundant_expression_elimination()
{
	int i, j, k;
	int changed = 0;
	for (i = 0; i < qc; i++)
	{
		// Skip assignments and special cases
		if (strcmp(quad[i].oper, "=") == 0 ||
			strcmp(quad[i].res, "vide") == 0)
			continue;

		for (j = i + 1; j < qc; j++)
		{
			// Skip assignments and special cases
			if (strcmp(quad[j].oper, "=") == 0 ||
				strcmp(quad[j].res, "vide") == 0)
				continue;

			// Check for redefinition of operands between i and j
			int operands_changed = 0;
			for (k = i + 1; k < j; k++)
			{
				if ((strcmp(quad[i].op1, quad[k].res) == 0) ||
					(strcmp(quad[i].op2, quad[k].res) == 0))
				{
					operands_changed = 1;
					break;
				}
			}

			if (operands_changed)
			{
				continue; // Skip this potential redundant expression
			}

			// Check if operations are the same
			if (strcmp(quad[i].oper, quad[j].oper) == 0 &&
				strcmp(quad[i].op1, quad[j].op1) == 0 &&
				strcmp(quad[i].op2, quad[j].op2) == 0)
			{
				// Replace the redundant operation with an assignment
				strcpy(quad[j].oper, "=");
				strcpy(quad[j].op1, quad[i].res);
				strcpy(quad[j].op2, "vide");
				changed = 1;
			}
		}
	}
	return changed;
}

int apply_algebraic_simplification()
{
	int i;
	int changed = 0;
	for (i = 0; i < qc; i++)
	{
		// === existing cases ===
		if (strcmp(quad[i].oper, "+") == 0)
		{
			if (strcmp(quad[i].op1, "0") == 0)
			{
				strcpy(quad[i].oper, "=");
				strcpy(quad[i].op1, quad[i].op2);
				strcpy(quad[i].op2, "vide");
				changed = 1;
			}
			else if (strcmp(quad[i].op2, "0") == 0)
			{
				strcpy(quad[i].oper, "=");
				// op1 unchanged
				strcpy(quad[i].op2, "vide");
				changed = 1;
			}
		}
		// X * 0 or 0 * X  → 0
		if (strcmp(quad[i].oper, "*") == 0)
		{
			if (strcmp(quad[i].op1, "0") == 0 || strcmp(quad[i].op2, "0") == 0)
			{
				strcpy(quad[i].oper, "=");
				strcpy(quad[i].op1, "0");
				strcpy(quad[i].op2, "vide");
				changed = 1;
			}
			else if (strcmp(quad[i].op1, "1") == 0)
			{
				strcpy(quad[i].oper, "=");
				strcpy(quad[i].op1, quad[i].op2);
				strcpy(quad[i].op2, "vide");
				changed = 1;
			}
			else if (strcmp(quad[i].op2, "1") == 0)
			{
				strcpy(quad[i].oper, "=");
				// op1 unchanged
				strcpy(quad[i].op2, "vide");
				changed = 1;
			}
			// X * 2 → X + X
			else if (strcmp(quad[i].op1, "2") == 0 || strcmp(quad[i].op2, "2") == 0)
			{
				// pick the non-"2" operand
				char *v = (strcmp(quad[i].op1, "2") == 0)
							  ? quad[i].op2
							  : quad[i].op1;
				strcpy(quad[i].oper, "+");
				strcpy(quad[i].op1, v);
				strcpy(quad[i].op2, v);
				changed = 1;
			}
		}

		// Cancellation of "+1 then –1" in two consecutive quads:
		// look for:   t1 = VAR + 1
		//              t2 = t1 - 1    ⇒  t2 = VAR
		if (strcmp(quad[i].oper, "-") == 0 &&
			strcmp(quad[i].op2, "1") == 0)
		{
			int j;
			// find the producer of quad[i].op1
			for (j = i - 1; j >= 0; j--)
			{
				if (strcmp(quad[j].res, quad[i].op1) == 0 &&
					strcmp(quad[j].oper, "+") == 0)
				{
					// one of its operands must be "1"
					char *v = NULL;
					if (strcmp(quad[j].op1, "1") == 0)
						v = quad[j].op2;
					else if (strcmp(quad[j].op2, "1") == 0)
						v = quad[j].op1;

					if (v)
					{
						// replace current quad with an assignment
						strcpy(quad[i].oper, "=");
						strcpy(quad[i].op1, v);
						strcpy(quad[i].op2, "vide");
						changed = 1;
					}
					break;
				}
			}
		}
	}
	return changed;
}

void apply_dead_code_elimination()
{
	if (qc == 0)
	{ // Handle empty quad list
		return;
	}

	// Dynamically allocate the 'used' array, initialized to zeros.
	int *used = (int *)calloc(qc, sizeof(int));
	if (used == NULL)
	{
		perror("apply_dead_code_elimination: calloc for used failed");
		return;
	}

	int i, j;

	// Pass 1: Initial Marking of Essential Code.
	for (i = 0; i < qc; i++)
	{
		if (strncmp(quad[i].oper, "B", 1) == 0 ||
			strcmp(quad[i].oper, "WRITE") == 0 ||
			strcmp(quad[i].oper, "READ") == 0)
		{
			used[i] = 1;
		}
	}

	// Pass 2: Backward Propagation of Liveness.
	int changes;
	do
	{
		changes = 0;
		for (i = qc - 1; i >= 0; i--)
		{
			if (used[i])
			{
				for (j = i - 1; j >= 0; j--)
				{
					if (!used[j])
					{
						if (strcmp(quad[j].res, quad[i].op1) == 0 ||
							strcmp(quad[j].res, quad[i].op2) == 0)
						{
							used[j] = 1;
							changes = 1;
						}
					}
				}
			}
		}
	} while (changes);

	// NEW: Create mapping from old to new indices
	int *old_to_new_mapping = (int *)calloc(qc, sizeof(int));
	if (old_to_new_mapping == NULL)
	{
		perror("apply_dead_code_elimination: calloc for old_to_new_mapping failed");
		free(used); // free previously allocated memory
		return;
	}
	for (int k = 0; k < qc; ++k)
		old_to_new_mapping[k] = -1; // Initialize with -1 (dead)

	int current_new_idx = 0;
	for (int k = 0; k < qc; k++)
	{
		if (used[k])
		{
			old_to_new_mapping[k] = current_new_idx++;
		}
	}

	// NEW: Create a temporary array for the new list of quads
	qdr *new_quad_list = (qdr *)malloc(qc * sizeof(qdr)); // Max possible size
	if (new_quad_list == NULL)
	{
		perror("apply_dead_code_elimination: malloc for new_quad_list failed");
		free(used);
		free(old_to_new_mapping);
		return;
	}

	int live_quad_count = 0; // This will be the new qc
	for (i = 0; i < qc; i++)
	{
		if (used[i])
		{
			new_quad_list[live_quad_count] = quad[i]; // Copy the live quad

			// Check if it's a branch instruction and update its target
			char *oper = new_quad_list[live_quad_count].oper;
			char *op1_str = new_quad_list[live_quad_count].op1;

			// Covers BR, BZ, BNZ, BE, BNE, BG, BL, BGE, BLE
			if (strcmp(oper, "BR") == 0 || strcmp(oper, "BZ") == 0 || strcmp(oper, "BNZ") == 0 ||
				strcmp(oper, "BE") == 0 || strcmp(oper, "BNE") == 0 || strcmp(oper, "BG") == 0 ||
				strcmp(oper, "BL") == 0 || strcmp(oper, "BGE") == 0 || strcmp(oper, "BLE") == 0)
			{
				if (isNumeric(op1_str))
				{
					int old_target_idx = atoi(op1_str);
					// Ensure old_target_idx is within the bounds of the original quad array
					if (old_target_idx >= 0 && old_target_idx < qc)
					{
						int new_target_idx_val = old_to_new_mapping[old_target_idx];
						if (new_target_idx_val != -1)
						{							 // If the target quad is live and has a new index
							char new_target_buf[10]; // quad.op1 is char[10]
							sprintf(new_target_buf, "%d", new_target_idx_val);
							strcpy(new_quad_list[live_quad_count].op1, new_target_buf);
						}
						else
						{
							// Target quad was eliminated. Mark this branch's target as invalid.
							strcpy(new_quad_list[live_quad_count].op1, "X_TGT");
						}
					}
					else
					{
						// The original target index was out of bounds or invalid.
						// Mark as error or leave as is, depending on desired strictness.
						// For now, if it was out of bounds, we can mark it too.
						// strcpy(new_quad_list[live_quad_count].op1, "BAD_REF");
					}
				}
				// If op1_str is not numeric (e.g., already "X_TGT" or some other non-index string), do nothing to it.
			}
			live_quad_count++;
		}
	}

	// Copy the compacted and updated quads back to the original array
	for (i = 0; i < live_quad_count; i++)
	{
		quad[i] = new_quad_list[i];
	}
	qc = live_quad_count; // Update the global quadruple count

	// Free allocated memory
	free(used);
	free(old_to_new_mapping);
	free(new_quad_list);
}

void apply_all_optimizations()
{
	int iteration = 0;
	int changed_in_pass;
	printf("\n\n=== STARTING ALL OPTIMIZATIONS (ITERATIVE) ===\n");

	do
	{
		changed_in_pass = 0;
		iteration++;
		printf("\n--- Optimization Iteration: %d ---\n", iteration);

		// printf("Before iteration %d (all passes):\n", iteration);
		// afficher_qdr(); // Optional: show quads before this full iteration if needed for deep debug

		int qc_before_iteration = qc;

		if (apply_copy_propagation())
		{
			changed_in_pass = 1;
			// printf("After Copy Propagation (Iteration %d):\n", iteration);
			// afficher_qdr();
		}

		if (apply_expression_propagation())
		{
			changed_in_pass = 1;
			// printf("After Expression Propagation (Iteration %d):\n", iteration);
			// afficher_qdr();
		}

		if (apply_algebraic_simplification())
		{
			changed_in_pass = 1;
			// printf("After Algebraic Simplification (Iteration %d):\n", iteration);
			// afficher_qdr();
		}

		if (apply_redundant_expression_elimination())
		{
			changed_in_pass = 1;
			// printf("After Redundant Expression Elimination (Iteration %d):\n", iteration);
			// afficher_qdr();
		}

		int qc_before_dce = qc;
		apply_dead_code_elimination(); // DCE has its own internal loop for completeness
		if (qc != qc_before_dce)
		{
			changed_in_pass = 1;
			// printf("After Dead Code Elimination (Iteration %d):\n", iteration);
			// afficher_qdr();
		}
		else if (qc_before_iteration != qc)
		{
			// If DCE didn't change qc, but other passes did, still show the state
			// This case might be redundant if previous prints cover it well
		}

		if (!changed_in_pass)
		{
			printf("\nNo changes in iteration %d. Optimization fixed point reached.\n", iteration);
		}
		else
		{
			printf("\nFinished iteration %d. Changes were made, re-iterating.\n", iteration);
		}

	} while (changed_in_pass);

	printf("\n=== ALL OPTIMIZATIONS COMPLETED ===\nFinal Quadruples:\n");
	afficher_qdr();
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
	quadr("+", "5", "3", "t1");		// t1 = 5 + 3
	quadr("*", "t1", "b", "t2");	// t2 = t1 * b
	quadr("+", "t1", "c", "t3");	// t3 = t1 + c
	quadr("*", "2", "6", "t1");		// t1 tbedel tema 7abes ma tremplacer el t1 b 8
	quadr("=", "t1", "vide", "t4"); // t4 = 12 mechi 8 chouf el break li dernah bach nriglou had le cas
	quadr("*", "3", "6", "t2");
	quadr("=", "t2", "vide", "t4");
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
	quadr("*", "4", "i", "t3"); // Should be eliminated
	quadr("+", "j", "k", "t4"); // Should be eliminated

	printf("Before Redundant Expression Elimination (Simple Case):\n");
	afficher_qdr();

	apply_redundant_expression_elimination();
	printf("\nAfter Redundant Expression Elimination (Simple Case):\n");
	afficher_qdr();

	// Test redundant expression elimination with modified operands
	printf("\n\n=== TESTING REDUNDANT EXPRESSION ELIMINATION WITH MODIFIED OPERANDS ===\n");
	qc = 0;
	quadr("+", "5", "t1", "t2");   // t2 = 5 + t1
	quadr("=", "6", "vide", "t1"); // t1 = 6  (t1 gets modified)
	quadr("+", "5", "t1", "t3");   // t3 = 5 + t1 (should NOT be replaced with t3 = t2)

	printf("Before Redundant Expression Elimination (Modified Operands):\n");
	afficher_qdr();

	apply_redundant_expression_elimination();
	printf("\nAfter Redundant Expression Elimination (Modified Operands):\n");
	afficher_qdr();

	// Test algebraic simplification
	printf("\n\n=== TESTING ALGEBRAIC SIMPLIFICATION ===\n");
	qc = 0;
	quadr("+", "x", "0", "t1");
	quadr("+", "0", "x", "t1");
	quadr("*", "y", "1", "t2");
	quadr("*", "y", "0", "t2");
	quadr("+", "0", "z", "t3");
	quadr("*", "1", "w", "t4");

	printf("Before Algebraic Simplification:\n");
	afficher_qdr();

	apply_algebraic_simplification();
	printf("\nAfter Algebraic Simplification:\n");
	afficher_qdr();

	// ------------------------------------------------------------
	// New test: Multiplication by two
	// ------------------------------------------------------------
	printf("\n\n=== TESTING X*2 ⇒ X+X ===\n");
	qc = 0;
	quadr("*", "x", "2", "t1");
	printf("Before Algebraic Simplification:\n");
	afficher_qdr();
	apply_algebraic_simplification();
	printf("After Algebraic Simplification:\n");
	afficher_qdr();

	// ------------------------------------------------------------
	// New test: Cancellation +1 then -1
	// ------------------------------------------------------------
	printf("\n\n=== TESTING Y+1-1 ⇒ Y ===\n");
	qc = 0;
	quadr("+", "y", "1", "t1");
	quadr("-", "t1", "1", "t2");
	printf("Before Algebraic Simplification:\n");
	afficher_qdr();
	apply_algebraic_simplification();
	printf("After Algebraic Simplification:\n");
	afficher_qdr();

	// Test dead code elimination
	printf("\n\n=== TESTING DEAD CODE ELIMINATION ===\n");
	qc = 0; // Reset quadruple counter

	// Quad 0: t1 = 10 (Live: t1 is used by Quad 2, which is used by Quad 3 (WRITE))
	quadr("=", "10", "vide", "t1");
	// Quad 1: t2 = 20 (Dead: t2 is not used by any subsequent live instruction)
	quadr("=", "20", "vide", "t2");
	// Quad 2: t3 = t1 + 5 (Live: t3 is used by Quad 3 (WRITE) and Quad 5 (BZ))
	quadr("+", "t1", "5", "t3");
	// Quad 3: WRITE "Value of t3:", t3 (Live: WRITE operation)
	quadr("WRITE", "\"Value of t3:\"", "t3", "vide");
	// Quad 4: t4 = 30 (Dead: t4 is not used)
	quadr("=", "30", "vide", "t4");
	// Quad 5: BZ 8, t3, vide (Live: Branch instruction, uses t3. Assuming '8' is quad index target)
	quadr("BZ", "8", "t3", "vide");
	// Quad 6: t_after_branch_live = 40 (Live: Used by Quad 7 (WRITE))
	quadr("=", "40", "vide", "t_after_branch_live");
	// Quad 7: WRITE "After branch, t_after_branch_live:", t_after_branch_live (Live: WRITE operation)
	quadr("WRITE", "\"After branch, t_after_branch_live:\"", "t_after_branch_live", "vide");
	// Quad 8: (target for BZ) t_branch_target = 50 (Live: Used by Quad 9 (WRITE))
	quadr("=", "50", "vide", "t_branch_target");
	// Quad 9: WRITE "Branch target val:", t_branch_target (Live: WRITE operation)
	quadr("WRITE", "\"Branch target val:\"", "t_branch_target", "vide");
	// Quad 10: READ "%", input_var, vide (Live: READ operation)
	quadr("READ", "\"Enter value for input_var:\"", "input_var", "vide"); // op1 used as prompt
	// Quad 11: t_using_input = input_var + 2 (Live: Used by Quad 12 (WRITE))
	quadr("+", "input_var", "2", "t_using_input");
	// Quad 12: WRITE "Input based calc:", t_using_input (Live: WRITE operation)
	quadr("WRITE", "\"Input based calc:\"", "t_using_input", "vide");
	// Quad 13: t_another_dead = 60 (Dead: Not used)
	quadr("=", "60", "vide", "t_another_dead");
	// Quad 14: t_final_live = 70 (Live: used by final WRITE)
	quadr("=", "70", "vide", "t_final_live");
	// Quad 15: WRITE "Final live value: ", t_final_live (Live: WRITE operation)
	quadr("WRITE", "\"Final live value: \"", "t_final_live", "vide");

	printf("Before Dead Code Elimination :\n");
	afficher_qdr();

	apply_dead_code_elimination();

	printf("\nAfter Dead Code Elimination :\n");
	afficher_qdr();

	// Test all optimizations together
	printf("\n\n=== TESTING ALL OPTIMIZATIONS TOGETHER ===\n");
	qc = 0; // Reset quadruple counter

	// Initial Quads: A mix that allows multiple optimizations
	quadr("=", "5", "vide", "t1");					// t1 = 5 (const)
	quadr("=", "t1", "vide", "t2");					// t2 = t1 (copy)
	quadr("+", "t2", "3", "t3");					// t3 = t2 + 3 (expr prop: t3 = 5 + 3 -> t3 = 8)
	quadr("-", "t3", "0", "t4");					// t4 = t3 - 0 (alg simp: t4 = t3)
	quadr("=", "x", "vide", "unused");				// unused = x (dead code)
	quadr("+", "a", "b", "t5");						// t5 = a + b
	quadr("+", "a", "b", "t6");						// t6 = a + b (redundant with t5)
	quadr("=", "8", "vide", "t3_redef");			// t3_redef = 8 (redefines t3 logic if not careful, but new var here)
													// Let's make a scenario where DCE is more impactful after other opts.
	quadr("*", "t4", "1", "t7");					// t7 = t4 * 1 (alg simp: t7 = t4)
	quadr("=", "100", "vide", "dead_var");			// dead_var = 100
	quadr("WRITE", "t7", "vide", "vide");			// WRITE t7 (makes t7 and its dependencies live)
	quadr("=", "dead_var", "vide", "another_dead"); // another_dead = dead_var (DCE)

	printf("Before All Optimizations:\n");
	afficher_qdr();

	apply_all_optimizations(); // Call the iterative optimizer

	// Note: The final state is already printed by apply_all_optimizations
}

// Helper: Check if a string is a character literal e.g. 'a'
static int isCharLiteral(const char *s)
{
	if (s == NULL || strlen(s) != 3)
		return 0;
	return s[0] == '\'' && s[2] == '\'';
}

// Helper: Extract character from literal e.g. 'a' -> a
static char getCharFromLiteral(const char *s)
{
	if (isCharLiteral(s))
		return s[1];
	return '\0';
}

// Helper: Check if a string is a string literal e.g. "hello"
static int isStringLiteral(const char *s)
{
	if (s == NULL || strlen(s) < 2)
		return 0;
	return s[0] == '"' && s[strlen(s) - 1] == '"';
}

// Helper: Strip outermost quotes from a string literal
// out_buffer must be large enough
static void stripQuotes(const char *s, char *out_buffer, size_t buffer_size)
{
	if (isStringLiteral(s))
	{
		size_t len = strlen(s) - 2;
		if (len < buffer_size)
		{
			strncpy(out_buffer, s + 1, len);
			out_buffer[len] = '\0';
		}
		else
		{
			// Handle error: buffer too small
			out_buffer[0] = '\0';
		}
	}
	else
	{
		// Not a string literal or error
		out_buffer[0] = '\0';
	}
}

// Add code generation function to output quads as 8086 assembly
void generate_assembly(const char *filename)
{
	FILE *f = fopen(filename, "w");
	if (!f)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	fprintf(f, "TITLE GeneratedProgram\n");

	// Stack segment
	fprintf(f, "PILE SEGMENT STACK\n");
	fprintf(f, "    DW 100 DUP(?)\n");
	fprintf(f, "PILE ENDS\n\n");

	// Data segment
	fprintf(f, "DONNEE SEGMENT\n");

	// Data collection
	char vars[200][100]; // Increased size
	int var_count = 0;
	char msgs[200][256];	  // Increased size
	char msg_labels[200][20]; // Increased size
	int msg_count = 0;
	int i, j, k;

	// Fixed constants
	fprintf(f, "    DIX DW 10\n");
	fprintf(f, "    MOINS_UN DW -1\n");
	fprintf(f, "    RETOUR_LIGNE DB 0Dh, 0Ah, '$'\n");
	fprintf(f, "    PROMPT_CHAR DB '?' , '$'\n");
	fprintf(f, "    TEMP_CHAR DB ?, '$'\n");
	fprintf(f, "    BUFFER_ENTREE LABEL BYTE\n");
	fprintf(f, "      MAX_CHARS  DB 81\n");
	fprintf(f, "      CHARS_LUS DB ?\n");
	fprintf(f, "      DONNEES_BUFFER DB 81 DUP('$')\n");
	fprintf(f, "    EST_NEGATIF DB 0\n\n");

	// Collect unique variables and messages
	for (i = 0; i < qc; ++i)
	{
		char *current_ops[3] = {quad[i].op1, quad[i].op2, quad[i].res};
		// Collect messages from WRITE op1 (if string literal) or READ op1
		if (strcmp(quad[i].oper, "WRITE") == 0 || strcmp(quad[i].oper, "READ") == 0)
		{
			if (isStringLiteral(quad[i].op1))
			{
				char stripped_msg[256];
				stripQuotes(quad[i].op1, stripped_msg, sizeof(stripped_msg));
				int found = 0;
				for (j = 0; j < msg_count; ++j)
				{
					if (strcmp(msgs[j], stripped_msg) == 0)
					{
						found = 1;
						break;
					}
				}
				if (!found && strlen(stripped_msg) > 0)
				{
					strcpy(msgs[msg_count], stripped_msg);
					sprintf(msg_labels[msg_count], "MSG%d", msg_count);
					msg_count++;
				}
			}
		}

		// Collect variables
		for (k = 0; k < 3; ++k)
		{
			char *v = current_ops[k];
			if (v && strcmp(v, "vide") != 0 && !isNumeric(v) && !isStringLiteral(v) && !isCharLiteral(v))
			{
				int found = 0;
				for (j = 0; j < var_count; ++j)
				{
					if (strcmp(vars[j], v) == 0)
					{
						found = 1;
						break;
					}
				}
				if (!found)
				{
					strcpy(vars[var_count++], v);
				}
			}
		}
	}

	// Declare collected messages
	for (i = 0; i < msg_count; ++i)
	{
		fprintf(f, "    %s DB \"%s$\"\n", msg_labels[i], msgs[i]);
	}
	fprintf(f, "\n");

	// Declare collected variables
	for (i = 0; i < var_count; ++i)
	{
		// Basic type inference for known char/string vars
		if (strcmp(vars[i], "AnotherChar") == 0)
		{
			fprintf(f, "    %s DB ?\n", vars[i]);
		}
		else if (strcmp(vars[i], "GreetingStr") == 0)
		{
			fprintf(f, "    %s DB 81 DUP('$')\n", vars[i]);
		}
		else
		{
			fprintf(f, "    %s DW ?\n", vars[i]); // Default to word (16-bit)
		}
	}
	fprintf(f, "DONNEE ENDS\n\n");

	// Code segment
	fprintf(f, "LECODE SEGMENT\n");
	fprintf(f, "Debut:\n");
	fprintf(f, "    ASSUME CS:LECODE, DS:DONNEE, SS:PILE\n");
	fprintf(f, "    MOV AX, DONNEE\n");
	fprintf(f, "    MOV DS, AX\n");
	fprintf(f, "    MOV ES, AX\n\n");

	// Generate code for each quad
	for (i = 0; i < qc; ++i)
	{
		fprintf(f, "L%d: ; (%s, %s, %s, %s)\n", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
		char *op = quad[i].oper;
		char *op1_str = quad[i].op1;
		char *op2_str = quad[i].op2;
		char *res_str = quad[i].res;

		if (strcmp(op, "+") == 0)
		{
			if (isNumeric(op1_str))
				fprintf(f, "    mov ax, %s\n", op1_str);
			else
				fprintf(f, "    mov ax, %s\n", op1_str); // Assumes varName is resolved by assembler
			if (isNumeric(op2_str))
				fprintf(f, "    add ax, %s\n", op2_str);
			else
				fprintf(f, "    add ax, %s\n", op2_str);
			fprintf(f, "    mov %s, ax\n\n", res_str);
		}
		else if (strcmp(op, "-") == 0)
		{
			if (isNumeric(op1_str))
				fprintf(f, "    mov ax, %s\n", op1_str);
			else
				fprintf(f, "    mov ax, %s\n", op1_str);
			if (isNumeric(op2_str))
				fprintf(f, "    sub ax, %s\n", op2_str);
			else
				fprintf(f, "    sub ax, %s\n", op2_str);
			fprintf(f, "    mov %s, ax\n\n", res_str);
		}
		else if (strcmp(op, "*") == 0)
		{
			if (isNumeric(op1_str))
				fprintf(f, "    mov ax, %s\n", op1_str);
			else
				fprintf(f, "    mov ax, %s\n", op1_str);
			if (isNumeric(op2_str))
			{
				fprintf(f, "    mov bx, %s\n", op2_str);
				fprintf(f, "    mul bx\n");
			}
			else
			{
				fprintf(f, "    mul %s\n", op2_str);
			}
			fprintf(f, "    mov %s, ax\n\n", res_str);
		}
		else if (strcmp(op, "/") == 0)
		{
			if (isNumeric(op1_str))
				fprintf(f, "    mov ax, %s\n", op1_str);
			else
				fprintf(f, "    mov ax, %s\n", op1_str);
			fprintf(f, "    cwd\n"); // Sign extend AX into DX:AX
			if (isNumeric(op2_str))
			{
				fprintf(f, "    mov bx, %s\n", op2_str);
				fprintf(f, "    div bx\n");
			}
			else
			{
				fprintf(f, "    div %s\n", op2_str);
			}
			fprintf(f, "    mov %s, ax\n\n", res_str); // AX = quotient, DX = remainder
		}
		else if (strcmp(op, "=") == 0)
		{
			if (isNumeric(op1_str))
			{
				fprintf(f, "    mov ax, %s\n", op1_str);
			}
			else if (isCharLiteral(op1_str))
			{
				fprintf(f, "    mov al, %d ; char '%c'\n", getCharFromLiteral(op1_str), getCharFromLiteral(op1_str));
				if (strcmp(res_str, "AnotherChar") == 0)
				{ // Special handling for char var
					fprintf(f, "    mov %s, al\n\n", res_str);
				}
				else
				{ // Assign char to a word var (upper byte will be 0 or sign-extended by mov)
					fprintf(f, "    cbw ; sign extend al to ax if needed, or mov ah,0\n");
					fprintf(f, "    mov %s, ax\n\n", res_str);
				}
				continue; // Skip default mov word
			}
			else
			{ // Variable
				fprintf(f, "    mov ax, %s\n", op1_str);
			}
			// For char assignment to char var handled above
			if (strcmp(res_str, "AnotherChar") == 0 && !isCharLiteral(op1_str))
			{
				fprintf(f, "    mov %s, al ; Assuming AX lower byte is what we want for char\n\n", res_str);
			}
			else if (!(strcmp(res_str, "AnotherChar") == 0 && isCharLiteral(op1_str)))
			{ // general case if not char to char
				fprintf(f, "    mov %s, ax\n\n", res_str);
			}
		}
		else if (strcmp(op, "BR") == 0)
		{ // Unconditional jump
			fprintf(f, "    jmp L%s\n\n", op1_str);
		}
		else if (op[0] == 'B')
		{ // Conditional Branches BZ, BNZ, BE, BNE, BG, BL, BGE, BLE
			char jump_instr[4];
			if (strcmp(op, "BZ") == 0)
				strcpy(jump_instr, "jz");
			else if (strcmp(op, "BNZ") == 0)
				strcpy(jump_instr, "jnz");
			else if (strcmp(op, "BE") == 0)
				strcpy(jump_instr, "je");
			else if (strcmp(op, "BNE") == 0)
				strcpy(jump_instr, "jne");
			else if (strcmp(op, "BG") == 0)
				strcpy(jump_instr, "jg");
			else if (strcmp(op, "BL") == 0)
				strcpy(jump_instr, "jl");
			else if (strcmp(op, "BGE") == 0)
				strcpy(jump_instr, "jge");
			else if (strcmp(op, "BLE") == 0)
				strcpy(jump_instr, "jle");
			else
			{ // Should not happen
				fprintf(f, "    ; Unknown branch %s\n", op);
				continue;
			}

			if (strcmp(op, "BZ") == 0 || strcmp(op, "BNZ") == 0)
			{
				// BZ target_label, cond_var, vide
				// BNZ target_label, cond_var, vide
				if (isNumeric(op2_str))
					fprintf(f, "    mov ax, %s\n", op2_str);
				else
					fprintf(f, "    mov ax, %s\n", op2_str);
				fprintf(f, "    cmp ax, 0\n");
				fprintf(f, "    %s L%s\n\n", jump_instr, op1_str); // op1 is target label
			}
			else
			{
				// BE target_label, var1, var2  (quad.op1=target, quad.op2=var1, quad.res=var2)
				if (isNumeric(op2_str))
					fprintf(f, "    mov ax, %s\n", op2_str); // var1
				else
					fprintf(f, "    mov ax, %s\n", op2_str);
				if (isNumeric(res_str))
					fprintf(f, "    cmp ax, %s\n", res_str); // var2
				else
					fprintf(f, "    cmp ax, %s\n", res_str);
				fprintf(f, "    %s L%s\n\n", jump_instr, op1_str); // op1 is target label
			}
		}
		else if (strcmp(op, "WRITE") == 0)
		{
			// op1 is prompt (string literal or variable) or value to write if op2 is "vide"
			// op2 is variable/value to write, or "vide"
			// res is "vide"

			// Print prompt from op1 if it's a string literal
			if (isStringLiteral(op1_str))
			{
				char stripped_msg[256];
				stripQuotes(op1_str, stripped_msg, sizeof(stripped_msg));
				int msg_idx = -1;
				for (j = 0; j < msg_count; ++j)
				{
					if (strcmp(msgs[j], stripped_msg) == 0)
					{
						msg_idx = j;
						break;
					}
				}
				if (msg_idx != -1)
				{
					fprintf(f, "    lea dx, %s\n", msg_labels[msg_idx]);
					fprintf(f, "    call display_message\n");
				}
			}

			// Determine what to print (op1 or op2)
			char *to_print_str = strcmp(op2_str, "vide") != 0 ? op2_str : op1_str;

			if (strcmp(to_print_str, "vide") == 0)
			{
				// Nothing specific to print beyond a potential prompt from op1
			}
			else if (isNumeric(to_print_str))
			{
				fprintf(f, "    mov ax, %s\n", to_print_str);
				fprintf(f, "    call display_integer\n");
			}
			else if (isCharLiteral(to_print_str))
			{
				fprintf(f, "    mov dl, %d ; char '%c'\n", getCharFromLiteral(to_print_str), getCharFromLiteral(to_print_str));
				fprintf(f, "    mov ah, 02h\n");
				fprintf(f, "    int 21h\n");
			}
			else if (isStringLiteral(to_print_str) && !isStringLiteral(op1_str))
			{
				// If op1 was not the prompt, and op2 (to_print_str) is a string literal to print
				char stripped_msg[256];
				stripQuotes(to_print_str, stripped_msg, sizeof(stripped_msg));
				int msg_idx = -1;
				for (j = 0; j < msg_count; ++j)
				{
					if (strcmp(msgs[j], stripped_msg) == 0)
					{
						msg_idx = j;
						break;
					}
				}
				// It might be a new message if not caught in initial scan
				if (msg_idx == -1 && strlen(stripped_msg) > 0)
				{
					// This is tricky - messages should be declared in .data
					// For simplicity, assume it was declared or this case is rare
					fprintf(f, "    ; Untracked message literal in WRITE: %s\n", stripped_msg);
				}
				if (msg_idx != -1)
				{
					fprintf(f, "    lea dx, %s\n", msg_labels[msg_idx]);
					fprintf(f, "    call display_message\n");
				}
			}
			else
			{ // It's a variable
				if (strcmp(to_print_str, "AnotherChar") == 0)
				{ // Special char var
					fprintf(f, "    mov dl, %s\n", to_print_str);
					fprintf(f, "    mov ah, 02h\n");
					fprintf(f, "    int 21h\n");
				}
				else if (strcmp(to_print_str, "GreetingStr") == 0)
				{ // Special string var
					fprintf(f, "    lea dx, %s\n", to_print_str);
					fprintf(f, "    call display_message\n");
				}
				else
				{ // Default: assume word variable
					fprintf(f, "    mov ax, %s\n", to_print_str);
					fprintf(f, "    call display_integer\n");
				}
			}
			fprintf(f, "    call print_newline\n\n");
		}
		else if (strcmp(op, "READ") == 0)
		{
			// op1 = prompt (string literal) or format specifier
			// op2 = variable to read into
			// res = "vide"
			if (isStringLiteral(op1_str))
			{
				char stripped_msg[256];
				stripQuotes(op1_str, stripped_msg, sizeof(stripped_msg));
				int msg_idx = -1;
				for (j = 0; j < msg_count; ++j)
				{
					if (strcmp(msgs[j], stripped_msg) == 0)
					{
						msg_idx = j;
						break;
					}
				}
				if (msg_idx != -1)
				{
					fprintf(f, "    lea dx, %s\n", msg_labels[msg_idx]);
					fprintf(f, "    call display_message\n");
				}
			}
			// Default prompt if op1 was not a known message (e.g. format specifier)
			// else if (strcmp(op1_str,"$")==0 || strcmp(op1_str,"%")==0 || strcmp(op1_str,"#")==0 || strcmp(op1_str,"&")==0){
			//    fprintf(f, "    ; Simple prompt for READ for %s into %s \n", op1_str, op2_str);
			// }

			if (strcmp(op2_str, "AnotherChar") == 0)
			{ // Read single char
				fprintf(f, "    mov ah, 01h ; Read char with echo\n");
				fprintf(f, "    int 21h\n");
				fprintf(f, "    mov %s, al\n", op2_str);
			}
			else if (strcmp(op2_str, "GreetingStr") == 0)
			{ // Read string
				fprintf(f, "    lea dx, BUFFER_ENTREE\n");
				fprintf(f, "    call scan_string_proc\n");
				fprintf(f, "    ; Copy BUFFER_ENTREE to %s and ensure $-termination\n", op2_str);
				fprintf(f, "    lea si, DONNEES_BUFFER\n");
				fprintf(f, "    lea di, %s\n", op2_str);
				fprintf(f, "    mov cl, CHARS_LUS\n");
				fprintf(f, "    xor ch, ch ; CX = actual_len\n");
				fprintf(f, "    cmp cl, 0\n");
				fprintf(f, "    je read_str_done_%d\n", i);
				fprintf(f, "    rep movsb ; Copy string\n");
				fprintf(f, "read_str_done_%d:\n", i);
				fprintf(f, "    mov byte ptr [di], '$' ; Terminate with $\n");
			}
			else
			{										   // Default: Read integer
				fprintf(f, "    call scan_integer\n"); // AX = scanned integer
				fprintf(f, "    mov %s, ax\n", op2_str);
			}
			fprintf(f, "    call print_newline\n\n");
		}
	}

	// Exit program
	fprintf(f, "\nFin_Programme:\n");
	fprintf(f, "    MOV AH, 4Ch\n");
	fprintf(f, "    INT 21h\n\n");

	// Runtime procedures
	fprintf(f, "; procédure to display string at DS:DX (must be $-terminated)\n");
	fprintf(f, "display_message proc near\n");
	fprintf(f, "    push ax\n");
	fprintf(f, "    mov ah, 09h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    pop ax\n");
	fprintf(f, "    ret\n");
	fprintf(f, "display_message endp\n\n");

	fprintf(f, "print_newline proc near\n");
	fprintf(f, "    push ax\n");
	fprintf(f, "    push dx\n");
	fprintf(f, "    lea dx, RETOUR_LIGNE\n");
	fprintf(f, "    call display_message\n");
	fprintf(f, "    pop dx\n");
	fprintf(f, "    pop ax\n");
	fprintf(f, "    ret\n");
	fprintf(f, "print_newline endp\n\n");

	fprintf(f, "; procedure to display integer in AX (handles negative)\n");
	fprintf(f, "display_integer proc near\n");
	fprintf(f, "    push ax\n");
	fprintf(f, "    push bx\n");
	fprintf(f, "    push cx\n");
	fprintf(f, "    push dx\n");
	fprintf(f, "    cmp ax, 0\n");
	fprintf(f, "    jge disp_positive_num_%d\n", qc); // Unique label
	fprintf(f, "    push ax\n");
	fprintf(f, "    mov dl, '-'\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    pop ax\n");
	fprintf(f, "    neg ax\n");
	fprintf(f, "disp_positive_num_%d:\n", qc);
	fprintf(f, "    xor cx, cx\n");
	fprintf(f, "    mov bx, 10\n");
	fprintf(f, "disp_convert_loop_%d:\n", qc);
	fprintf(f, "    xor dx, dx\n");
	fprintf(f, "    div bx\n");
	fprintf(f, "    push dx\n");
	fprintf(f, "    inc cx\n");
	fprintf(f, "    cmp ax, 0\n");
	fprintf(f, "    jne disp_convert_loop_%d\n", qc);
	fprintf(f, "disp_print_loop_%d:\n", qc);
	fprintf(f, "    pop dx\n");
	fprintf(f, "    add dl, '0'\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    loop disp_print_loop_%d\n", qc);
	fprintf(f, "    pop dx\n");
	fprintf(f, "    pop cx\n");
	fprintf(f, "    pop bx\n");
	fprintf(f, "    pop ax\n");
	fprintf(f, "    ret\n");
	fprintf(f, "display_integer endp\n\n");

	fprintf(f, "; procedure to scan integer into AX (handles negative & backspace)\n");
	fprintf(f, "scan_integer proc near\n");
	fprintf(f, "    push bx\n");
	fprintf(f, "    push cx\n");
	fprintf(f, "    push dx\n");
	fprintf(f, "    push si\n\n");
	fprintf(f, "    mov cx, 0             ; CX will hold the number\n");
	fprintf(f, "    mov EST_NEGATIF, 0     ; Flag for negative number\n");
	fprintf(f, "    mov si, 0             ; Digit counter\n\n");
	fprintf(f, "scan_read_char_loop_%d:\n", qc);
	fprintf(f, "    mov ah, 01h           ; Read char with echo\n");
	fprintf(f, "    int 21h               ; AL = char\n\n");
	fprintf(f, "    cmp al, 0Dh           ; Carriage return?\n");
	fprintf(f, "    je scan_end_input_%d\n\n", qc);
	fprintf(f, "    cmp al, '-'           ; Minus sign?\n");
	fprintf(f, "    je scan_handle_minus_%d\n\n", qc);
	fprintf(f, "    cmp al, 8             ; Backspace?\n");
	fprintf(f, "    je scan_handle_backspace_%d\n\n", qc);
	fprintf(f, "    cmp al, '0'\n");
	fprintf(f, "    jl scan_ignore_char_%d\n", qc);
	fprintf(f, "    cmp al, '9'\n");
	fprintf(f, "    jg scan_ignore_char_%d\n\n", qc);
	fprintf(f, "    ; It's a digit\n");
	fprintf(f, "    cmp si, 5             ; Limit to 5 digits (max ~32767)\n");
	fprintf(f, "    jge scan_ignore_char_%d ; Too many digits, ignore\n\n");
	fprintf(f, "    inc si\n");
	fprintf(f, "    sub al, '0'           ; Convert char to number\n");
	fprintf(f, "    mov ah, 0\n");
	fprintf(f, "    push ax               ; Save digit\n\n");
	fprintf(f, "    mov ax, cx            ; AX = current number\n");
	fprintf(f, "    mov bx, DIX\n");
	fprintf(f, "    mul bx                ; AX = current number * 10\n");
	fprintf(f, "    jc scan_overflow_%d   ; Check for overflow from mul\n");
	fprintf(f, "    mov cx, ax\n\n");
	fprintf(f, "    pop ax                ; Restore digit\n");
	fprintf(f, "    add cx, ax            ; CX = CX + digit\n");
	fprintf(f, "    jc scan_overflow_%d   ; Check for overflow from add\n");
	fprintf(f, "    jmp scan_read_char_loop_%d\n\n", qc);
	fprintf(f, "scan_handle_minus_%d:\n", qc);
	fprintf(f, "    cmp si, 0             ; Minus only allowed as first char\n");
	fprintf(f, "    jne scan_ignore_char_%d\n");
	fprintf(f, "    cmp EST_NEGATIF, 1     ; Only one minus allowed\n");
	fprintf(f, "    je scan_ignore_char_%d\n");
	fprintf(f, "    mov EST_NEGATIF, 1\n");
	fprintf(f, "    jmp scan_read_char_loop_%d\n\n", qc);
	fprintf(f, "scan_handle_backspace_%d:\n", qc);
	fprintf(f, "    cmp si, 0             ; Anything to backspace?\n");
	fprintf(f, "    je scan_read_char_loop_%d\n\n");
	fprintf(f, "    dec si                ; Decrement digit count\n");
	fprintf(f, "    ; Erase char on screen: print backspace, space, backspace\n");
	fprintf(f, "    mov dl, 08h\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    mov dl, ' '\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    mov dl, 08h\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n\n");
	fprintf(f, "    mov ax, cx\n");
	fprintf(f, "    xor dx, dx\n");
	fprintf(f, "    mov bx, DIX\n");
	fprintf(f, "    div bx                ; AX = CX / 10\n");
	fprintf(f, "    mov cx, ax\n");
	fprintf(f, "    cmp si, 0             ; If all digits removed and was negative\n");
	fprintf(f, "    jne scan_read_char_loop_%d\n");
	fprintf(f, "    mov EST_NEGATIF, 0     ; Reset minus flag if no digits left\n");
	fprintf(f, "    jmp scan_read_char_loop_%d\n\n", qc);
	fprintf(f, "scan_overflow_%d:\n", qc);
	fprintf(f, "    ; Handle overflow - maybe clear CX and restart, or error\n");
	fprintf(f, "    ; For now, just ignore and continue (bad number will result)\n");
	fprintf(f, "    mov cx, 0 ; Clear to avoid partial large number\n");
	fprintf(f, "    mov si, 0\n");
	fprintf(f, "    mov EST_NEGATIF, 0\n");
	fprintf(f, "    ; Could print an error message here\n");
	fprintf(f, "    jmp scan_read_char_loop_%d\n\n", qc);
	fprintf(f, "scan_ignore_char_%d:\n", qc);
	fprintf(f, "    mov dl, 07h           ; Bell for invalid char\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    ; also erase the bad char from screen\n");
	fprintf(f, "    mov dl, 08h\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    mov dl, ' '\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    mov dl, 08h\n");
	fprintf(f, "    mov ah, 02h\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    jmp scan_read_char_loop_%d\n\n", qc);
	fprintf(f, "scan_end_input_%d:\n", qc);
	fprintf(f, "    cmp EST_NEGATIF, 1\n");
	fprintf(f, "    jne scan_positive_res_%d\n", qc);
	fprintf(f, "    cmp cx, 0 ; if cx is 0, -0 is 0\n");
	fprintf(f, "    je scan_positive_res_%d\n", qc);
	fprintf(f, "    neg cx\n");
	fprintf(f, "scan_positive_res_%d:\n", qc);
	fprintf(f, "    mov ax, cx            ; Result in AX\n\n");
	fprintf(f, "    pop si\n");
	fprintf(f, "    pop dx\n");
	fprintf(f, "    pop cx\n");
	fprintf(f, "    pop bx\n");
	fprintf(f, "    ret\n");
	fprintf(f, "scan_integer endp\n\n");

	fprintf(f, "; Procedure to read a string using DOS buffered input (AH=0Ah)\n");
	fprintf(f, "; Expects DX to point to a buffer: max_len, actual_len, data...\n");
	fprintf(f, "scan_string_proc proc near\n");
	fprintf(f, "    push ax\n");
	fprintf(f, "    mov ah, 0Ah\n");
	fprintf(f, "    int 21h\n");
	fprintf(f, "    pop ax\n");
	fprintf(f, "    ret\n");
	fprintf(f, "scan_string_proc endp\n\n");

	// End of code segment and program
	fprintf(f, "LECODE ENDS\n");
	fprintf(f, "END Debut\n");

	fclose(f);
	printf("Assembly code generated in %s\n", filename);
}

// int main()
// {
// 	printf("\n=== COMPILER OPTIMIZATION DEMONSTRATION ===\n");
// 	printf("This program demonstrates various compiler optimizations.\n");
// 	printf("Each optimization is tested separately with a fresh set of quadruples.\n\n");

// 	test_optimizations();
// 	return 0;
// }
