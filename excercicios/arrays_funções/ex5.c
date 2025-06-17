#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  

bool simetrica(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] != mat[j][i]) {
                return false;  
            }
        }
    }
    return true;  
}

int main() {
    system("clear");
    int mat[3][3] = {
        {1, 4, 5},
        {6, 2, 6},
        {5, 6, 3}
    };

    if (simetrica(mat)) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    return 0;
}