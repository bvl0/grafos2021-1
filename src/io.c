#include"../lib/io.h"

  int** readData(char* filePath,int* nVertex,int* nEdges,int** edges){
    size_t size = 100;
    char *buffer = malloc(size*sizeof(char));
    FILE* file = fopen(filePath,"r");
    if(!file){
      puts("fail to read file.");
      exit(1);
    }
    char firstWord[2];
    char secondWord[100];
    int thirdWord;
    fscanf(file, "%s %s", firstWord, secondWord);
    while(!feof(file) && strcmp(firstWord,"c")==0){
      getline(&buffer,&size,file);
      fscanf(file, "%s %s", firstWord, secondWord);
    }  
    *nVertex = atoi(firstWord);
    *nEdges = atoi(secondWord);
    printf("%d %d aaaaaaaaaaaaa",*nVertex, *nEdges);
    edges = getMatrix(*nVertex);
    fscanf(file, "%s %s", firstWord, secondWord);
    while(!feof(file) && strcmp(firstWord,"c")==0){
      getline(&buffer,&size,file);
      fscanf(file, "%s %s", firstWord, secondWord);
    }
    fscanf(file,"%d", &thirdWord);
    edges[atoi(firstWord) -1][atoi(secondWord) -1] = thirdWord;
    for(int i=1;i < *nEdges;i++){
      int arg1,arg2,arg3;
      fscanf(file,"%d %d %d",&arg1, &arg2, &arg3);
      printf("\n arg3: %d \n ",arg3); 
      edges[arg1-1][arg2-1] = arg3;
    }
    return edges;
  }

  int** getMatrix(int nVertex){
    int** matrix = malloc(nVertex * sizeof(int*));
    
    for(int i = 0;i < nVertex;i++){
      matrix[i]= malloc(nVertex * sizeof(int));
    }

    for(int i=0;i<nVertex;i++){
      for(int j = 0;j < nVertex;j++){
        matrix[i][j]=-1;
      }
    }
    
    return matrix;
  }
