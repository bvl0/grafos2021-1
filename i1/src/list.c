#include "../lib/list.h"


struct item {
    void *element;
    struct item *next;
};

struct list {
    Item *head;
    Item *tail;
    int length;
};

List* createList() {
List *l = malloc(sizeof(List));
l->head = NULL;
l->tail = NULL;
l->length = 0;
return l;
}

Item* createItem(void *element) {
    Item *item = malloc(sizeof(Item));
    item->element = element;
    item->next = NULL;
    return item;
}

void pushToList(List *list, void *element) {
    if (list->head == NULL) {
        Item *item = createItem(element);
        list->head = item;
        list->tail = list->head;
        list->length = 1;
    } else {
        Item *item = createItem(element);
        list->tail->next = item;
        list->tail = item;
        list->length += 1;
    }
}

void deleteList(List *list) {
    Item *p = list->head;
    for (int i = 0; i < list->length; i += 1) {
        list->head = list->head->next;
        vertex* aux =  p->element;
        free(aux->edgeList);
        free(aux);
        free(p);
        p = list->head;
    }
}

int listLength(List *list) {
    return list->length;
}

void printList(List *list) {
    Item *p = list->head;
    for (int i = 0; i < list->length; i += 1) {
        int *value = p->element;
        printf("%d ", *value);
        p = p->next;
    }
    putchar('\n');
}

void printListV2(List *list, int root, char* direcionado, int valorado, FILE* file) {
    Item *p = list->head;
    for (int i = 0; i < list->length; i += 1) {
        vertex* value = p->element;
        if(!direcionado && valorado == 0){
            fprintf(file,"  %d -- %d;\n",root,value->name);
        }
        else if(!direcionado && valorado ==1){
            fprintf(file,"  %d -- %d[label = %d]\n",root, value->name, value->weight);
        }
        else if(direcionado && valorado ==0){
            fprintf(file,"  %d -> %d;\n",root,value->name);
        }
        else{
            fprintf(file,"  %d -> %d[label = %d]\n",root, value->name, value->weight);;
        } 
        p = p->next;
    }
}