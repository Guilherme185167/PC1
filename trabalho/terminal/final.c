#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#define tit 30

void livros();

void menu_livro()
{
    int lv;
    while (lv != 999)
    {
        system("clear");
        printf("\t\t   [999 p/sair] Digite o codigo do livro: ");
        scanf("%d", &lv);
        switch (lv)
        {
        case 31:
            int gab1[10] = {1, 2, 4, 1, 1, 4, 1, 3, 4, 1};
            livros(gab1, 0);
            break;
        case 32:
            int gab2[10] = {3, 4, 3, 4, 3, 1, 3, 1, 2, 4};
            livros(gab2, 1);
            break;
        case 999:

            printf("\t\t\t\t\033[35mSaindo");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                usleep(500000);
            }
            system("clear");
            printf("\033[m");
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        default:
            printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
    }
}

// void menu_matematica();
void livros(int gabarito[10], int a)
{
    int mv = 0, que = 0, resp[10], cer = 0, err = 0, form[10];
    char nav;
    char *cores[] = {
        "\033[31m", // Vermelho
        "\033[32m", // Verde
        "\033[33m", // Amarelo
        "\033[34m"  // Azul
    };
    char *livros[] = {
        "Hardware",
        "Software"};

    printf("\n\t\tUtilize o livro \033[35m%s\033[m para visualizar as questoes!\n", livros[a]);
    sleep(3);

    while (1)
    {
        system("clear");
        printf("\t\033[1;33mQuestão %d [a/d para mover q para sair, espaço para confirmar]\033[m\n\n", que + 1);
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\t\a|| %s\u2588\u2588\033[m ||\t", cores[i]); // destaque reverso
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
        else if (nav == ' ')
        {
            resp[que] = mv + 1;
            que += 1;
        }
        else if (nav == 'q')
        {
            return;
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

    printf("\nAperte qualquer tecla para continuar......");
    getchar();
    getchar();
}

void lista(){
system("clear");
            printf("\033[33m999 - SAIR\n998 - LISTA DE COMANDOS\nq - SAIR DA ATIVIDADE\na - MOVER PARA ESQUERDA\nd - MOVER PARA DIREITA\nSpace - SELECIONAR OPÇÂO\nEnter - CONFIRMAR OPÇÂO\n1 - MENU DE LIVROS\n2 - MENU DE MATEMATICA\n31 - LIVRO HARDWARE\n32 - LIVRO SOFTWARE\n\033[m");
            getchar();
            printf("\nTecle enter para continuar...");
            getchar();
            system("clear");
}
void menu_principal()
{
    char mensagem[] = "\t\t\tBEM VINDO AO PENSE MAIS OU MENOS";
    int n = strlen(mensagem), atv;
    // mensagem de boas vindas
    for (int i = 0; i < n; i++)
    {
        printf("%c", mensagem[i]);
        fflush(stdout);
        usleep(20000);
    }
    system("clear");
    for (int i = 0; i < 7; i++)
    {
        system("clear");
        printf("\033[7;3%dm%s\033[m", i, mensagem);
        fflush(stdout);
        usleep(10000);
    }
    sleep(1);
    system("clear");
    while (1)
    {
        printf("\t\t\t    [999 Sair, 998 Codigos]\n\t\t\tDigite um codigo de atividade: \033[7;31m");
        scanf("%d", &atv);
        printf("\033[m");
        if (atv == 999)
        {
            printf("\033[m");
            printf("\t\t\t\t\033[35mSaindo");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                usleep(500000);
            }
            system("clear");
            printf("\033[m");
            printf("\033[32m\n\t\t\t\tVOLTE SEMPRE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
        switch (atv)
        {
        case 1:
            menu_livro();
            break;
        case 2:
            /* code */
            break;
        case 998:
            lista();
            break;
        default:
            printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
    }
}

int main()
{
    system("clear");
    menu_principal();
}