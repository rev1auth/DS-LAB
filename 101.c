#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = -1, rear =-1; 
int visited[MAX] = {0};
void enqueue(int value)
{ 
if (rear == MAX -1)
return;
if (front == -1)
front = 0;
queue[++rear] = value;
}
int dequeue() {
if (front == -1 || front >
rear) return -1;
return queue[front++];
}
void BFS(int graph[MAX][MAX], int vertices, int
start) { enqueue(start);
visited[start] = 1;
while (front <= rear)
{ 
int node = dequeue();
printf("%d ", node);
for (int i = 0; i < vertices; i++) {
if (graph[node][i] == 1 && !visited[i])
{ enqueue(i);
visited[i] = 1;
}
}
}
}
int main() {
int vertices, edges, start;
printf("Enter number of vertices:"); 
scanf("%d", &vertices);
int graph[MAX][MAX] = {0};
printf("Enter number of edges: ");
scanf("%d", &edges);
printf("Enter edges (source destination):\n"); 
for (int i = 0; i < edges;i++)
 {
int src, dest;
scanf("%d %d", &src , &dest);
graph[src][dest] = 1;
graph[dest][src] = 1; 
}
printf("Enter the starting vertex:"); 
scanf("%d", &start);
printf("BFS Traversal: ");
BFS(graph, vertices, start);
return 0;
}