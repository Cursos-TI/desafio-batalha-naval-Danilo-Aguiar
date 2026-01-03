#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ============================
    // Coordenadas iniciais dos navios
    // ============================

    // Navio horizontal
    int linhaH = 3;      // Linha 3
    char colunaH = 'B';  // Coluna B

    // Navio vertical
    int linhaV = 6;      // Linha 6
    char colunaV = 'H';  // Coluna H

    // Navio diagonal ↘
    int linhaD1 = 1;     // Linha 1
    char colunaD1 = 'A'; // Coluna A

    // Navio diagonal ↙
    int linhaD2 = 4;     // Linha 4
    char colunaD2 = 'J'; // Coluna J

    // Conversão para índices do array
    int linhaHIdx = linhaH - 1;
    int colunaHIdx = colunaH - 'A';

    int linhaVIdx = linhaV - 1;
    int colunaVIdx = colunaV - 'A';

    int linhaD1Idx = linhaD1 - 1;
    int colunaD1Idx = colunaD1 - 'A';

    int linhaD2Idx = linhaD2 - 1;
    int colunaD2Idx = colunaD2 - 'A';

    // ============================
    // Navio horizontal
    // ============================
    if (colunaHIdx + TAM_NAVIO <= TAM_TABULEIRO) {
        int livre = 1;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaHIdx][colunaHIdx + i] != AGUA) {
                livre = 0;
                break;
            }
        }

        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaHIdx][colunaHIdx + i] = NAVIO;
            }
        }
    }

    // ============================
    // Navio vertical
    // ============================
    if (linhaVIdx + TAM_NAVIO <= TAM_TABULEIRO) {
        int livre = 1;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaVIdx + i][colunaVIdx] != AGUA) {
                livre = 0;
                break;
            }
        }

        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaVIdx + i][colunaVIdx] = NAVIO;
            }
        }
    }

    // ============================
    // Navio diagonal ↘
    // ============================
    if (linhaD1Idx + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaD1Idx + TAM_NAVIO <= TAM_TABULEIRO) {

        int livre = 1;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1Idx + i][colunaD1Idx + i] != AGUA) {
                livre = 0;
                break;
            }
        }

        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1Idx + i][colunaD1Idx + i] = NAVIO;
            }
        }
    }

    // ============================
    // Navio diagonal ↙
    // ============================
    if (linhaD2Idx + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaD2Idx - (TAM_NAVIO - 1) >= 0) {

        int livre = 1;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2Idx + i][colunaD2Idx - i] != AGUA) {
                livre = 0;
                break;
            }
        }

        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2Idx + i][colunaD2Idx - i] = NAVIO;
            }
        }
    }

    // ============================
    // Exibição do tabuleiro com coordenadas
    // ============================
    printf("    ");
    for (char c = 'A'; c < 'A' + TAM_TABULEIRO; c++) {
        printf("%c ", c);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

