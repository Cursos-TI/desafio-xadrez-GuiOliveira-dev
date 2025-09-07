#include <stdio.h>

// ---------------------------------------------
// Função recursiva para movimentar a TORRE
// Move-se horizontalmente para a direita
// ---------------------------------------------
void moverTorre(int casasRestantes, int passo) {
    if (casasRestantes == 0) return;
    printf("Casa %d: Direita\n", passo);
    moverTorre(casasRestantes - 1, passo + 1);
}

// ---------------------------------------------
// Função recursiva para movimentar a RAINHA
// Move-se horizontalmente para a esquerda
// ---------------------------------------------
void moverRainha(int casasRestantes, int passo) {
    if (casasRestantes == 0) return;
    printf("Casa %d: Esquerda\n", passo);
    moverRainha(casasRestantes - 1, passo + 1);
}

// ---------------------------------------------
// Função recursiva para movimentar o BISPO
// Move-se na diagonal (Cima Direita)
// Também utiliza loops aninhados para simular diagonais
// ---------------------------------------------
void moverBispo(int casasRestantes, int passo) {
    if (casasRestantes == 0) return;

    // Simula coordenadas diagonais com loops aninhados
    for (int i = 0; i < 1; i++) { // Loop externo (vertical)
        for (int j = 0; j < 1; j++) { // Loop interno (horizontal)
            printf("Casa %d: Cima Direita\n", passo);
        }
    }

    moverBispo(casasRestantes - 1, passo + 1);
}

// ---------------------------------------------
// Movimentação do CAVALO em "L":
// 2 casas para cima e 1 para direita
// Usando loops aninhados com múltiplas variáveis
// ---------------------------------------------
void moverCavalo() {
    const int movimentos = 1;  // Simulando 1 movimento "L"
    int movimentosFeitos = 0;

    printf("Movimento do CAVALO (2 casas para cima e 1 para a direita):\n");

    for (int i = 0; i < 3; i++) {  // Loop de controle geral
        int verticais = 0;

        while (verticais < 2) {
            // Verifica se é parte do "L"
            if (i == 0 && verticais < 2) {
                printf("Passo %d: Cima\n", movimentosFeitos + 1);
                movimentosFeitos++;
                verticais++;
                continue;  // Continua o loop vertical
            }

            break; // Sai do loop se já subiu 2 casas
        }

        // Agora, move para a direita (1 casa)
        if (movimentosFeitos == 2) {
            printf("Passo %d: Direita\n", movimentosFeitos + 1);
            movimentosFeitos++;
            break; // Cavalo faz apenas um movimento completo "L"
        }
    }
}

// ---------------------------------------------
// Função principal
// ---------------------------------------------
int main() {
    // -------------------------------
    // TORRE - Recursiva
    // -------------------------------
    const int casasTorre = 5;
    printf("Movimento da TORRE (5 casas para a direita):\n");
    moverTorre(casasTorre, 1);
    printf("\n");

    // -------------------------------
    // BISPO - Recursiva + Loops aninhados
    // -------------------------------
    const int casasBispo = 5;
    printf("Movimento do BISPO (5 casas na diagonal para cima e à direita):\n");
    moverBispo(casasBispo, 1);
    printf("\n");

    // -------------------------------
    // RAINHA - Recursiva
    // -------------------------------
    const int casasRainha = 8;
    printf("Movimento da RAINHA (8 casas para a esquerda):\n");
    moverRainha(casasRainha, 1);
    printf("\n");

    // -------------------------------
    // CAVALO - Loops aninhados e condições
    // -------------------------------
    moverCavalo();
    printf("\n");

    return 0;
}
