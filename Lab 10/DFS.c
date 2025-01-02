#include <stdio.h>
#define MAX 100

void DFS(int graph[MAX][MAX], int n, int vertex, int visited[MAX]) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, n, i, visited);
        }
    }
}

int isConnected(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};

    DFS(graph, n, 0, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    if (isConnected(graph, n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
