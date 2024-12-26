#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[], int vertices) {
    visited[vertex] = true;
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited, vertices);
        }
    }
}

bool isConnected(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};
    dfs(graph, 0, visited, vertices);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            return false; 
        }
    }
    return true; 
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    if (isConnected(graph, vertices)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
