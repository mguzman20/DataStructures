#include "node.h"

Node *create_node(int value, int position) {
    Node *node = malloc(sizeof(Node));
    node->position = position;
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}



void insert_node(Node *root, int value, int position) {
    Node *node = create_node(value, position);
    Node *temp = find_node(root, position / 2);
    while (temp != NULL) {
        if (temp->left_child == NULL) {
            temp->left_child = node;
            return;
        } else if (temp->right_child == NULL) {
            temp->right_child = node;
            return;
        }
    }
}

//find node with a given position
Node *find_node(Node *root, int position) {
    if (root == NULL) {
        return NULL;
    }
    if (root->position == position) {
        return root;
    }
    Node *left = find_node(root->left_child, position);
    if (left != NULL) {
        return left;
    }
    Node *right = find_node(root->right_child, position);
    if (right != NULL) {
        return right;
    }
    return NULL;
}
void print_tree(Node *root, int space, int heigth)
{
    if (heigth == 0)
    {
        return;
    }
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    print_tree(root->right_child, space, heigth - 1);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);
 
    // Process left child
    print_tree(root->left_child, space, heigth - 1);
}

int sum_of_nodes(Node* node){
    if (node == NULL){
        return 0;
    }
    return node->value + sum_of_nodes(node->left_child) + sum_of_nodes(node->right_child);
}

void free_tree(Node* node){
    if (node == NULL){
        return;
    }
    free_tree(node->left_child);
    free_tree(node->right_child);
    free(node);
}

int heigth_tree(Node* node){
    if (node == NULL){
        return 0;
    }
    int left = heigth_tree(node->left_child);
    int right = heigth_tree(node->right_child);
    if (left > right){
        return left + 1;
    } else {
        return right + 1;
    }
}

bool compare_trees(Node* node1, int height1, Node* node2){
    if (height1 == 0){
        return true;
    }
    if (node1 == NULL || node2 == NULL){
        return false;
    }
    if (node1->value != node2->value){
        return false;
    }
    return compare_trees(node1->left_child, height1 - 1, node2->left_child) && compare_trees(node1->right_child, height1 - 1, node2->right_child);
}