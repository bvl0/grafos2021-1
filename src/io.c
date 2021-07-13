#include"../lib/io.h"

  int** getMatrix(int nVertex){
    int** matrix = malloc(nVertex * sizeof(int*));
    
    for(int i = 0;i < nVertex;i++){
      matrix[i]= malloc(nVertex * sizeof(int));
    }

    for(int i=0;i<nVertex;i++){
      for(int j = 0;j < nVertex;j++){
        matrix[i][j]=0;
      }
    }
    
    return matrix;
  }
  vertex* getVertex(int nVertex){
    vertex* vertexlist = malloc(nVertex * sizeof(vertex));
    
    for(int i = 0;i < nVertex;i++){
      vertexlist[i].name = i+1;
      vertexlist[i].weight = -1;
      vertexlist[i].edgeList = createList();
    } 
    return vertexlist;
  }
  
  int** readData(char* filePath,int* nVertex,int* nEdges,int* valorado,int** edges){
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
    edges = getMatrix(*nVertex);
    
    fscanf(file, "%s %s", firstWord, secondWord);
    while(!feof(file) && strcmp(firstWord,"c")==0){
      getline(&buffer,&size,file);
      fscanf(file, "%s %s", firstWord, secondWord);
    }
    
    fscanf(file,"%d", &thirdWord);
    if(thirdWord == 0){
      edges[atoi(firstWord) -1][atoi(secondWord) -1] = 1;
      valorado = 0;
    }
    else{
      *valorado = 1;
      edges[atoi(firstWord) -1][atoi(secondWord) -1] = thirdWord;
    }
    
    for(int i=1;i < *nEdges;i++){
      int arg1,arg2,arg3;
      fscanf(file,"%d %d %d",&arg1, &arg2, &arg3);
      if(valorado == 0){
        edges[arg1-1][arg2-1] = 1;
      }
      else{
        puts("serase");
        edges[arg1-1][arg2-1] = arg3;
      }
    }
    fclose(file);
    free(buffer);
    return edges;
  }

vertex* readDataVertexVersion(char* filePath,int* nVertex,int* nEdges,int* valorado,vertex* edgesList){
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
    edgesList = getVertex(*nVertex);
    
    fscanf(file, "%s %s", firstWord, secondWord);
    while(!feof(file) && strcmp(firstWord,"c")==0){
      getline(&buffer,&size,file);
      fscanf(file, "%s %s", firstWord, secondWord);
    }
    
    fscanf(file,"%d", &thirdWord);
    if(thirdWord !=0){
      *valorado = 1;
    }
    vertex* aux = createVertex(atoi(secondWord),thirdWord);
    pushToList(edgesList[atoi(firstWord)-1].edgeList,aux);
    
    for(int i=1;i < *nEdges;i++){
      int arg1,arg2,arg3;
      fscanf(file,"%d %d %d",&arg1, &arg2, &arg3);
      vertex* aux = createVertex(arg2,arg3);
      pushToList(edgesList[arg1-1].edgeList,aux);
    }
    fclose(file);
    free(buffer);
    return edgesList;
  }



