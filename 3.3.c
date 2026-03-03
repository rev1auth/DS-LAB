#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node* next;
struct Node* prev;
};
struct Node* createNode(int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}
void insertFront(struct Node** head_ref, int data)
{
struct Node* newNode = createNode(data);
if (*head_ref == NULL)
{
*head_ref = newNode;
}
else
{
newNode->next = *head_ref;
(*head_ref)->prev = newNode;
*head_ref = newNode;
}
}
void insertRear(struct Node** head_ref, int data)
{
struct Node* newNode = createNode(data);
if (*head_ref == NULL)
{
*head_ref = newNode;
}
else
{
struct Node* temp = *head_ref;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
}
}
void deleteFront(struct Node** head_ref)
{
if (*head_ref == NULL)
{
printf("Deque is empty.\n");
}
else
{
struct Node* temp = *head_ref;
*head_ref = (*head_ref)->next;
if (*head_ref != NULL)
{
(*head_ref)->prev = NULL;
}
free(temp);
}
}
void deleteRear(struct Node** head_ref)
{
if (*head_ref == NULL)
{
printf("Deque is empty.\n");
}
else
{
struct Node* temp = *head_ref;
while (temp->next != NULL)
{
temp = temp->next;
}
if (temp->prev != NULL)
{
temp->prev->next = NULL;
}
else
{
*head_ref = NULL;
}
free(temp);
}
}
void displayDeque(struct Node* head)
{
struct Node* temp = head;
while (temp != NULL)
{
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main()
{
struct Node* deque = NULL;
insertFront(&deque, 10);
insertFront(&deque, 20);
insertFront(&deque, 30);
printf("Deque after inserting at front: ");
displayDeque(deque);
insertRear(&deque, 40);
insertRear(&deque, 50);
printf("Deque after inserting at rear: ");
displayDeque(deque);
deleteFront(&deque);
deleteFront(&deque);
printf("Deque after deleting from front: ");
displayDeque(deque);
deleteRear(&deque);
printf("Deque after deleting from rear: ");
displayDeque(deque);
return 0;
}