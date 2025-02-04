#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Inicializar o grafo
void InicializaGrafo(Grafo *g, int n, int dig) {
    if (n > MAX_VERTICES) {
        fprintf(stderr, "Erro: numero de vertices excede o maximo permitido (%d).\n", MAX_VERTICES);
        exit(EXIT_FAILURE);
    }

    g->digrafo = dig;
    g->nVertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->Pesos[i][j] = 0;
        }
    }
}

// Implementação da função exibeGrafo
void exibeGrafo(Grafo g) {
    if (g.digrafo) {
        printf("Numero de vertices do Digrafo: %d\n", g.nVertices);
    } else {
        printf("Numero de vertices Grafos: %d\n", g.nVertices);
    }

    for (int i = 0; i < g.nVertices; i++) {
        for (int j = 0; j < g.nVertices; j++) {
            printf("%.1f ", g.Pesos[i][j]);
        }
        printf("\n");
    }
}

// Implementação da função inserirAresta
void inserirAresta(Grafo *g, int de, int para, float peso) {
    if (g->digrafo) {
        g->Pesos[de][para] = peso;
    } else {
        g->Pesos[de][para] = peso;
        g->Pesos[para][de] = peso;
    }
    printf("a");
}

// Implementação da função RemoverAresta
void RemoverAresta(Grafo *g, int de, int para) {
    g->Pesos[de][para] = 0;
    if (!g->digrafo) {
        g->Pesos[para][de] = 0;
    }
}