/*Crie uma função que recebe uma string como parâmetro e escreve ela ao contrário.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nm 20
void invert(char str[nm])
{
    int tamanho = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = tamanho - 1; i < j; i++, j--)
    {
        //!bubble sort
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    system("clear");
    char nome[nm];
    invert(fgets(nome, nm, stdin));
    printf("String invertida: %s\n", nome);
}