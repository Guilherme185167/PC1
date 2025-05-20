#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ncurses.h>
#include <unistd.h>
#include <termios.h>

#define tit 30
struct termios original;

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

void livro1()
{
    int mv = 0, que = 0, resp[10], cer = 0, err = 0, form[10];
    char nav;
    char *cores[] = {
        "\033[31m", // Vermelho
        "\033[32m", // Verde
        "\033[33m", // Amarelo
        "\033[34m"  // Azul
    };
    int gab[10] = {1, 1, 4, 3, 2, 4, 1, 1, 4, 3};

    puts("Utilize o livro para visualizar as questoes!\n");
    while (1)
    {
        system("clear");
        printf("\033[1;33mNa cozinha: Questão %d [a/d para mover]\033[m\n\n", que + 1);
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf(" > \033[%s\u2588\u2588\033[m < ", cores[i]); // destaque reverso
            else
                printf(" \033[%s\u2588\u2588\033[m ", cores[i]); // normal
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
        if (que == 10)
        {
            break;
        }
    }

    // verificação das respostas
    for (int j = 0; j < 10; j++)
    {
        if (resp[j] == gab[j])
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
        printf("\033[32m%d \033[m", gab[j]);
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
        "Atividades Programadas Nº 01",
        "Atividades Programadas Nº 02",
        "Atividades Programadas Nº 03",
        "Sair"};

    while (1)
    {
        system("clear");
        puts("\033[1;33mEscolha um livro: [use w/s para navegar enter para confirmar]\033[m\n");
        for (int i = 0; i < 3; i++)
        {
            if (i == mv)
                printf("\033[7;37m%s\033[m\n", op[i]);
            else
                printf("%s\n", op[i]);
        }

        nav = getchar();
        if (nav == 'w')
        {
            mv--;
            if (mv < 0)
                mv = 2;
        }
        else if (nav == 's')
        {
            mv++;
            if (mv > 2)
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
        livro1();
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;

    default:
        break;
    }
}

int main()
{
    desativarModoCanonico(); // Ativa modo de leitura direta do teclado
    menu_livro();            // Executa o menu
    restaurarModoCanonico(); // Restaura terminal ao final
    return 0;
}