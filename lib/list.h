#ifndef _LIST_
#define _LIST_

#include <stdio.h>
#include <stdlib.h>

#include"../lib/vertex.h"

typedef struct item Item;

typedef struct list List;

List* createList();

Item* createItem();

void pushToList(List *, void *);

void deleteList(List *);

void printList(List *);

void printListV2(List *list, int root, char* direcionado, int valorado, FILE* file);

#endif