#include "mst.h"
#include <stdio.h>

int main() {
    
    const int num_v = 5;
    const int num_e = 7;

    Edge edges[] = {{0, 1, 4},{0, 2, 3},{1, 2, 1},{1, 3, 2},{2, 3, 4},{2, 4, 5},{3, 4, 2}};
    printf("%d",get_mst_total_weight(edges,num_v,num_e));
    return 0;
}