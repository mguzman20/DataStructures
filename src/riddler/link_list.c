#include "link_list.h"

LinkList *link_list_create(int value){
    LinkList *new = malloc(sizeof(LinkList));
    new->value = value;
    new->next = NULL;
    return new;
}

// apendd item sorted to list
void link_list_append(LinkList *list, int value){
    LinkList *new = link_list_create(value);
    LinkList *aux = list;
    while (aux->next != NULL && aux->next->value < value){
        aux = aux->next;
    }
    new->next = aux->next;
    aux->next = new;
}


void free_link_list(LinkList *list){
    LinkList *aux = list;
    while (aux != NULL){
        LinkList *aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}