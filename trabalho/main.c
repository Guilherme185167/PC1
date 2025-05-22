#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ncurses.h>
#include <unistd.h>
#include <termios.h>

#define tit 30
struct termios original;

void menu_principal();
void menu_livro();

char *nome_livro[] = {
    "Hardware"};

void desativarModoCanonico()
{
    struct termios novo;
    tcgetattr(STDIN_FILENO, &original);
    novo = original;
    novo.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &novo);
}

void restaurarModoCanonico()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
}

void livros(int n, int gabarito[10])
{
    int mv = 0, que = 0, resp[10], cer = 0, err = 0, form[10];
    char nav;
    char *cores[] = {
        "\033[31m", // Vermelho
        "\033[32m", // Verde
        "\033[33m", // Amarelo
        "\033[34m"  // Azul
    };

    puts("Utilize o livro para visualizar as questoes!\n");
    while (1)
    {
        system("clear");
        printf("\t\t\033[1;33m%s: Questão %d [a/d para mover q para sair]\033[m\n\n", nome_livro[n], que + 1);
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\t\a|| [%s\u2588\u2588\033[m ||\t", cores[i]); // destaque reverso
            else
                printf(" \t\a\033[%s\u2588\u2588\033[m\t ", cores[i]); // normal
        }
        puts("");

        nav = getchar();
        if (nav == 'a')
        {
            mv--;
            if (mv < 0)
                mv = 3;
        }
        else if (nav == 'd')
        {
            mv++;
            if (mv > 3)
                mv = 0;
        }
        else if (nav == '\n')
        {
            resp[que] = mv + 1;
            que += 1;
        }
        else if (nav == 'q')
        {
            menu_livro();
        }
        if (que == 10)
        {
            break;
        }
    }
    // verificação das respostas
    for (int j = 0; j < 10; j++)
    {
        if (resp[j] == gabarito[j])
        {
            cer += 1;
            form[j] = 1;
        }
        else
        {
            err += 1;
            form[j] = 0;
        }
    }
    // imprimir respostas
    for (int j = 0; j < 10; j++)
    {
        if (form[j] == 1)
            printf("\033[32m%d \033[m", resp[j]);
        else
            printf("\033[31m%d \033[m", resp[j]);
    }
    puts("");
    // imprimir gabarito
    for (int j = 0; j < 10; j++)
    {
        printf("\033[32m%d \033[m", gabarito[j]);
    }
    puts("\n");
    printf("\033[32mAcertos: %d \033[31mErros %d\n\033[m", cer, err);
}

void menu_livro()
{
    int mv = 0;
    char nav;
    // opções do menu
    char *op[] = {
        "\aAtividades Programadas Nº 01",
        "\aAtividades Programadas Nº 02",
        "\aAtividades Programadas Nº 03",
        "\a::Sair"};

    while (1)
    {
        system("clear");
        puts("\033\t[1;33mEscolha um livro: [use w/s para navegar enter para confirmar]\033[m\n");
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\033[1;36;47m%s\033[m\n", op[i]);
            else
                printf("%s\n", op[i]);
        }
        nav = getchar();
        if (nav == 'w')
        {
            mv--;
            if (mv < 0)
                mv = 3;
        }
        else if (nav == 's')
        {
            mv++;
            if (mv > 3)
                mv = 0;
        }
        else if (nav == '\n')
        {
            break;
        }
    }
    switch (mv)
    {
    case 0:
    {

        int gab1[10] = {1, 1, 4, 3, 2, 4, 1, 1, 4, 3};
        livros(0, gab1);
        break;
    }
    case 1:
    {
        int gab2[10] = {2, 1, 4, 3, 2, 4, 1, 1, 4, 3};
        livros(0, gab2);
        break;
    }
    case 2:
    {
        int gab3[10] = {3, 1, 4, 3, 2, 4, 1, 1, 4, 3};
        livros(0, gab3);
        break;
    }
    case 3:
        menu_principal();
        break;

    default:
        break;
    }
}
void menu_principal()
{
    int mv = 0;
    char nav;
    // opções do menu
    char *op[] = {
        "\aEquações Matematicas",
        "\aLivros",
        "\aGabritos",
        "\a::Sair"};

    while (1)
    {
        system("clear");
        puts("\033\t[1;33mEscolha um desafio: [use w/s para navegar enter para confirmar]\033[m\n");
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\033[1;36;47m%s\033[m\n", op[i]);
            else
                printf("%s\n", op[i]);
        }
        nav = getchar();
        if (nav == 'w')
        {
            mv--;
            if (mv < 0)
                mv = 3;
        }
        else if (nav == 's')
        {
            mv++;
            if (mv > 3)
                mv = 0;
        }
        else if (nav == '\n')
        {
            break;
        }
    }
    switch (mv)
    {
    case 0:
        /* code */
        break;
    case 1:
        menu_livro();
        break;
    case 2:
        /* code */
        break;
    case 3:
        break;

    default:
        break;
    }
}

int main()
{
    desativarModoCanonico();
    menu_principal();
    restaurarModoCanonico();
    return 0;
}