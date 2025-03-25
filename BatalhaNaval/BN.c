#include <stdio.h>

#define TAM 10
#define NAVIO 3

// Declaração  das funções
void inicializarTabuleiro(int tabuleiro[TAM][TAM]);
void imprimirTabuleiro(int tabuleiro[TAM][TAM]);
int validarPosicao(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, int direcao);
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, int direcao);

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int navios[4][3] = { {2, 2, 0}, {5, 1, 1}, {0, 0, 2}, {3, 9, 3} };

    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int orientacao = navios[i][2];

        if (validarPosicao(tabuleiro, linha, coluna, 3, orientacao)) {
            posicionarNavio(tabuleiro, linha, coluna, 3, orientacao);
        }
    }

    imprimirTabuleiro(tabuleiro);
    return 0;
}

// Função Iniciar tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// FUnção imprimir tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int j = 0; j < TAM; j++) 
        printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int validarPosicao(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int x = linha + (direcao == 1 ? i : 0);
        int y = coluna + (direcao == 0 ? i : 0);

        if (x >= TAM || y >= TAM || tabuleiro[x][y] != 0) return 0;
    }
    return 1;
}

// Função posicionar navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int x = linha + (direcao == 1 ? i : 0);
        int y = coluna + (direcao == 0 ? i : 0);
        tabuleiro[x][y] = NAVIO;
    }
}
