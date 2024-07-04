#include "hashtable.h"

int hash_function(Node* node, int height)
{
    if (height > 0)
    {
        return node->value + hash_function(node->left_child, height - 1) + hash_function(node->right_child, height - 1);
    }
    else
    {
        return 0;
    }
    
}

void insert_hash(HashItem** hash_table, Node* node, int height){
    int key = hash_function(node, height);
    HashItem* item = malloc(sizeof(HashItem));
    item->node = node;
    item->height = height;
    item->next = NULL;
    if (hash_table[key] == NULL){
        hash_table[key] = item;
    } else {
        HashItem* temp = hash_table[key];
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = item;
    }
}

void create_hash_table(Node* node, int height, HashItem** hash_table){
    if (node == NULL){
        return;
    }
    int temp = height;
    while (temp > 1){
        insert_hash(hash_table, node, temp);
        temp--;
    }
    create_hash_table(node->left_child, height - 1, hash_table);
    create_hash_table(node->right_child, height - 1, hash_table);
}

void free_hash_table(HashItem** hash_table, int size){
    for (int i = 0; i < size; i++){
        HashItem* item = hash_table[i];
        while (item != NULL){
            HashItem* temp = item->next;
            free(item);
            item = temp;
        }
    }
    free(hash_table);
}