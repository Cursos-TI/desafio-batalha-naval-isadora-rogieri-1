#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios

int main()
{

    // Tabuleiro
    int tabuleiro[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }

    // Navios
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 3; // horizontal
    int linhaV = 5, colunaV = 6; // vertical

    // Verificar limite horizontal
    if (colunaH + 3 > 10)
    {
        printf("Erro: Navio horizontal ultrapassa o limite!\n");
        return 1;
    }

    // Verificar limite vertical
    if (linhaV + 3 > 10)
    {
        printf("Erro: Navio vertical ultrapassa o limite!\n");
        return 1;
    }

    // Verificar sobreposição
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaH][colunaH + i] == 3)
        {
            printf("Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaV + i][colunaV] == 3)
        {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }

    // Posiciona Navio horizontal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
    }

    // Posiciona Navio vertical
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
    }

    // Exibir tabuleiro
    printf("== TABULEIRO BATALHA NAVAL ==\n   ");

    for (int j = 0; j < 10; j++)
    {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}
