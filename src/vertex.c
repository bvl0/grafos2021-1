#include"../lib/vertex.h"

vertex* createVertex(int nome, int weight){
  vertex* aux = malloc(sizeof(vertex));
  aux->name = nome;
  aux->weight = weight;
  aux->edgeList = createList();
  return aux;
}

