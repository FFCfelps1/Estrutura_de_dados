/* 
 * Enunciado: 
 * Crie um programa capaz de ler os valores(float) de x e y de uma 
 * estrutura Ponto. A seguir, o programa deve calcular e exibir a distância 
 * entre esses dois pontos.
 * 
 * Exemplos: 
 *
 *   Digite um ponto (x, y): 0, 1
 *   Digite um ponto (x, y): 0, 0
 *   Distancia: 1.00
 *   
 *   Digite um ponto (x, y): 5, 7
 *   Digite um ponto (x, y): 10, 3
 *   Distancia: 6.40
 *
 */

#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

Ponto lerPonto();
float calcularDistancia(Ponto p1, Ponto p2);

int main() {
    Ponto p1, p2;

    printf("Digite o primeiro ponto (x, y): ");
    p1 = lerPonto();

    printf("Digite o segundo ponto (x, y): ");
    p2 = lerPonto();

    float distancia = calcularDistancia(p1, p2);

    printf("Distancia: %.2f\n", distancia);

    return 0;
}

Ponto lerPonto() {
    Ponto p;
    scanf("%f, %f", &p.x, &p.y);
    return p;
}

float calcularDistancia(Ponto p1, Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
