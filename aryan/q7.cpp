// program to generate 3 address codes along with quadruples, triples, and indirect triples

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Quadruples
typedef struct {
    char op;
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

// Structure for Triples
typedef struct {
    char op[10];
    char arg1[10];
    char arg2[10];
} Triple;

void generateCode(char op, char arg1[], char arg2[], char result[], Quadruple *quads, Triple *trips, Triple *indirect_trips, int *quadCount, int *tripCount, int *indirect_tripCount) {
    // Generate Quadruples
    quads[*quadCount].op = op;
    strcpy(quads[*quadCount].arg1, arg1);
    strcpy(quads[*quadCount].arg2, arg2);
    strcpy(quads[*quadCount].result, result);
    (*quadCount)++;

    // Generate Triples
    strcpy(trips[*tripCount].op, &op);
    strcpy(trips[*tripCount].arg1, arg1);
    strcpy(trips[*tripCount].arg2, arg2);
    (*tripCount)++;

    // Generate Indirect Triples
    strcpy(indirect_trips[*indirect_tripCount].op, &op);
    strcpy(indirect_trips[*indirect_tripCount].arg1, arg1);
    strcpy(indirect_trips[*indirect_tripCount].arg2, arg2);
    (*indirect_tripCount)++;
}

int main() {
    char op, arg1[10], arg2[10], result[10];
    Quadruple quadruples[100];
    Triple triples[100];
    Triple indirect_triples[100];
    int quadCount = 0, tripCount = 0, indirect_tripCount = 0;

    printf("Enter the expression (e.g., a + b): ");
    scanf("%s %c %s %s", arg1, &op, arg2, result);

    generateCode(op, arg1, arg2, result, quadruples, triples, indirect_triples, &quadCount, &tripCount, &indirect_tripCount);

    // Output the generated code
    printf("\nThree Address Code:\n");
    printf("%s = %s %c %s\n", result, arg1, op, arg2);

    printf("\nQuadruples:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("(%c, %s, %s, %s)\n", quadruples[i].op, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }

    printf("\nTriples:\n");
    for (int i = 0; i < tripCount; i++) {
        printf("(%s, %s, %s)\n", triples[i].op, triples[i].arg1, triples[i].arg2);
    }

    printf("\nIndirect Triples:\n");
    for (int i = 0; i < indirect_tripCount; i++) {
        printf("(%s, %s, %s)\n", indirect_triples[i].op, indirect_triples[i].arg1, indirect_triples[i].arg2);
    }

    return 0;
}

// Eg .Input expression: a = b * -c + b * -c