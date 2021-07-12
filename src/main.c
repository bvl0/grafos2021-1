#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../lib/io.h"
#include"../lib/vertex.h"
#include"../lib/list.h"

void printMatrix(int** matrix, int nVertex, char* direcionado, int valorado){
  printf("graph G\n{\n");
  for(int i=0;i<nVertex;i++){
    for(int j = 0;j < nVertex;j++){
      if(matrix[i][j]!=-1){
        if(!direcionado && valorado == 0){
          printf("  %d -- %d;\n",i+1,j+1);
        }
        else if(!direcionado && valorado ==1){
          printf("  %d -- %d[label = %d]\n",i+1,j+1,matrix[i][j]);
        }
        else if(direcionado && valorado ==0){
          printf("  %d -> %d;\n",i+1,j+1);
        }
        else{
          printf("  %d -> %d[label = %d]\n",i+1,j+1,matrix[i][j]);
        }
      }
    }
  }
  printf("}");
}
void printEdgeList(vertex* list, int nVertex, char* direcionado, int valorado) {
  printf("graph G\n{\n");
  for(int i=0;i<nVertex;i++){
    printListV2(list[i].edgeList,i+1,direcionado,valorado);
  }
  printf("}");
}

void printaSaida(int** edges, vertex* edgesList,int nVertex,int choose,char* direcionado,int valorado){
  if(choose == 1){
    printMatrix(edges,nVertex,direcionado,valorado); //printa matriz
  }
  if(choose == 2){
    printEdgeList(edgesList,nVertex,direcionado,valorado);//printa lista
  }
}


int main() {
  int* nVertex = malloc(sizeof(int));
  int* nEdges= malloc(sizeof(int));
  int tipo;
  int** edges;
  vertex* edgesList;
  char* filePath = "./data/grafo_8_11.txt";
  char* direcionado;
  int valorado = 0;

  direcionado = strstr(filePath,"digrafo");

  puts("Choose one: ");
  puts("1- Matriz de adjacencia \n 2- Lista de adjascencia");

  int choose;
  scanf("%d",&choose);
  if(choose == 1) {
    edges = readData(filePath,nVertex,nEdges,&valorado,edges);
    printf("%d aaa",*nVertex);
  }
  if(choose ==2 ) {
    edgesList = readDataVertexVersion(filePath,nVertex,nEdges,&valorado,edgesList);
  }
  printaSaida(edges,edgesList,*nVertex,choose,direcionado,valorado);
}


