#include"../lib/io.h"

  void readData(char* filePath,int* nVertex,int* nEdges,int** edges){
    char buffer[100];
    FILE* file = fopen(filePath,"r");
    if(!file){
      puts("fail to read file.");
      exit(1);
    }
    
    getline(buffer,100,file);
    while(!FEOF(file) && buffer[0] != "c"){
      getline(buffer,100,file);
    }
    nVertex = buffer[0];
    nEdges = buffer[1];
    edges = getMatrix(nVertex);
    
    getline(buffer,100,file);
    while(!FEOF(file) && buffer[0] != "c"){
      getline(buffer,100,file);
    }
    edges[buffer[0]][buffer[1]] = buffer[2];
    for(int i=1; i<nEdges;i++){
      getline(buffer,100,file);
      edges[buffer[0]][buffer[1]] = buffer[2];
    }

  }

  int** getMatrix(int* nVertex){
    int** matrix = malloc(*nVertex * sizeof(int*));
    
    for(int i = 0;i<nVertex;i++){
      matrix[i]= malloc(*nVertex * sizeof(int));
    }
    
    return matrix;
  }
