#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <windows.h>  // Substitui <unistd.h> e <termios.h>
#define tit 30

char hora_atual[50];
char nome[30];

void pegar_hora() {
    time_t agora;
    time(&agora);
    strftime(hora_atual, 50, "[%d/%m/%Y %H:%M:%S]", localtime(&agora));
}

void livros(int gabarito[10], int a);
void lista();
void placar();
void soma();
void sub();
void mult();
void divis();
void equee();
void menu_matematica();
void menu_livro();
void menu_principal();

void placar() {
    FILE *arquivo = fopen("pontos.txt", "r"); 
    if (arquivo == NULL) {
        printf("\033[31mErro ao abrir o arquivo!\033[m\n");
        return;
    }

    system("cls");
    printf("\n\t\t\033[34m=== REGISTRO DE PONTUAÇÕES ===\033[m\n\n");

    char linha[200]; 
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo); 
    printf("\n\nPressione ENTER para voltar...");
    getchar(); 
    getchar(); 
    system("cls");
}

void soma() {
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    system("cls");
    printf("\t\t\t   BEM VINDO AO MODO SOMA\n");
    Sleep(1000);
    system("cls");
    printf("Digite 9999 para voltar\n");
    Sleep(1000);
    system("cls");

    while (1) {
        if (v > 10) {
            lim = 50;
            if (v > 25) lim = 120;
        }

        n1 = rand() % lim;
        n2 = rand() % lim;
        res = n1 + n2;

        system("cls");
        printf("Dificuldade: %d\nQuanto é %d + %d?\n>> ", v, n1, n2);
        scanf("%d", &esc);

        if (esc == 9999) {
            fprintf(arquivo, "Hora atual: %s Modo: Soma\nDificuldade: %d\nAcertos: %d\nErros: %d\n\n", hora_atual, v, v, f);
            printf("\t\t\t\t\033[35mVoltando");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(500);
            }
            system("cls");
            printf("\033[m");
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            Sleep(1000);
            system("cls");
            break;
        }

        if (esc == res) {
            v += 1;
            printf("Correto! %d\n", v);
        } else {
            printf("Errado! %d\n", res);
            f += 1;
        }
        Sleep(1000);
    }
    fclose(arquivo);
}

void sub() {
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    system("cls");
    printf("\t\t\t   BEM VINDO AO MODO SUBTRAÇÃO\n");
    Sleep(1000);
    system("cls");
    printf("Digite 9999 para voltar\n");
    Sleep(1000);
    system("cls");

    while (1) {
        if (v > 10) {
            lim = 50;
            if (v > 25) lim = 120;
        }

        n1 = rand() % lim;
        n2 = rand() % lim;
        res = n1 - n2;

        system("cls");
        printf("Dificuldade: %d\nQuanto é %d - %d?\n>> ", v, n1, n2);
        scanf("%d", &esc);

        if (esc == 9999) {
            fprintf(arquivo, "Hora atual: %s Modo: Subtração\nDificuldade: %d\nAcertos: %d\nErros: %d\n\n", hora_atual, v, v, f);
            printf("\t\t\t\t\033[35mVoltando");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(500);
            }
            system("cls");
            printf("\033[m");
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            Sleep(1000);
            system("cls");
            break;
        }

        if (esc == res) {
            v += 1;
            printf("Correto! %d\n", v);
        } else {
            printf("Errado! %d\n", res);
            f += 1;
        }
        Sleep(1000);
    }
    fclose(arquivo);
}

