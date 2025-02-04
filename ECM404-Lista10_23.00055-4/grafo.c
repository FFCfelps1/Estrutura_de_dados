#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

void ExibirArestas (Grafo g)
{
    int i, j, a;
    printf("\nPeso da Aresta:\n");
    a = 65;
    for (i=0; i<g.nVertices; i++)
        for (j=0; j<g.nVertices; j++)
            if (PesoDaAresta(g, i, j) != 0)
                printf("Aresta %c%i,%i%c: w(%c)=%.1f\n",
                       g.digrafo==0?'{':'(',
                       i, j,
                       g.digrafo==0?'}':')',
                       a++,
                       PesoDaAresta(g, i, j)
                      );
    printf ("\n");
}

void ExibirGrafo (Grafo g)
{
    int i, j;
    // Troque por CLS se estiver usando Windows
    system("cls");
    printf ("Numero de vertices do %s: %i\n", g.digrafo==0?"GRAFO":"DIGRAFO",g.nVertices);
    for (i=0; i <g.nVertices; i++)
    {
        for (j=0; j < g.nVertices; j++)
            printf ("%0.1f   ", PesoDaAresta (g, i, j));
        printf ("\n");
    }
    printf ("\n");
}

void CriarGrafo (Grafo *g, int n, int dig)
{
    int i, j;
    g->nVertices = n;
    g->digrafo = dig;
    for (i=0; i < g->nVertices; i++)
        for (j=0; j < g->nVertices; j++)
            g->Pesos[i][j] = 0;
}


void InserirAresta (Grafo *g, int de, int para, float peso)
{
    g->Pesos[de][para] = peso;
    if (!g->digrafo)
        g->Pesos[para][de] = peso;
}


void RemoverAresta (Grafo *g, int de, int para)
{
    g->Pesos[de][para] = 0;
    if (!g->digrafo)
        g->Pesos[para][de] = 0;
}


float PesoDaAresta (Grafo g, int de, int para)
{
    return g.Pesos[de][para];
}

int GrauDeEntrada (Grafo g, int v){
    int i, grau;
    grau = 0;
    for (i=0; i < g.nVertices; i++)
        if (g.Pesos[i][v] != 0)
            grau++;
    return grau;
}

int GrauDeSaida (Grafo g, int v){
    int i, grau;
    grau = 0;
    for (i=0; i < g.nVertices; i++)
        if (g.Pesos[v][i] != 0)
            grau++;
    return grau;
}

int Sorvedouro (Grafo g, int v){
    int i;
    for (i=0; i < g.nVertices; i++)
        if (g.Pesos[v][i] != 0)
            return 0;
    return 1;
}

int Vertedouro (Grafo g, int v){
    int i;
    for (i=0; i < g.nVertices; i++)
        if (g.Pesos[i][v] != 0)
            return 0;
    return 1;
}

int Adjacente (Grafo g, int de, int para){
    return g.Pesos[de][para] != 0;
}

void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT]){
    int i, j, k;
    for (i=0; i < g.nVertices; i++)
        for (j=0; j < g.nVertices; j++)
            w[i][j] = g.Pesos[i][j] != 0;
    for (k=0; k < g.nVertices; k++)
        for (i=0; i < g.nVertices; i++)
            for (j=0; j < g.nVertices; j++)
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
}

int Alcanca (Grafo g, int de, int para){
    int w[MAX_VERT][MAX_VERT];
    Warshall (g, w);
    return w[de][para];
}

float PesoDoPasseio (Grafo g, ListaDeVertices p){
    int i;
    float peso;
    peso = 0;
    for (i=0; i < p.nVertices-1; i++)
        if (g.Pesos[p.vertices[i]][p.vertices[i+1]] == 0)
            return -1;
        else
            peso += g.Pesos[p.vertices[i]][p.vertices[i+1]];
    return peso;
}