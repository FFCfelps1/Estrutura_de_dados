/* 
 * Enunciado: 
 * Crie um programa capaz de ler dois pontos que compõe uma estrutura de um 
 * Retângulo. Os dois pontos correspondem aos vértices inferior esquerdo e 
 * superior direito. Após a leitura do Retângulo, deve ser lido um terceiro 
 * ponto. O programa, então, exibirá se o ponto digitado pertence ao retângulo.
 * 
 * Exemplos: 
 *
 *   Digite um ponto (x, y): 0, 0
 *   Digite um ponto (x, y): 4, 4
 *   Digite um ponto (x, y): 2, 1
 *   O ponto digitado faz parte do Retângulo
 *
 *   Digite um ponto (x, y): 0, 0 
 *   Digite um ponto (x, y): 3, 4
 *   Digite um ponto (x, y): 5, 7
 *   O ponto digitado não pertence ao Retângulo
 *
 */

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto inferior_esq;
    Ponto superior_dir;
} Retangulo;

int pontoPertenceRetangulo(Ponto ponto, Retangulo retangulo) {
    if (ponto.x >= retangulo.inferior_esq.x && ponto.x <= retangulo.superior_dir.x &&
        ponto.y >= retangulo.inferior_esq.y && ponto.y <= retangulo.superior_dir.y) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Retangulo retangulo;
    Ponto ponto;

    printf("Digite as coordenadas do vértice inferior esquerdo (x, y): ");
    scanf("%d, %d", &retangulo.inferior_esq.x, &retangulo.inferior_esq.y);

    printf("Digite as coordenadas do vértice superior direito (x, y): ");
    scanf("%d, %d", &retangulo.superior_dir.x, &retangulo.superior_dir.y);

    printf("Digite as coordenadas do ponto a ser verificado (x, y): ");
    scanf("%d, %d", &ponto.x, &ponto.y);

    if (pontoPertenceRetangulo(ponto, retangulo)) {
        printf("O ponto digitado faz parte do Retângulo\n");
    } else {
        printf("O ponto digitado não pertence ao Retângulo\n");
    }

    return 0;
}
