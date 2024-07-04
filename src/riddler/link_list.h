#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct link_list {
    int value;
    struct link_list *next;
} LinkList;

LinkList *link_list_create(int value);
void link_list_append(LinkList *list, int value);
void link_list_sort(LinkList *list);
void free_link_list(LinkList *list);