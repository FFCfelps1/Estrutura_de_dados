#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100  // Defina um valor adequado para o número máximo de vértices

typedef struct {
    int digrafo;
    int nVertices;
    float Pesos[MAX_VERTICES][MAX_VERTICES];  // Defina a matriz com um tamanho máximo
} Grafo;

void InicializaGrafo(Grafo *g, int n, int dig);
void exibeGrafo(Grafo g);
void inserirAresta(Grafo *g, int de, int para, float peso);
void RemoverAresta(Grafo *g, int de, int para);

#endif // GRAFO_H