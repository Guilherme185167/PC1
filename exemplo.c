#include <ncurses.h>

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    // Cores
    start_color();
    use_default_colors();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);    // selecionado
    init_pair(2, COLOR_BLACK, COLOR_WHITE);   // não selecionado

    // Menu
    char *opcoes[] = {"Cadastrar aluno", "Buscar aluno", "Listar alunos", "Sair"};
    int total_opcoes = sizeof(opcoes) / sizeof(char*);
    int selecionado = 0, tecla;

    // Janela personalizada
    WINDOW *menuwin = newwin(10, 40, 4, 10);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, TRUE); // ativa setas para essa janela

    while (1) {
        for (int i = 0; i < total_opcoes; i++) {
            if (i == selecionado) {
                wattron(menuwin, COLOR_PAIR(1));
                mvwprintw(menuwin, i + 1, 2, "%s", opcoes[i]);
                wattroff(menuwin, COLOR_PAIR(1));
            } else {
                wattron(menuwin, COLOR_PAIR(2));
                mvwprintw(menuwin, i + 1, 2, "%s", opcoes[i]);
                wattroff(menuwin, COLOR_PAIR(2));
            }
        }

        tecla = wgetch(menuwin);
        if (tecla == KEY_UP) selecionado = (selecionado - 1 + total_opcoes) % total_opcoes;
        else if (tecla == KEY_DOWN) selecionado = (selecionado + 1) % total_opcoes;
        else if (tecla == 10) break;
    }

    endwin();
    printf("Você escolheu: %s\n", opcoes[selecionado]);
    return 0;
}
