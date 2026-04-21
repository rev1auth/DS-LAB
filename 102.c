#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int visited[MAX] = {0};
void DFS(int graph[MAX][MAX], int vertices, int node)
{ 

printf("%d ",node);
visited[node] = 1;
for (int i = 0; i < vertices; i++) {
if (graph[node][i] == 1 && !visited[i])
{ DFS(graph, vertices, i);
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
for (int i = 0; i < edges;i++) {
int src, dest;
scanf("%d %d", &src , &dest);
graph[src][dest] = 1;
graph[dest][src] = 1;
}
printf("Enter the starting vertex:"); 
scanf("%d", &start);
printf("DFS Traversal:"); 
DFS(graph, vertices,start);
return 0;
}