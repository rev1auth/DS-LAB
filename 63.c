#include<stdio.h>
#include<stdlib.h>

#define N 3

void insertion(int);
int deletion();
void display();

int Q[N], F = -1, R = -1;

int main()
{
    int x, ch;

    while(1)
    {
        printf("\n1:INSERTION\n2:DELETION\n3:DISPLAY\n4:EXIT");
        printf("\nEnter Your Choice = ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter An Element To Insert = ");
                scanf("%d", &x);
                insertion(x);
                break;

            case 2:
                x = deletion();
                if(x == -1)
                    printf("\nQueue Empty");
                else
                    printf("\nDeleted Element = %d", x);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
        }
    }
}
void insertion(int item)
{
    if((F == 0 && R == N-1) || (F == R + 1))
    {
        printf("\nQueue Overflow");
        return;
    }

    if(R == N-1)
        R = 0;
    else
        R = R + 1;

    Q[R] = item;

    if(F == -1)
        F = 0;
}
int deletion()
{
    int k;

    if(F == -1)
    {
        printf("\nQueue Underflow");
        return -1;
    }

    k = Q[F];

    if(F == R)
        F = R = -1;
    else if(F == N-1)
        F = 0;
    else
        F = F + 1;

    return k;
}
void display()
{
    int i;

    if(F == -1)
    {
        printf("\nQueue Empty");
        return;
    }

    printf("\nQueue Elements Are = ");

    if(F <= R)
    {
        for(i = F; i <= R; i++)
            printf("%4d", Q[i]);
    }
    else
    {
        for(i = F; i <= N-1; i++)
            printf("%4d", Q[i]);

        for(i = 0; i <= R; i++)
            printf("%4d", Q[i]);
    }
}