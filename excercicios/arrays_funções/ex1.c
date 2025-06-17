/*Escreva uma função que calcule o produto interno entre dois arrays*/

#include <stdio.h>
#include <stdlib.h>
int res[5];
void PI(int a[],int b[])
{
    for (int i = 0; i < 5; i++)
    {
        res[i] += a[i] * b[i];
    }
}

int main()
{
    system("clear");
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    PI(a,b);
    for(int j = 0; j < 5; j++){
        printf("%d ", res[j]);
    }
    puts("");
}