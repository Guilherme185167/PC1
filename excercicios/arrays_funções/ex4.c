#include <stdio.h>
#include <stdlib.h>
#define MAX_A 50

int busca(int arr[], int n) {
    for (int i = 0; i < MAX_A; i += 2) {  
        if (arr[i] == n) {
            return i;  
        }
        if (i + 1 < MAX_A && arr[i + 1] == n) {  
            return i + 1; 
        }
    }
    return -1;
}

int main() {
    int n, result;
    int arr[MAX_A];

    for (int i = 0; i < MAX_A; i++) {
        arr[i] = rand() % 100; 
    }

    printf("Digite um número para buscar: ");
    scanf("%d", &n);

    result = busca(arr, n); 

    if (result == -1) {
        printf("%d não está no array.\n", n);
    } else {
        printf("%d está na posição %d.\n", n, result);
    }

    return 0;
}