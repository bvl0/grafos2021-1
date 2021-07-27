#ifndef VERTEX_H_
#define VERTEX_H_
#include<stdio.h>
#include<stdlib.h>
#include"../lib/list.h"

typedef struct Vertex{
  int name;
  int weight;
  struct list* edgeList;
}vertex;

vertex* createVertex(int nome, int weight);

#endif // !VERTEX_H_