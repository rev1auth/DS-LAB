#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node* next;
struct Node* prev;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}
void insertFront(struct Node** head, int data) {
struct Node* newNode = createNode(data);
if (*head != NULL) {
newNode->next = *head;
(*head)->prev = newNode;
}
*head = newNode;
}
void insertEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);
if (*head == NULL)
{
*head = newNode;
return;
}
struct Node* temp = *head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
}
void deleteFront(struct Node** head) {
if (*head == NULL) {
printf("List is empty!\n");
return;
}
struct Node* temp = *head;
*head = (*head)->next;
if (*head != NULL) {
(*head)->prev = NULL;
}
free(temp);
}
void deleteEnd(struct Node** head) {
if (*head == NULL) {
printf("List is empty!\n");
return;
}
struct Node* temp = *head;
while (temp->next != NULL) {
temp = temp->next;
}
if (temp->prev != NULL) {
temp->prev->next = NULL;
}
else
{
*head = NULL;
}
free(temp);
}
void displayList(struct Node* head) {
struct Node* temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
struct Node* head = NULL;
insertFront(&head, 10);
insertEnd(&head, 20);
insertFront(&head, 5);
insertEnd(&head, 25);
printf("Doubly Linked List after insertions: ");
displayList(head);
deleteFront(&head);
printf("Doubly Linked List after deleting front: ");
displayList(head);
deleteEnd(&head);
printf("Doubly Linked List after deleting end: ");
displayList(head);
return 0;
}