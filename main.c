#include "graph.h"

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);


    // Adding weighted edges: addEdge(graph, src, dest, weight)
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 4, 2, 7);


    printGraph(graph);


    freeGraph(graph);
    return 0;
}