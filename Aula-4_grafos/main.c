//coloque todas as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
//a biblioteca criada de grafos
#include "grafo.h"

int main (){
    //crie um grafo
    Grafo g;
    //inicialize o grafo
    InicializaGrafo(&g, 3, 1);
    //insira arestas
    inserirAresta(&g, 0, 1, 5);
    inserirAresta(&g, 0, 2, 1);
    inserirAresta(&g, 1, 0, 3);
    inserirAresta(&g, 1, 1, 4);
    inserirAresta(&g, 1, 2, 7);
    //exiba o grafo
    exibeGrafo(g);
}