#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct Node {
int key;
char value[100];
struct Node* next;
} Node;
Node* hashTable[TABLE_SIZE];
int hashFunction(int key)
{ return key % TABLE_SIZE;
}
void insert(int key, const char* value)
{
int index = hashFunction(key);
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->key = key;
strcpy(newNode->value, value);
newNode->next = hashTable[index];
hashTable[index] = newNode;
printf("Inserted (%d, %s) at index %d\n", key, value, index);
}
char* search(int key) {
int index = hashFunction(key);
Node* temp = hashTable[index];
while (temp != NULL) {
if (temp->key == key)
return temp->value;
temp = temp->next;
}
return NULL;
}
void delete(int key) {
int index = hashFunction(key);
Node* temp = hashTable[index];
Node* prev = NULL;
while (temp != NULL) { if
(temp->key == key) {
if (prev == NULL) hashTable[index] = temp->next;
else
prev->next = temp->next;
free(temp);
printf("Deleted key %d from index %d\n", key, index); 
return;
}
prev = temp;
temp = temp->next;
}
printf("Key %d not found for deletion\n", key);
}
void display() {
for (int i = 0; i < TABLE_SIZE; i++) { printf("Index %d:", i);
Node* temp = hashTable[i];
while (temp != NULL) {
printf("(%d, %s) -> ", temp->key, temp->value); temp
= temp->next;
}
printf("NULL\n");
}
}
int main() {
insert(1, "Apple");
insert(11,
"Banana");
insert(21, "Cherry");
insert(5, "Date");
display();
int searchKey = 11;
char* result = search(searchKey);
if (result)
printf("Found key %d with value: %s\n", searchKey, result); else
printf("Key %d not found\n", searchKey);
delete(11);
display();
return 0;
}