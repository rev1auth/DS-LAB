#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int DATA;
    struct list *LINK;
} node;

node *f = NULL, *r = NULL;

void display();
void insertion(int);
int deletion();

int main()
{
    int ch, item, p;

    while(1)
    {
        printf("\n\n1:INSERTION\n2:DELETION\n3:DISPLAY\n4:EXIT");
        printf("\nEnter Your Choice = ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter Element = ");
                scanf("%d", &item);
                insertion(item);
                break;

            case 2:
                p = deletion();
                if(p == -1)
                    printf("\nLinked Queue Underflow");
                else
                    printf("\nDeleted Element = %d", p);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
        }
    }
}
void insertion(int x)
{
    node *newnode = (node*)malloc(sizeof(node));

    if(newnode == NULL)
    {
        printf("\nMemory Allocation Failed");
        return;
    }

    newnode->DATA = x;
    newnode->LINK = NULL;

    if(f == NULL)
        f = r = newnode;
    else
    {
        r->LINK = newnode;
        r = newnode;
    }
}
int deletion()
{
    node *temp;
    int k;

    if(f == NULL)
        return -1;

    temp = f;
    k = f->DATA;

    if(f == r)
        f = r = NULL;
    else
        f = f->LINK;

    free(temp);   

    return k;
}
void display()
{
    node *temp = f;

    if(f == NULL)
    {
        printf("\nLinked Queue Empty");
        return;
    }

    printf("\nLinked Queue Elements Are:\n");

    while(temp != NULL)
    {
        printf("%d\t", temp->DATA);
        temp = temp->LINK;
    }
}