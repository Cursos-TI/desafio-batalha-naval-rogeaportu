#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int TAMANHO = 10, NAVIO = 3; // Tamanho do tabuleiro e Navio
    int tabuleiro[10][10]; // matriz 10 x 10 que representa o tabuleiro
    int i, j, valido; // contadores dos loops e verificação de posiçao valida
    // Coordenadas de cada navio
    int linha1 = 2, coluna1 = 4; // Navio 1
    int linha2 = 5, coluna2 = 1; // Navio 2
    int linha3 = 0, coluna3 = 0; // Navio 3
    int linha4 = 5, coluna4 = 5; // Navio 4

    // Iniciando o tabuleiro com 0 em todas as posições(água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    // __________ NAVIO 1: Horizontal __________
    // Verifica sobreposicao, tamanho, limite
    if (coluna1 + NAVIO <= TAMANHO) {
        valido = 1;
        for (j = coluna1; j < coluna1 + NAVIO; j++) {
            if (tabuleiro[linha1][j] != 0) valido = 0;
        }
        if (valido) {
            for (j = coluna1; j < coluna1 + NAVIO; j++) {
                tabuleiro[linha1][j] = 3;
            }
        }
    }

    // __________ NAVIO 2: Vertical __________
    // Verifica sobreposicao, tamanho, limite
    if (linha2 + NAVIO <= TAMANHO) {
        valido = 1;
        for (i = linha2; i < linha2 + NAVIO; i++) {
            if (tabuleiro[i][coluna2] != 0) valido = 0;
        }
        if (valido) {
            for (i = linha2; i < linha2 + NAVIO; i++) {
                tabuleiro[i][coluna2] = 3;
            }
        }
    }

    // __________ NAVIO 3: 1 Diagonal __________
    // Verifica sobreposicao, tamanho, limite
    if (linha3 + NAVIO <= TAMANHO && coluna3 + NAVIO <= TAMANHO) {
        valido = 1;
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha3 + i][coluna3 + i] != 0) valido = 0;
        }
        if (valido) {
            for (i = 0; i < NAVIO; i++) {
                tabuleiro[linha3 + i][coluna3 + i] = 3;
            }
        }
    }

    // __________ NAVIO 4: 2 Diagonal __________
    // Verifica sobreposicao, tamanho, limite

   if (linha4 + NAVIO <= TAMANHO && coluna4 + NAVIO <= TAMANHO) {
    valido = 1;
    for (i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha4 + i][coluna4 + i] != 0) valido = 0; // Verifica se está vazio
    }
    if (valido) {
        for (i = 0; i < NAVIO; i++) {
            tabuleiro[linha4 + i][coluna4 + i] = 3; // Posiciona o navio
        }
    }
}

  // Cone (forma de pirâmide para cima)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i <= 2 && j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro (losango centrado)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplicando Cone (valor 1)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int li = origemConeL + i - 2;
            int co = origemConeC + j - 2;
            if (li >= 0 && li < TAMANHO && co >= 0 && co < TAMANHO && cone[i][j] == 1 && tabuleiro[li][co] == 0) {
                tabuleiro[li][co] = 1;
            }
        }
    }

    // Aplicando Cruz (valor 5)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int li = origemCruzL + i - 2;
            int co = origemCruzC + j - 2;
            if (li >= 0 && li < TAMANHO && co >= 0 && co < TAMANHO && cruz[i][j] == 1 && tabuleiro[li][co] == 0) {
                tabuleiro[li][co] = 5;
            }
        }
    }

    // Aplicando Octaedro (valor 8)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int li = origemOctaedroL + i - 2;
            int co = origemOctaedroC + j - 2;
            if (li >= 0 && li < TAMANHO && co >= 0 && co < TAMANHO && octaedro[i][j] == 1 && tabuleiro[li][co] == 0) {
                tabuleiro[li][co] = 8;
            }
        }
    }

// __________ Impressão do Tabuleiro __________
    printf("     A B C D E F G H I J\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("%2d |", i + 1);
        for (j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}
