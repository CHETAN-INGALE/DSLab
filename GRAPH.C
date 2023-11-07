#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph {
    int numVertices;
    int* visited;
    struct node** adjLists;
};

struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void BFS(struct Graph* graph, int startVertex) {
    struct node* temp = graph->adjLists[startVertex];
    graph->visited[startVertex] = 1;
    printf("Visited %d \n", startVertex);

    while (temp) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            BFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    struct node* temp = graph->adjLists[startVertex];
    graph->visited[startVertex] = 1;
    printf("Visited %d \n", startVertex);

    while (temp) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    printf("Graph:\n");
    printGraph(graph);

    printf("Breadth First Search starting from vertex 0:\n");
    BFS(graph, 0);

    // Reset visited for next traversal
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }

    printf("\nDepth First Search starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}

