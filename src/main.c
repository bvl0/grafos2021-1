#include<stdio.h>
#include<stdlib.h>

#include"../lib/io.h"

int main() {
  int* nVertex;
  int* nEdges;
  int tipo;
  int** edges;
  char* filePath = "./data/teste.txt";

  readData(filePath,nVertex,nEdges,edges);
  
  puts("Choose one: ");
  puts("1- Matriz de adjacencia \n 2- Lista de adjascencia");
  
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