#include <stdio.h>
#include <stdlib.h>

#define tit 30
void cabeca()
{

    system("clear");
    for (int i = 0; i < tit; i++)
    {
        printf("+");
    }
    puts("");
    printf("|\033[33m BEM VINDO(A) AO PENSE BEM! \033[m|\n");

    for (int i = 0; i < tit; i++)
    {
        printf("+");
    }
    puts("");
}
void livros()
{
    printf("\033[7;31mESCOLHA UM LIVRO:\033[m\n\n\033[1;32mAtividades Programadas Nº 01 \033[m\n\033[1;34mAtividades Programadas Nº 02\033[m\n::");
}

void livro1()
{
    
    char que[10][20] = {
        "1-LEITE",
        "2-GELO",
        "3-MANTEIGA",
        "4-OVOS",
        "5-QUEIJO",
        "6-SORVETE",
        "7-BALAS",
        "8-JARRA",
        "9-GATO",
        "10-SUCO"
    };
    for (int i = 0; i < 10; i++)
    {
        printf("%s ", que[i]);
    }
    puts("");
}

void ler()
{
}
int main()
{
    livro1();
    cabeca();
    livros();
}