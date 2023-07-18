#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  int count;
  struct Node* leftNode;
  struct Node* rightNode;
};

bool canReorderDoubled(int* arr, int arrSize){

  int totalCount = 0;

  struct Node* anode = malloc(sizeof(struct Node));
  anode->value = arr[0];
  anode->leftNode = NULL;
  anode->rightNode = NULL;
  anode->count = 1;
  totalCount++;

  for (int i = 1; i < arrSize; i++) {
    int val = arr[i];

    struct Node* iter = anode;
    
    for (int j = 0; j < 200000 ; j++) {
      if (val == iter->value) {
        iter->count++;
        totalCount++;
        break;
      } else if (val < iter->value) {
        if (iter->leftNode == NULL) {
          struct Node* anewnode = malloc(sizeof(struct Node));
          anewnode->leftNode = NULL;
          anewnode->rightNode = NULL;
          anewnode->value = val;
          anewnode->count = 1;
          iter->leftNode = anewnode;
          totalCount++;
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
          totalCount++;
          break;
        } else iter = iter->rightNode;
      }
    }    
  }
  
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
      
      int currentCount = current->count;
      for (int j = 0; j < currentCount; j++) {
        
        if (current->count == 0) break;
        
        int val = current->value;
        int wait = val*2;

        if (val < 0) {
          if (val % 2 == 0)
            wait = val/2;
          else 
            wait = 201*1000;
        }

        struct Node* iter = anode;              

        for (int j = 0; j < 200000 ; j++) {
          if (wait == iter->value && iter->count > 0) {
            
            if ((iter->count == 1 && iter != current) || iter->count > 1) {
              iter->count--;
              totalCount--;

              current->count--;
              totalCount--;
            }

            break;
            
          } else if (wait < iter->value) {
            if (iter->leftNode == NULL) {
              break;
            } else iter = iter->leftNode;
          } else {
            if (iter->rightNode == NULL) {
              break;
            } else iter = iter->rightNode;
          }
        }   
                
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

  return totalCount == 0;
}

int main() {
  
  // int test[16] = {,2,-6,4,-3,8,3,2,-2,6,1,-3,-4,-4,-8,4};

 int test[4] = {2,1,2,6};

  bool is = canReorderDoubled(&test,4);  
  printf(is ? "YES": "NO");
  return 0;
}
