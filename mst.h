#pragma once

typedef struct{
    int src,dest,weight;
}Edge;

typedef struct node_int{
    int data;
    struct node_int *next;
}Node_int;

typedef struct{
    Node_int *head;
    Node_int *end;
}LinkedList_int;

void init_list_int(LinkedList_int *l);
void push_int(LinkedList_int *l,Node_int *n);
int is_in_int(LinkedList_int l,int value);
void join_int(LinkedList_int *l1, LinkedList_int *l2);
Node_int *create_node_int(int i);

//edge list
typedef struct node_edge{
    Edge data;
    struct node_edge *next;
}Node_edge;

typedef struct{
    Node_edge *head;
    Node_edge *end;
}LinkedList_edge;

void init_list_edge(LinkedList_edge *l);
void push_edge(LinkedList_edge *l,Node_edge *n);
Node_edge *create_node_edge(Edge e);

int get_mst_total_weight(Edge *arr,int num_v,int num_e);
//sorts
void heapsort(Edge *arr,int n);

void heapify(Edge *arr,int n);

void siftdown(Edge *arr,int n,int index);

void swap(Edge *a, Edge *b);