void mult() {
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    system("cls");
    printf("\t\t\t   BEM VINDO AO MODO MULTIPLICAÇÃO\n");
    Sleep(1000);
    system("cls");
    printf("Digite 9999 para voltar\n");
    Sleep(1000);
    system("cls");

    while (1) {
        if (v > 10) {
            lim = 50;
            if (v > 25) lim = 120;
        }

        n1 = rand() % lim;
        n2 = rand() % lim;
        res = n1 * n2;

        system("cls");
        printf("Dificuldade: %d\nQuanto é %d * %d?\n>> ", v, n1, n2);
        scanf("%d", &esc);

        if (esc == 9999) {
            fprintf(arquivo, "Hora atual: %s Modo: Multiplicação\nDificuldade: %d\nAcertos: %d\nErros: %d\n\n", hora_atual, v, v, f);
            printf("\t\t\t\t\033[35mVoltando");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(500);
            }
            system("cls");
            printf("\033[m");
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            Sleep(1000);
            system("cls");
            break;
        }

        if (esc == res) {
            v += 1;
            printf("Correto! %d\n", v);
        } else {
            printf("Errado! %d\n", res);
            f += 1;
        }
        Sleep(1000);
    }
    fclose(arquivo);
}

void divis() {
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    system("cls");
    printf("\t\t\t   BEM VINDO AO MODO DIVISÃO\n");
    Sleep(1000);
    system("cls");
    printf("Digite 9999 para voltar\n");
    Sleep(1000);
    system("cls");

    while (1) {
        if (v > 10) {
            lim = 50;
            if (v > 25) lim = 120;
        }

        n1 = rand() % lim + 1;
        n2 = rand() % lim + 1;
        res = n1 / n2;

        system("cls");
        printf("Dificuldade: %d\nQuanto é %d / %d? (Divisão inteira)\n>> ", v, n1, n2);
        scanf("%d", &esc);

        if (esc == 9999) {
            fprintf(arquivo, "Hora atual: %s Modo: Divisão\nDificuldade: %d\nAcertos: %d\nErros: %d\n\n", hora_atual, v, v, f);
            printf("\t\t\t\t\033[35mVoltando");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(500);
            }
            system("cls");
            printf("\033[m");
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            Sleep(1000);
            system("cls");
            break;
        }

        if (esc == res) {
            v += 1;
            printf("Correto! %d\n", v);
        } else {
            printf("Errado! %d\n", res);
            f += 1;
        }
        Sleep(1000);
    }
    fclose(arquivo);
}

void equee() {
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    system("cls");
    printf("\t\t\t   BEM VINDO AO MODO EQUAÇÃO\n");
    Sleep(1000);
    system("cls");
    printf("Digite 9999 para voltar\n");
    Sleep(1000);
    system("cls");
    srand(time(NULL));
    int resposta_usuario, dificuldade = 0, min = 0, max = 10, v = 0, f = 0;

    while (1) {
        if (dificuldade > 5) {
            max = 50;
            min = 10;
            if (dificuldade > 13) {
                max = 100;
                min = 35;
                if (dificuldade > 25) {
                    max = 100;
                    min = 0;
                }
            }
        }

        system("cls");

        int qtd_numeros = rand() % 3 + 2;
        int numeros[qtd_numeros];
        char operadores[qtd_numeros - 1];

        for (int i = 0; i < qtd_numeros; i++) {
            numeros[i] = rand() % max + min;
        }

        char ops[] = {'+', '-', '*', '/'};
        for (int i = 0; i < qtd_numeros - 1; i++) {
            operadores[i] = ops[rand() % 4];
        }

        printf("Dificuldade: %d\nResolva: ", dificuldade);
        for (int i = 0; i < qtd_numeros; i++) {
            printf("%d", numeros[i]);
            if (i < qtd_numeros - 1) {
                printf(" %c ", operadores[i]);
            }
        }
        printf("\n");

        int resultado = numeros[0];
        for (int i = 1; i < qtd_numeros; i++) {
            if (operadores[i - 1] == '*') {
                resultado *= numeros[i];
            } else if (operadores[i - 1] == '/') {
                if (numeros[i] == 0) numeros[i] = 1;
                resultado /= numeros[i];
            }
        }
        for (int i = 1; i < qtd_numeros; i++) {
            if (operadores[i - 1] == '+') {
                resultado += numeros[i];
            } else if (operadores[i - 1] == '-') {
                resultado -= numeros[i];
            }
        }

        printf("Sua resposta: ");
        scanf("%d", &resposta_usuario);

        if (resposta_usuario == 9999) {
            fprintf(arquivo, "Hora atual: %s Modo: Equação\nDificuldade: %d\nAcertos: %d\nErros: %d\n\n", hora_atual, dificuldade, v, f);
            printf("\t\t\t\t\033[35mVoltando");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(500);
            }
            system("cls");
            printf("\033[m");
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            Sleep(1000);
            system("cls");
            break;
        } else if (resposta_usuario == resultado) {
            printf("Correto!\n");
            dificuldade += 1;
            v += 1;
        } else {
            printf("Errado! Era: %d\n", resultado);
            f += 1;
        }
        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();
    }
    fclose(arquivo);
}

