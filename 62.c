#include <stdio.h>
#include <stdlib.h>
typedef struct PrintJob
{
int jobNumber;
struct PrintJob *next;
} PrintJob;
typedef struct
{
PrintJob *front;
PrintJob *rear;
}
PrinterQueue;
void initializeQueue(PrinterQueue *queue);
void enqueue(PrinterQueue *queue, int jobNumber);
int dequeue(PrinterQueue *queue);
int isEmpty(PrinterQueue *queue);
int main()
{
PrinterQueue queue;
initializeQueue(&queue);
enqueue(&queue, 1);
enqueue(&queue, 2);
enqueue(&queue, 3);
enqueue(&queue, 4);
while (!isEmpty(&queue))
{
    int jobNumber = dequeue(&queue);
printf("Printing job: %d\n", jobNumber);
}
return 0;
}
void initializeQueue(PrinterQueue *queue)
{
queue->front = NULL;
queue->rear = NULL;
}
void enqueue(PrinterQueue *queue, int jobNumber)
{
PrintJob *newJob = (PrintJob *)malloc(sizeof(PrintJob));
if (newJob == NULL) {
printf("Memory allocation failed!\n");
exit(1);
}
newJob->jobNumber = jobNumber;
newJob->next = NULL;
if (isEmpty(queue))
{
queue->front = newJob;
}
else
{
queue->rear->next = newJob;
}
queue->rear = newJob;
}
int dequeue(PrinterQueue *queue)
{
if (isEmpty(queue))
{
printf("Queue is empty!\n");
exit(1);
}
PrintJob *temp = queue->front;
int jobNumber = temp->jobNumber;
queue->front = queue->front->next;
free(temp);
if (queue->front == NULL)
{
queue->rear = NULL;
}
return jobNumber;
}
int isEmpty(PrinterQueue *queue)
{
return queue->front == NULL;
}