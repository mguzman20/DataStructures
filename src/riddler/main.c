#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "hashtable.h"
#include "link_list.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Modo de uso: %s input output\nDonde:\n", argv[0]);
    printf("\t\"input\" es la ruta al archivo de input\n");
    printf("\t\"output\" es la ruta al archivo de output\n");
    return 1;
  }

  // Abrimos el archivo de input
  FILE* input_stream = fopen(argv[1], "r");

  // Abrimos el archivo de output
  FILE* output_stream = fopen(argv[2], "w");

  // Si alguno de los dos archivos no se pudo abrir
  if (!input_stream) {
    printf("El archivo %s no existe o no se puede leer\n", argv[1]);
    return 2;
  }
  if (!output_stream) {
    printf("El archivo %s no se pudo crear o no se puede escribir\n", argv[2]);
    printf("Recuerda que \"fopen\" no puede crear carpetas\n");
    fclose(input_stream);
    return 3;
  }

  // [Aqui va tu tarea]
  int n_nodes;
  fscanf(input_stream, "%d", &n_nodes);
  int value;
  Node* root;
  fscanf(input_stream, "%d", &value);
  root = create_node(value, 1);
  for (int i = 1; i < n_nodes; i++) {
    fscanf(input_stream, "%d", &value);
    insert_node(root, value, i+1);
  }

  HashItem** hash_table = calloc(n_nodes, sizeof(HashItem*));

  int heigth = heigth_tree(root);
  create_hash_table(root, heigth, hash_table);

  int n_consultas;
  fscanf(input_stream, "%d", &n_consultas);

  for (int i = 0; i < n_consultas; i++){
    int n;
    fscanf(input_stream, "%d", &n);
    fscanf(input_stream, "%d", &value);
    Node* root_2 = create_node(value, 1);
    for (int j = 1; j < n; j++) {
      fscanf(input_stream, "%d", &value);
      insert_node(root_2, value, j+1);
    }

    int hash = hash_function(root_2, heigth_tree(root_2));

    HashItem* h = hash_table[hash];
    LinkList* list = link_list_create(0);

    while (h != NULL){
      if (compare_trees(h->node, h->height, root_2)){
        link_list_append(list, h->node->position);
      }
      h = h->next;
    }

    if (list->next == NULL){
      fprintf(output_stream, "%d", -1);
    } else {
      LinkList* aux = list->next;
      while (aux != NULL){
        fprintf(output_stream, "%d ", aux->value);
        aux = aux->next;
      }
    }
    fprintf(output_stream, "\n");

    free_tree(root_2);
    free_link_list(list);
  }

  // Cerrar archivo de input
  fclose(input_stream);
  
  // Cerrar archivo de output
  fclose(output_stream);

  free_hash_table(hash_table, n_nodes);
  free_tree(root);
  
  return 0;
}