void menu_matematica() {
    int modo;
    while (1) {
        system("cls");
        printf("\t\t\t   BEM VINDO AO MODO MATEMÁTICA\n");
        Sleep(1000);
        system("cls");
        printf("\t\t\t    \033[33m[999 Sair, 998 Ajuda]\033[m\n\t\t        Digite um codigo de atividade: ");
        scanf("%d", &modo);
        switch (modo) {
            case 41: soma(); break;
            case 42: sub(); break;
            case 43: mult(); break;
            case 44: divis(); break;
            case 45: equee(); break;
            case 998: lista(); break;
            case 999:
                printf("\t\t\t\t\033[35mSaindo");
                for (int i = 0; i < 3; i++) {
                    printf(".");
                    fflush(stdout);
                    Sleep(500);
                }
                system("cls");
                printf("\033[m");
                printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
                Sleep(1000);
                system("cls");
                return;
            default:
                printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
                Sleep(1000);
                system("cls");
                break;
        }
    }
}

void menu_livro() {
    int lv;
    while (1) {
        system("cls");
        printf("\t\t\t   BEM VINDO AO MODO LIVRO\n");
        Sleep(1000);
        system("cls");
        printf("\t\t\t   \033[33m[999 p/ voltar, 998 ajuda]\033[m\n\t\t\t   Digite o codigo do livro: ");
        scanf("%d", &lv);
        switch (lv) {
            case 31: {
                int gab1[10] = {1, 2, 4, 1, 1, 4, 1, 3, 4, 1};
                livros(gab1, 0);
                break;
            }
            case 32: {
                int gab2[10] = {3, 4, 3, 4, 3, 1, 3, 1, 2, 4};
                livros(gab2, 1);
                break;
            }
            case 998: lista(); break;
            case 999:
                printf("\t\t\t\t\033[35mVoltando");
                for (int i = 0; i < 3; i++) {
                    printf(".");
                    fflush(stdout);
                    Sleep(70);
                }
                system("cls");
                printf("\033[m");
                printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
                Sleep(1000);
                system("cls");
                return;
            default:
                printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
                Sleep(1000);
                system("cls");
                break;
        }
    }
}

