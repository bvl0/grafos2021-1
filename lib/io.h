#ifndef IO_H_
#define IO_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void readData(char* filePath,int* nVertex,int* nEdges,int** edges);
int** getMatrix(int* nVertex);


#endif // !IO_H_