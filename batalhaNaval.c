#include <stdio.h>

int main() {
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    // Declaração do tabuleiro
    int tabuleiro[10][10];

    // Inicialização do tabuleiro com água (0)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navios (vetores unidimensionais)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // Coordenadas iniciais (linha numérica, coluna letra)
    // Linha começa em 1 e coluna começa em 'A'
    int linhaH = 3;      // Linha 3
    char colunaH = 'B';  // Coluna B

    int linhaV = 6;      // Linha 6
    char colunaV = 'G';  // Coluna G

    // Conversão para índices do array (começam em 0)
    int linhaHIndex = linhaH - 1;
    int colunaHIndex = colunaH - 'A';

    int linhaVIndex = linhaV - 1;
    int colunaVIndex = colunaV - 'A';

    
    // Posicionamento do navio horizontal
   
    if (colunaHIndex + tamanhoNavio <= tamanhoTabuleiro) {
        int podePosicionar = 1;

        // Verifica sobreposição
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaHIndex][colunaHIndex + i] != 0) {
                podePosicionar = 0;
                break;
            }
        }

        // Posiciona o navio horizontal
        if (podePosicionar) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaHIndex][colunaHIndex + i] = navioHorizontal[i];
            }
        }
    }

    
    // Posicionamento do navio vertical
   
    if (linhaVIndex + tamanhoNavio <= tamanhoTabuleiro) {
        int podePosicionar = 1;

        // Verifica sobreposição
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVIndex + i][colunaVIndex] != 0) {
                podePosicionar = 0;
                break;
            }
        }

        // Posiciona o navio vertical
        if (podePosicionar) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVIndex + i][colunaVIndex] = navioVertical[i];
            }
        }
    }

    // ============================
    // Exibição do tabuleiro
    

    printf("    ");
    for (char c = 'A'; c < 'A' + tamanhoTabuleiro; c++) {
        printf("%c ", c);
    }
    printf("\n");

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
