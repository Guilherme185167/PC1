/*Escreva uma função que imprima uma linha específica de uma matriz*/

#include <stdio.h>
#include <stdlib.h>

void imp(int mat[][3], int tam)
{
    for(int i = 0; i < 3; i++){
        if(tam == i){
            for(int j = 0; j < 3; j++){
                printf("%d ", mat[tam][j]);
            }
        }
    }
}


int main()
{
    system("clear");
    int mat[3][3], k = 1, n;
    for (int i = 0; i < 3; i++)
    {
        k += 10;
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = k;
            k++;
        }
    }
    scanf("%d", &n);
    system("clear");
    imp(mat, n);
    puts("");
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", mat[i][j] );
    //     }
    //     puts("");
    // }
}