#ifndef IO_H_
#define IO_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"../lib/vertex.h"
#include"../lib/list.h"

int** readData(char* filePath,int* nVertex,int* nEdges,int* valorado,int** edges);
vertex* readDataVertexVersion(char* filePath,int* nVertex,int* nEdges,int* valorado,vertex* edgesList);
int** getMatrix(int nVertex);


#endif // !IO_H_