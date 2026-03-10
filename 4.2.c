#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* last) {
    if (last == NULL) return;
    struct Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

struct Node* insertAtBeginning(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

struct Node* deleteNode(struct Node* last, int key) {
    if (last == NULL) return NULL;
    struct Node *curr = last->next, *prev = last;
    if (last->next == last && last->data == key) {
        free(last);
        return NULL;
    }
    if (last->next->data == key) {
        struct Node* temp = last->next;
        last->next = temp->next;
        free(temp);
        return last;
    }
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            if (curr == last) last = prev;
            free(curr);
            return last;
        }
    } while (curr != last->next);
    return last;
}

int main() {
    struct Node* last = NULL;
    last = insertAtBeginning(last, 30);
    last = insertAtBeginning(last, 20);
    last = insertAtBeginning(last, 10);
    traverse(last);
    last = deleteNode(last, 20);
    traverse(last);
    return 0;
}