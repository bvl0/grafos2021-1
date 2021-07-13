#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../lib/io.h"
#include"../lib/vertex.h"
#include"../lib/list.h"


char* getOutfilePath(char* filePath,int nVertex, int nEdges, char* direcionado, int valorado){
  if(valorado == 0){
    char* new = malloc((strlen(filePath) +5)*sizeof(char));
    for (size_t i = 0; i < 7; i++)
    {
      new[i] = filePath[i];
    }
    new[7] = 'o';
    new[8] = 'u';
    new[9] = 't';
    new[10] = '/';
    for (size_t i = 11; i < strlen(filePath) + 5; i++)
    {
      new[i] = filePath[i-4];
    }
    new[strlen(filePath) +3]='t';
    new[strlen(filePath) +2]='o';
    new[strlen(filePath) +1]='d';
    new[strlen(filePath) + 4]='\0';
    return new;
  }
  else if(!direcionado && valorado ==1){
    char* new = malloc((strlen(filePath) +6)*sizeof(char));
    for (size_t i = 0; i < 7; i++)
    {
      new[i] = filePath[i];
    }
    new[7] = 'o';
    new[8] = 'u';
    new[9] = 't';
    new[10] = '/';
    for (size_t i = 11; i < 16; i++)
    {
      new[i] = filePath[i-4];
    }

    new[16] = 'v';

    for (size_t i = 17; i < strlen(filePath) +6; i++)
    {
      new[i] = filePath[i-5];
    }
    new[strlen(filePath) +4]='t';
    new[strlen(filePath) +3]='o';
    new[strlen(filePath) +2]='d';
    new[strlen(filePath) + 5]='\0';
    return new;
  }
  else{
    char* new = malloc((strlen(filePath) +6)*sizeof(char));
    for (size_t i = 0; i < 7; i++)
    {
      new[i] = filePath[i];
    }
    new[7] = 'o';
    new[8] = 'u';
    new[9] = 't';
    new[10] = '/';
    for (size_t i = 11; i < 18; i++)
    {
      new[i] = filePath[i-4];
    }

    new[18] = 'v';

    for (size_t i = 19; i < strlen(filePath) +6; i++)
    {
      new[i] = filePath[i-5];
    }
    new[strlen(filePath) +4]='t';
    new[strlen(filePath) +3]='o';
    new[strlen(filePath) +2]='d';
    new[strlen(filePath) + 5]='\0';
    return new;
  }
}


void printMatrix(int** matrix, int nVertex, int nEdges, char* direcionado, int valorado,char* filePath){
  char* outputPath = getOutfilePath(filePath,nVertex,nEdges,direcionado,valorado);
  puts(outputPath);
  FILE* file = fopen(outputPath,"w");

  fprintf(file,"graph G\n{\n");
  for(int i=0;i<nVertex;i++){
    for(int j = 0;j < nVertex;j++){
      if(matrix[i][j]!=0){
        if(!direcionado && valorado == 0){
          fprintf(file,"  %d -- %d;\n",i+1,j+1);
        }
        else if(!direcionado && valorado ==1){
          fprintf(file,"  %d -- %d[label = %d]\n",i+1,j+1,matrix[i][j]);
        }
        else if(direcionado && valorado ==0){
          fprintf(file,"  %d -> %d;\n",i+1,j+1);
        }
        else{
          fprintf(file,"  %d -> %d[label = %d]\n",i+1,j+1,matrix[i][j]);
        }
      }
    }
  }
  fprintf(file,"}");
  free(outputPath);
  fclose(file);
}
void printEdgeList(vertex* list, int nVertex, int nEdges, char* direcionado, int valorado, char* filePath) {
  char* outputPath = getOutfilePath(filePath,nVertex,nEdges,direcionado,valorado);
  FILE* file = fopen(outputPath,"w");
  fprintf(file,"graph G\n{\n");
  for(int i=0;i<nVertex;i++){
    printListV2(list[i].edgeList,i+1,direcionado,valorado,file);
  }
  fprintf(file,"}");
  free(outputPath);
  fclose(file);
}

void printaSaida(int** edges, vertex* edgesList,int nVertex,int nEdges,int choose,char* direcionado,int valorado, char* filePath){
  if(choose == 1){
    printMatrix(edges,nVertex,nEdges,direcionado,valorado,filePath); //printa matriz
  }
  if(choose == 2){
    printEdgeList(edgesList,nVertex,nEdges,direcionado,valorado,filePath);//printa lista
  }
}

void freeMatrix(int** edges, int nVertex){
  for (size_t i = 0; i < nVertex; i++)
  {
    free(edges[i]);
  }
  free(edges); 
}

void freeList(vertex* list, int nVertex){
  for (size_t i = 0; i < nVertex; i++)
  {
    deleteList(list[i].edgeList);
    free(list[i].edgeList);
  }
  free(list);
}

int main() {
  int* nVertex = malloc(sizeof(int));
  int* nEdges= malloc(sizeof(int));
  int tipo;
  int** edges;
  vertex* edgesList;
  char* filePath = "./data/digrafo_8_11.txt";
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
  printaSaida(edges,edgesList,*nVertex,*nEdges,choose,direcionado,valorado,filePath);

  if(choose == 1){
    freeMatrix(edges,*nVertex);
  }
  if (choose == 2)
  {
    freeList(edgesList,*nVertex);
  }
  
  free(nVertex);
  free(nEdges);
}


