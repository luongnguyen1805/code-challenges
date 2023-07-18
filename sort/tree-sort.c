#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  int count;
  struct Node* leftNode;
  struct Node* rightNode;
};

int* sortedArray(int* arr, int arrSize) {

  struct Node* anode = malloc(sizeof(struct Node));
  anode->value = arr[0];
  anode->leftNode = NULL;
  anode->rightNode = NULL;
  anode->count = 1;

  for (int i = 1; i < arrSize; i++) {
    int val = arr[i];

    struct Node* iter = anode;
    
    for (int j = 0; j < 200000 ; j++) {
      if (val == iter->value) {
        iter->count++;
        break;
      } else if (val < iter->value) {
        if (iter->leftNode == NULL) {
          struct Node* anewnode = malloc(sizeof(struct Node));
          anewnode->leftNode = NULL;
          anewnode->rightNode = NULL;
          anewnode->value = val;
          anewnode->count = 1;
          iter->leftNode = anewnode;
          break;
        } else iter = iter->leftNode;
      } else {
        if (iter->rightNode == NULL) {
          struct Node* anewnode = malloc(sizeof(struct Node));
          anewnode->leftNode = NULL;
          anewnode->rightNode = NULL;
          anewnode->value = val;
          anewnode->count = 1;
          iter->rightNode = anewnode;
          break;
        } else iter = iter->rightNode;
      }
    }    
  }
  
  int* results = malloc(sizeof(int)*arrSize);
  int idx = 0;

  struct Node* iter = anode;
  
  struct Node** stack = malloc(arrSize * sizeof(struct Node*));

  int position = 0;
  stack[position] = anode;
  
  for (int i = 0; i < 200000; i++) {
    
    if (iter && iter->leftNode != NULL) {
      position++;
      stack[position] = iter->leftNode;
      iter = iter->leftNode;
    } else {
      
      struct Node* current = stack[position];
      position--;
      
      for (int j = 0; j < current->count; j++) {
        results[idx] = current->value;
        idx++;
      }
      
      iter = NULL;
      if (current->rightNode != NULL) {
        position++;
        stack[position] = current->rightNode;
        iter = current->rightNode;
      }

      if (iter == NULL && position < 0) {
        break;
      }
      
    }
  
  }

  return results;
}

