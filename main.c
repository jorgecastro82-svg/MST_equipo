#include "graph.h"

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);


    // Adding weighted edges: addEdge(graph, src, dest, weight)
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 1, 4, 7);
    addEdge(graph, 2, 3, 9);
    addEdge(graph, 3, 4, 1);


    printGraph(graph);


    freeGraph(graph);
    return 0;
}