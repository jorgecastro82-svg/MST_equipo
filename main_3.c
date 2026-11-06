#include "mst.h"
#include <stdio.h>

int main() {
    
    const int num_v = 7;
    const int num_e = 11;

    Edge edges[] = {{0, 1, 7},{0, 3, 5},{1, 2, 8},{1, 3, 9},{1, 4, 7},{2, 4, 5},{3, 4, 15},{3, 5, 6},{4, 5, 8},{4, 6, 9},{5, 6, 11}};
    printf("%d",get_mst_total_weight(edges,num_v,num_e));
    return 0;
}