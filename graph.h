#pragma once
#include <stdio.h>
#include <stdlib.h>

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
struct Node* createNode(int dest, int weight);


// Function to create a graph with V vertices
struct Graph* createGraph(int numVertices);


// Function to add a weighted edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight);


// Function to print the weighted adjacency list
void printGraph(struct Graph* graph);


// Function to free allocated memory
void freeGraph(struct Graph* graph);



