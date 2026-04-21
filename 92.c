#include <stdio.h>
#include <stdlib.h>
#define CACHE_SIZE 10
#define EMPTY -1
typedef struct {
int key;
int value;
} CacheEntry;
CacheEntry cache[CACHE_SIZE];
int hash(int key) {
return key % CACHE_SIZE;
}
void initCache() {
for (int i = 0; i < CACHE_SIZE; i++)
{ cache[i].key = EMPTY;
cache[i].value = 0;
}
}
void insert(int key, int value)
{ int index = hash(key);
int start = index;
while (cache[index].key != EMPTY && cache[index].key != key) { index =
(index + 1) % CACHE_SIZE;
if (index == start) {
printf("Cache is full! Cannot insert key: %d\n", key); return;
}
}
cache[index].key = key;
cache[index].value = value;
printf("Inserted key: %d with value: %d at index: %d\n", key, value, index);
}
int search(int key) {
int index = hash(key);
int start = index;
while (cache[index].key != EMPTY) { 
if
(cache[index].key == key) {
return cache[index].value;
}
index = (index + 1) % CACHE_SIZE; 
if
(index == start) break;
}
return -1;
}
void displayCache()
{ printf("\nCache contents:\n");
for (int i = 0; i < CACHE_SIZE; i++) { 
if
(cache[i].key != EMPTY) {
printf("Index %d: Key = %d, Value = %d\n", i, cache[i].key, cache[i].value);
}
else
{
printf("Index %d: Empty\n", i);
}
}
}
int main() {
int choice, key, value;
initCache();
while (1) {
printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: "); scanf("%d",
&choice);
switch (choice)
{ case 1:
printf("Enter key and value to insert: ");
scanf("%d %d", &key, &value); insert(key, value);
break;
case 2:
printf("Enter key to search: ");
scanf("%d", &key);
value = search(key);
if (value != -1)
printf("Key %d found with value %d\n", key, value); 
else
printf("Key %d not found in cache\n", key); 
break;
case 3:
displayCache();
break;
case 4:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}