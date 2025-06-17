/*Crie uma função que recebe uma string como parâmetro e converte todos seus caracteres para maiúsculo. https://www.w3schools.com/c/c_ref_ctype.php*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define mx 20
void convert(char str[mx])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int main()
{
    system("clear");
    char nome[mx];
    fgets(nome, mx, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    convert(nome);
    printf("%s\n", nome);
}