#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    int position;
    struct node *left_child;
    struct node *right_child;
} Node;

Node *create_node(int value, int position);
void insert_node(Node *root, int value, int position);
void print_tree(Node *root, int space, int height);
Node *find_node(Node *root, int position);
void free_tree(Node* node);
int sum_of_nodes(Node* node);
int heigth_tree(Node* node);
bool compare_trees(Node* node1, int height1, Node* node2);