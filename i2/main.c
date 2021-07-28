#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Vertex{
  int name;
  int weight;
  struct list* edgeList;
}vertex;

void freeMatrix(int** edges, int nVertex);

typedef struct Test{
  int startingVertex;
  int nVertex;
  int nEdges;
  int** edges;
}tests;

int** getMatrix(int nVertex){
    int** matrix = malloc(nVertex * sizeof(int*));
    
    int i;
    for(i = 0;i < nVertex;i++){
      matrix[i]= malloc(nVertex * sizeof(int));
    }

    for(i=0;i<nVertex;i++){
      int j;
      for(j = 0;j < nVertex;j++){
        matrix[i][j]=0;
      }
    }
    
    return matrix;
  }
  
  tests* readData(int* numTests){
    size_t size = 100;
    char *buffer = malloc(size*sizeof(char));
    
    scanf("%d ",numTests);
    tests *testes = malloc(*numTests*sizeof(tests));
    
    size_t i;
    for (i = 0; i < *numTests; i++)
    {
      int** edges;
      int starting;
      int a;
      int b;
      
      scanf("%d",&starting);
      testes[i].startingVertex = starting;
      int nVertex = 0;
      int nEdges = 0;
      scanf("%d %d",&nVertex,&nEdges);
        
      testes[i].nEdges = nEdges;
      testes[i].nVertex = nVertex;

      //*nVertex =a;
      //*nEdges = b;
      edges = getMatrix(nVertex);//inicializa a matriz
      int j;
      for(j=0;j <nEdges;j++){
        scanf("%d %d",&a, &b);
        edges[a][b] = 1;
      }
      testes[i].edges = edges;
    } 
    
    free(buffer);
    return testes;
  }

void maze(int** edges,int nVertex, int* nDuplas){
  size_t i;
  for (i = 0; i < nVertex; i++)
  {
    size_t j;
    for (j = i+1; j < nVertex; j++)
    {
      if(edges[i][j] == 1 &&(edges[j][i]) == 1)
        *nDuplas += 1;
    }
    
  }
}


int main(int argc, char **argv) {
  //declaração das variaveis uteis pras proximas funcoes
  //int* nVertex = malloc(sizeof(int));
  //int* nEdges= malloc(sizeof(int));
  int* nTests= malloc(sizeof(int));
  tests *testes;
  testes = readData(nTests);//funcao que le os dados e cria a matriz
  size_t i;
  for (i = 0; i < *nTests; i++)
  {
    int menorCaminho;
    int nDuplas=0;
    maze(testes[i].edges,testes[i].nVertex,&nDuplas);
    menorCaminho = (testes[i].nEdges - nDuplas) * 2;
    printf("%d\n",menorCaminho);
  } 
  //printf("\n");
  for (i = 0; i < *nTests; i++)
  {
    freeMatrix(testes[i].edges,testes[i].nVertex);
    //free(testes);
  }
   

free(nTests);
}








void freeMatrix(int** edges, int nVertex){
  size_t i;
  for (i = 0; i < nVertex; i++)
  {
    free(edges[i]);
  }
  free(edges); 
}


