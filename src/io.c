#include"../lib/io.h"

  void readData(char* filePath,int* nVertex,int* nEdges,int** edges){
    size_t size = 100;
    char *buffer = malloc(size*sizeof(char));
    FILE* file = fopen(filePath,"r");
    if(!file){
      puts("fail to read file.");
      exit(1);
    }
    
    getline(&buffer,&size,file);
    while(!feof(file) && buffer[0] == 'c'){
      getline(&buffer,&size,file);
    }
    printf("%c\n",buffer[0]);
    printf("%c\n",buffer[2]);
    int firstInt = (int)buffer[0];
    int secondInt = (int)buffer[2];
    printf("%d aaa\n",firstInt);
    nVertex = &firstInt;
    nEdges = &secondInt;
    edges = getMatrix(nVertex);
    
    getline(&buffer,&size,file);
    while(!feof(file) &&  buffer[0] == 'c'){
      getline(&buffer,&size,file);
    }
    
    edges[buffer[0]][buffer[2]] = (int)buffer[4];
    for(int i=1;i < *nEdges;i++){
      getline(&buffer,&size,file);
      edges[buffer[0]][buffer[2]] = (int)buffer[4];
      // printf("%i\n",edges[buffer[0]][buffer[2]]);
    }

  }

  int** getMatrix(int* nVertex){
    int** matrix = malloc(*nVertex * sizeof(int*));
    
    for(int i = 0;i < *nVertex;i++){
      matrix[i]= malloc(*nVertex * sizeof(int));
    }
    
    return matrix;
  }
