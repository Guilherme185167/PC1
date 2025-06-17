#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mudar(char str[20])
{
    int tam = strlen(str);
    char op;
    int pos = 0;       
    char novo[20] = {0}; 


    strcpy(novo, str);

    while (1)
    {
        system("clear");

        for (int i = 0; i < tam; i++)
        {
            if (i == pos)
                printf("[%c]", novo[i]); 
            else
                printf(" %c ", novo[i]);
        }

        printf("\nComandos: (a) esquerda, (d) direita, ($) substituir, (q) sair\n");

        op = getchar();
        getchar(); 

        if (op == 'q')
            break;
        else if (op == 'd' && pos < tam - 1)
            pos++;
        else if (op == 'a' && pos > 0)
            pos--;
        else if (isdigit(op) || op == '$')
        {
            novo[pos] = op;
        }
    }

    printf("\nResultado final: %s\n", novo);
}

int main()
{
    system("clear");
    char nome[20];
    printf("Digite uma palavra (max 19 letras): ");
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    mudar(nome);
}