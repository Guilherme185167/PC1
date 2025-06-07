#include <stdio.h>

int main(){
    int vetor[5] = {5,2,3,8,12}, aux;

    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }
    puts("");
}