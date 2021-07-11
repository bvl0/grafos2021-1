#include<stdio.h>
#include<stdlib.h>

#include"../lib/io.h"

void printMatrix(int** matrix, int nVertex){
  for(int i=0;i<nVertex;i++){
    for(int j = 0;j < nVertex;j++){
      printf("%d -- %d : %d\n",i+1,j+1,matrix[i][j]);
    }
  }
}

int main() {
  int* nVertex = malloc(sizeof(int));
  int* nEdges= malloc(sizeof(int));
  int tipo;
  int** edges;
  char* filePath = "./data/teste.txt";

  edges = readData(filePath,nVertex,nEdges,edges);
  printf("%d",*nVertex);
  printMatrix(edges,*nVertex);



  // puts("Choose one: ");
  // puts("1- Matriz de adjacencia \n 2- Lista de adjascencia");
  
  // switch (int i) {
  // case 1:
  //   int** matriz;
  //   break;
  // case 2:
  //   vertex* vertexList;
  // default:
  //   break;
  // }


}