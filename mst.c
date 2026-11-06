#include "mst.h"
#include <stdlib.h>

int get_mst_total_weight(Edge *arr,int num_v,int num_e){
    heapsort(arr,num_e);

    LinkedList_int sets[num_v];
    for(int i = 0; i < num_v;i++){
        init_list_int(sets + i);
        push_int(sets + i,create_node_int(i));
    }
    LinkedList_edge mst;
    init_list_edge(&mst);
    int iterations = 0;
    int edge_index = 0;

    while(iterations < num_v-1){
        int index_src = -1,index_dest = -1;

        Edge current_edge = arr[edge_index++];
        for(int i = 0;i < num_v;i++){
            if(is_in_int(sets[i],current_edge.src)) index_src = i;
            if(is_in_int(sets[i],current_edge.dest)) index_dest = i;
            if(index_src != -1 && index_dest != -1) break; 
        }
        if(index_src == index_dest) continue; //evitar ciclo
        push_edge(&mst,create_node_edge(current_edge));
        join_int(sets + index_src,sets + index_dest);

        ++iterations;
    }

    //in the end we get a linked list with all needed edges
    int total_weight = 0;
    for(Node_edge *aux = mst.head; aux != NULL; aux = aux->next) total_weight += (aux->data).weight;
    
    return total_weight;
    
}

void init_list_int(LinkedList_int *l){
    l->head = NULL;
    l->end = NULL;
}

Node_int *create_node_int(int i){
    Node_int *n = malloc(sizeof(Node_int));
    n->data = i;
    n->next = NULL;
}

void push_int(LinkedList_int *l,Node_int *n){
    if(!l->head){
        l->head = l->end = n;
        return;
    }
    l->end->next = n;
    l->end = l->end->next;
}

int is_in_int(LinkedList_int l,int value){
    for(Node_int *aux = l.head; aux != NULL; aux = aux->next){
        if(aux->data == value) return 1;
    }
    return 0;
}

void join_int(LinkedList_int *l1, LinkedList_int *l2){
    l1->end->next = l2->head;
    l1->end = l2->end;
    l2->head = l2->end = NULL;
}

void init_list_edge(LinkedList_edge *l){
    l->head = NULL;
}

Node_edge *create_node_edge(Edge i){
    Node_edge *n = malloc(sizeof(Node_edge));
    n->data = i;
    n->next = NULL;
}

void push_edge(LinkedList_edge *l,Node_edge *n){
    if(!l->head){
        l->head = l->end = n;
        return;
    }
    l->end->next = n;
    l->end = l->end->next;
}

//sorts
void heapsort(Edge *arr,int n){
    heapify(arr,n);
    
    for(int i = n-1;i > 0;--i){
        swap(arr + 0,arr + i);
        siftdown(arr,i,0);
    }
}


void heapify(Edge *arr,int n){
    for(int i = n-1;i >= 0;--i) siftdown(arr,n,i);
}


void siftdown(Edge *arr,int n,int index){
    int current = index;

    while(current <= n/2 - 1 && current >= 0){
        int left = 2*current + 1;
        int right = 2*current + 2;
        int child = left;


        if(right < n) child = (arr[left].weight >= arr[right].weight) ? left : right;


        if(arr[current].weight >= arr[child].weight) return;
        
        swap(arr + current,arr + child); //else
        current = child;
    }
} 


void swap(Edge *a, Edge *b){
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

