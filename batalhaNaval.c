#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro - Tabuleiro Completo e Navios Diagonais

#define tamanhoTabuleiro 10
#define tamanhoNavio 3

int main()
{
    // ================================
    // Tabuleiro
    // ================================
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    for (int i = 0; i < tamanhoTabuleiro; i++)
    {
        for (int j = 0; j < tamanhoTabuleiro; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // ================================
    // Coordenadas dos navios
    // ================================

    // Horizontal
    int linhaH = 7, colunaH = 2;

    // Vertical
    int linhaV = 5, colunaV = 6;

    // Diagonal ↘
    int linhaD1 = 2, colunaD1 = 1;

    // Diagonal ↙
    int linhaD2 = 0, colunaD2 = 8;

    // ================================
    // NAVIO HORIZONTAL
    // ================================
    for (int i = 0; i < tamanhoNavio; i++)
    {
        int linha = linhaH;
        int coluna = colunaH + i;

        // valida limite + sobreposição
        if (linha < 0 || linha >= tamanhoTabuleiro ||
            coluna < 0 || coluna >= tamanhoTabuleiro ||
            tabuleiro[linha][coluna] != 0)
        {
            printf("Erro: navio horizontal fora do tabuleiro ou sobreposto\n");
            return 1;
        }
    }

    // posiciona
    for (int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // ================================
    // NAVIO VERTICAL
    // ================================
    for (int i = 0; i < tamanhoNavio; i++)
    {
        int linha = linhaV + i;
        int coluna = colunaV;

        if (linha < 0 || linha >= tamanhoTabuleiro ||
            coluna < 0 || coluna >= tamanhoTabuleiro ||
            tabuleiro[linha][coluna] != 0)
        {
            printf("Erro: navio vertical fora do tabuleiro ou sobreposto\n");
            return 1;
        }
    }

    for (int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // ================================
    // NAVIO DIAGONAL ↘
    // ================================
    for (int i = 0; i < tamanhoNavio; i++)
    {
        int linha = linhaD1 + i;
        int coluna = colunaD1 + i;

        if (linha < 0 || linha >= tamanhoTabuleiro ||
            coluna < 0 || coluna >= tamanhoTabuleiro ||
            tabuleiro[linha][coluna] != 0)
        {
            printf("Erro: navio diagonal principal fora do tabuleiro ou sobreposto\n");
            return 1;
        }
    }

    for (int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // ================================
    //  NAVIO DIAGONAL ↙
    // ================================
    for (int i = 0; i < tamanhoNavio; i++)
    {
        int linha = linhaD2 + i;
        int coluna = colunaD2 - i;

        if (linha < 0 || linha >= tamanhoTabuleiro ||
            coluna < 0 || coluna >= tamanhoTabuleiro ||
            tabuleiro[linha][coluna] != 0)
        {
            printf("Erro: navio diagonal secundária fora do tabuleiro ou sobreposto\n");
            return 1;
        }
    }

    for (int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // ================================
    // Exibir tabuleiro
    // ================================

    printf("== TABULEIRO BATALHA NAVAL ==\n   ");

    // Letras das colunas
    for (int j = 0; j < tamanhoTabuleiro; j++)
    {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Linhas + conteúdo
    for (int i = 0; i < tamanhoTabuleiro; i++)
    {
        printf("%2d ", i + 1);

        for (int j = 0; j < tamanhoTabuleiro; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}