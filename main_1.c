#include "mst.h"
#include <stdio.h>

int main() {
    
    const int num_v = 5;
    const int num_e = 7;

    Edge edges[] = {{0, 1, 2},{0, 3, 6},{1, 2, 3},{1, 3, 8},{1, 4, 5},{2, 4, 7},{3, 4, 9}};
    printf("%d",get_mst_total_weight(edges,num_v,num_e));
    return 0;
}