void livros(int gabarito[10], int a) {
    int mv = 0, que = 0, resp[10], cer = 0, err = 0, form[10];
    char nav;
    char *cores[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m"};
    char *livros[] = {"Hardware", "Software"};

    printf("\n\t\t   Utilize o livro \033[35m%s\033[m para visualizar as questoes!\n", livros[a]);
    Sleep(3000);

    while (1) {
        system("cls");
        printf("\t\033[1;33mQuestão %d [a/d para mover q para sair, espaço para confirmar]\033[m\n\n", que + 1);
        for (int i = 0; i < 4; i++) {
            if (i == mv) printf("\t\a|| %s\u2588\u2588\033[m ||\t", cores[i]);
            else printf(" \t\a\033[%s\u2588\u2588\033[m\t ", cores[i]);
        }
        puts("");

        nav = getchar();
        if (nav == 'a') {
            mv--;
            if (mv < 0) mv = 3;
        } else if (nav == 'd') {
            mv++;
            if (mv > 3) mv = 0;
        } else if (nav == ' ') {
            resp[que] = mv + 1;
            que += 1;
        } else if (nav == 'q') {
            return;
        }
        if (que == 10) break;
    }

    for (int j = 0; j < 10; j++) {
        if (resp[j] == gabarito[j]) {
            cer += 1;
            form[j] = 1;
        } else {
            err += 1;
            form[j] = 0;
        }
    }

    for (int j = 0; j < 10; j++) {
        if (form[j] == 1) printf("\033[32m%d \033[m", resp[j]);
        else printf("\033[31m%d \033[m", resp[j]);
    }
    puts("");

    for (int j = 0; j < 10; j++) {
        printf("\033[32m%d \033[m", gabarito[j]);
    }
    puts("\n");
    printf("\033[32mAcertos: %d \033[31mErros %d\n\033[m", cer, err);

    printf("\nAperte qualquer tecla para continuar......");
    getchar();
    getchar();
}

void lista() {
    system("cls");
    printf("\033[35mComandos principais\033[m\n\033[33m999 - SAIR\n998 - LISTA DE COMANDOS\n997 - PONTUAÇÃO\033[m\n\n\033[35mNavegação\033[m\n\033[33mq - SAIR DA ATIVIDADE(Livros)\n9999 - SAIR DA ATIVIDADE(Matematica)\na - MOVER PARA ESQUERDA\nd - MOVER PARA DIREITA\nSpace - SELECIONAR OPÇÂO\nEnter - CONFIRMAR OPÇÂO\033[m\n\n\033[35mMenus\033[m\n\033[33m1 - MENU DE LIVROS\n2 - MENU DE MATEMATICA\033[m\n\n\033[35mLivros\n\033[33m31 - LIVRO HARDWARE\n32 - LIVRO SOFTWARE\033[m\n\n\033[35mModos matemáticos\033[m\n\033[33m41 - SOMA\n42 - SUBTRAÇÃO\n43 - MUTIPLICAÇÃO\n44 - DIVISÃO\n45 - EQUAÇÕES\033[m");
    getchar();
    printf("\nTecle enter para continuar...");
    getchar();
    system("cls");
}

void menu_principal() {
    char mensagem[] = "\t\t\tBEM VINDO AO PENSE MAIS OU MENOS";
    int n = strlen(mensagem), atv;
    for (int i = 0; i < n; i++) {
        printf("%c", mensagem[i]);
        fflush(stdout);
        Sleep(40);
    }
    system("cls");
    for (int i = 0; i < 7; i++) {
        system("cls");
        printf("\033[7;3%dm%s\033[m", i, mensagem);
        fflush(stdout);
        Sleep(300);
    }
    printf("\n\t\t\t\t    \033[7;36m : %s\033[m", nome);
    Sleep(2000);
    system("cls");
    while (1) {
        printf("\t\t\t\033[33m[999 Sair, 998 Ajuda, 997 placar]\033[m\n\t\t        Digite um codigo de atividade: \033[7;31m");
        scanf("%d", &atv);
        printf("\033[m");
        if (atv == 999) {
            printf("\033[m");
            printf("\t\t\t\t\033[35mSaindo");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(500);
            }
            system("cls");
            printf("\033[m");
            printf("\033[32m\n\t\t\t\tVOLTE SEMPRE!\033[m\n");
            Sleep(1000);
            system("cls");
            break;
        }
        switch (atv) {
            case 1: menu_livro(); break;
            case 2: menu_matematica(); break;
            case 997: placar(); break;
            case 998: lista(); break;
            default:
                printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
                Sleep(1000);
                system("cls");
                break;
        }
    }
}

int main() {
    FILE *arquivo = fopen("pontos.txt", "a");
    system("cls");
    printf("NOME: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';  // Remove a quebra de linha do fgets
    fprintf(arquivo, "Nome: %s\n", nome);
    fclose(arquivo);
    system("cls");
    menu_principal();
    return 0;
}