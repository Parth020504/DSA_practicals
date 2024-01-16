#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the linked list
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } 
        else if (poly2->exponent > poly1->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } 
        else {
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) {
                insertTerm(&result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If one polynomial has more terms, add them to the result
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to subtract two polynomials
Term* subtractPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } 
        else if (poly2->exponent > poly1->exponent) {
            insertTerm(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } 
        else {
            int diff_coeff = poly1->coefficient - poly2->coefficient;
            if (diff_coeff != 0) {
                insertTerm(&result, diff_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If one polynomial has more terms, add them to the result
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1,8,3);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 5, 3);
    insertTerm(&poly2, 2, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    Term* difference = subtractPolynomials(poly1, poly2);
    printf("Difference of the polynomials: ");
    displayPolynomial(difference);

    // // Free memory allocated for the linked lists
    // while (poly1 != NULL) {
    //     Term* temp = poly1;
    //     poly1 = poly1->next;
    //     free(temp);
    // }
    // while (poly2 != NULL) {
    //     Term* temp = poly2;
    //     poly2 = poly2->next;
    //     free(temp);
    // }
    // while (sum != NULL) {
    //     Term* temp = sum;
    //     sum = sum->next;
    //     free(temp);
    // }
    // while (difference != NULL) {
    //     Term* temp = difference;
    //     difference = difference->next;
    //     free(temp);
    // }

    return 0;
}
