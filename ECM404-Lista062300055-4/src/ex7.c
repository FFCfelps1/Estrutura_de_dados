/* 
 * Enunciado: 
 * Crie um programa capaz de ler 4 estruturas Retângulo
 * (leitura de 2 em 2 pontos) que devem ser armazenados em um array.
 * A seguir, o programa deve exibir o array de retângulos, ordenando-os por
 * área. Utilize o algoritmo de ordenação que preferir.
 * 
 * Exemplos: 
 *
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,2,2
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,1,1 
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,3,3
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,1.5,1.5
 *   [Ret{Ponto{0.00, 0.00},Ponto{1.00, 1.00}},
 *   Ret{Ponto{0.00, 0.00},Ponto{1.50, 1.50}},
 *   Ret{Ponto{0.00, 0.00},Ponto{2.00, 2.00}},
 *   Ret{Ponto{0.00, 0.00},Ponto{3.00, 3.00}}]
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    Ponto inf_esq;
    Ponto sup_dir;
} Retangulo;

// Função para calcular a área de um retângulo
float calcularArea(Retangulo ret) {
    float base = ret.sup_dir.x - ret.inf_esq.x;
    float altura = ret.sup_dir.y - ret.inf_esq.y;
    return base * altura;
}

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    float area_a = calcularArea(*(Retangulo*)a);
    float area_b = calcularArea(*(Retangulo*)b);
    if (area_a < area_b)
        return -1;
    else if (area_a > area_b)
        return 1;
    else
        return 0;
}

int main() {
    Retangulo retangulos[4];

    // Leitura dos retângulos
    for (int i = 0; i < 4; i++) {
        printf("Digite os valores do retângulo (x1, y1, x2, y2): ");
        scanf("%f,%f,%f,%f", &retangulos[i].inf_esq.x, &retangulos[i].inf_esq.y, 
                              &retangulos[i].sup_dir.x, &retangulos[i].sup_dir.y);
    }

    // Ordenação dos retângulos por área
    qsort(retangulos, 4, sizeof(Retangulo), comparar);

    // Exibição dos retângulos ordenados
    printf("[");
    for (int i = 0; i < 4; i++) {
        printf("Ret{Ponto{%.2f, %.2f},Ponto{%.2f, %.2f}}", 
               retangulos[i].inf_esq.x, retangulos[i].inf_esq.y,
               retangulos[i].sup_dir.x, retangulos[i].sup_dir.y);
        if (i < 3)
            printf(", ");
    }
    printf("]\n");

    return 0;
}

