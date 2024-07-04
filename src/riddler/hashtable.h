#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct hash_item {
    int height;
    Node* node;
    struct hash_item *next;
} HashItem;

int hash_function(Node* node, int height);
void insert_hash(HashItem** hash_table, Node* node, int height);
void create_hash_table(Node* node, int height, HashItem** hash_table);
void free_hash_table(HashItem** hash_table, int size);