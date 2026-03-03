#include <stdio.h>
#include <stdlib.h>
struct Node
{
int coeff;
int exp;
struct Node* next;
};
void insertTerm(struct Node** head_ref, int coeff, int exp)
{
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->coeff = coeff;
new_node->exp = exp;
new_node->next = NULL;
if (*head_ref == NULL)
{
*head_ref = new_node;
}
else
{
struct Node* last = *head_ref;
while (last->next != NULL)
{
last = last->next;
}
last->next = new_node;
}
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2)
{
struct Node* result = NULL;
struct Node* current = NULL;
while (poly1 != NULL && poly2 != NULL)
{
if (poly1->exp > poly2->exp)
{
insertTerm(&result, poly1->coeff, poly1->exp);
poly1 = poly1->next;
}
else if (poly1->exp < poly2->exp)
{
insertTerm(&result, poly2->coeff, poly2->exp);
poly2 = poly2->next;
}
else
{
insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
poly1 = poly1->next;
poly2 = poly2->next;
}
}
while (poly1 != NULL)
{
insertTerm(&result, poly1->coeff, poly1->exp);
poly1 = poly1->next;
}
while (poly2 != NULL)
{
insertTerm(&result, poly2->coeff, poly2->exp);
poly2 = poly2->next;
}
return result;
}
void displayPolynomial(struct Node* poly)
{
struct Node* current = poly;
while (current != NULL)
{
printf("%dx^%d ", current->coeff, current->exp);
current = current->next;
if (current != NULL)
{
printf("+ ");
}
}
printf("\n");
}
int main()
{
struct Node* poly1 = NULL;
struct Node* poly2 = NULL;
struct Node* result = NULL;
insertTerm(&poly1, 3, 2);
insertTerm(&poly1, 5, 1);
insertTerm(&poly1, 2, 0);
insertTerm(&poly2, 4, 3);
insertTerm(&poly2, 3, 1);
insertTerm(&poly2, 1, 0);
printf("First polynomial: ");
displayPolynomial(poly1);
printf("Second polynomial: ");
displayPolynomial(poly2);
result = addPolynomials(poly1, poly2);
printf("Sum of the polynomials: ");
displayPolynomial(result);
return 0;
}