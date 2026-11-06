#include "graph.h"

// Structure to represent an adjacency list node (with weight)
struct Node {
    int dest;
    int weight;
    struct Node* next;
};


// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};


// Structure to represent a graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};


// Function to create a new weighted adjacency list node
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}


// Function to create a graph with V vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;


    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));


    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }


    return graph;
}


// Function to add a weighted edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest with weight
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;


    // Add back-edge from dest to src for undirected graph
    newNode = createNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


// Function to print the weighted adjacency list
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* crawl = graph->array[v].head;
        printf("Vertex %d:", v);
        while (crawl) {
            printf(" -> %d (weight: %d)", crawl->dest, crawl->weight);
            crawl = crawl->next;
        }
        printf("\n");
    }
}


// Function to free allocated memory
void freeGraph(struct Graph* graph) {
    if (!graph) return;
    
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* current = graph->array[v].head;
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}