#include <stdio.h>

#define COLUNA 10
#define LINHA 10
#define HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 3   
int main() {

    int tabuleiro[COLUNA][LINHA];
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    int centro = HAB / 2;

    // Inicializa tabuleiro
    for (int i = 0; i < COLUNA; i++)
        for (int j = 0; j < LINHA; j++)
            tabuleiro[i][j] = AGUA;

    // Navio exemplo
    tabuleiro[4][4] = NAVIO;
    tabuleiro[4][5] = NAVIO;
    tabuleiro[4][6] = NAVIO;

    // ================= CONE =================
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            cone[i][j] = 0;
            if (i < centro) continue;

            int alcance = i - centro;
            if (j < centro - alcance) continue;
            if (j > centro + alcance) continue;

            cone[i][j] = 3;
        }
    }

    // ================= CRUZ =================
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            cruz[i][j] = 0;
            if (i == centro) cruz[i][j] = 3;
            if (j == centro) cruz[i][j] = 3;
        }
    }

    // ================= OCTAEDRO =================
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int l = (i > centro) ? i - centro : centro - i;
            int c = (j > centro) ? j - centro : centro - j;

            octaedro[i][j] = 0;
            if (l + c <= centro)
                octaedro[i][j] = 3;
        }
    }

    // Origens
    int oConeL = 2, oConeC = 2;
    int oCruzL = 6, oCruzC = 2;
    int oOctL  = 6, oOctC  = 7;

    // Sobreposição das habilidades
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (cone[i][j] == 3) {
                int l = oConeL + i - centro;
                int c = oConeC + j - centro;

                if (l < 0) continue;
                if (l >= COLUNA) continue;
                if (c < 0) continue;
                if (c >= LINHA) continue;

                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }

            if (cruz[i][j] == 3) {
                int l = oCruzL + i - centro;
                int c = oCruzC + j - centro;

                if (l < 0) continue;
                if (l >= COLUNA) continue;
                if (c < 0) continue;
                if (c >= LINHA) continue;

                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }

            if (octaedro[i][j] == 3) {
                int l = oOctL + i - centro;
                int c = oOctC + j - centro;

                if (l < 0) continue;
                if (l >= COLUNA) continue;
                if (c < 0) continue;
                if (c >= LINHA) continue;

                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }

    // Exibição final
    printf("\n0 = Agua | 3 = Navio (inclui habilidade)\n\n");

    for (int i = 0; i < COLUNA; i++) {
        for (int j = 0; j < LINHA; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}


