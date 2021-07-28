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
  
  tests* readData(char* filePath,int* numTests){
    size_t size = 100;
    char *buffer = malloc(size*sizeof(char));
    FILE* file = fopen(filePath,"r");
    
    if(!file){
      puts("fail to read file.");
      exit(1);
    }
    
    fscanf(file,"%d ",numTests);
    tests *testes = malloc(*numTests*sizeof(tests));
    
    size_t i;
    for (i = 0; i < *numTests; i++)
    {
      int** edges;
      int starting;
      int a;
      int b;
      
      fscanf(file,"%d",&starting);
      testes[i].startingVertex = starting;
      int nVertex = 0;
      int nEdges = 0;
      fscanf(file,"%d %d",&nVertex,&nEdges);
        
      testes[i].nEdges = nEdges;
      testes[i].nVertex = nVertex;

      //*nVertex =a;
      //*nEdges = b;
      edges = getMatrix(nVertex);//inicializa a matriz
      int j;
      for(j=0;j <nEdges;j++){
        fscanf(file,"%d %d",&a, &b);
        edges[a][b] = 1;
      }
      testes[i].edges = edges;
    } 
    
    fclose(file);
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
  char* filePath = argv[1];
  puts("Choose one: ");
  puts("1- Matriz de adjascencia \n2- Lista de adjascencia");

  int choose;
  choose = 1;
  if(choose == 1) {
    puts(filePath);
    testes = readData(filePath,nTests);//funcao que le os dados e cria a matriz
    printf("teste %d \n",*nTests);
    size_t i;
    for (i = 0; i < *nTests; i++)
    {
      int menorCaminho;
      int nDuplas=0;
      maze(testes[i].edges,testes[i].nVertex,&nDuplas);
      //printf("\n teste %d ",testes[i].nDuplas);
      menorCaminho = (testes[i].nEdges - nDuplas) * 2;
      //menorCaminho = (menorCaminho - testes[i].nDuplas) * 2;
      printf("%d\n",menorCaminho);
      
    } 
  for (i = 0; i < *nTests; i++)
  {
    freeMatrix(testes[i].edges,testes[i].nVertex);
    //free(testes);
  }
   
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


