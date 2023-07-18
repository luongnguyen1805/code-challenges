#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MAX   2147483647
#define INT_MIN   2147483648

struct Divisor {
  long value;
  long deltaQ;
};

struct DivideResult {
  long q;
  long r;
};

struct Node {
  struct Divisor* divisor;
  struct DivideResult* result;
  struct Node* next;
  struct Node* prev;
};

struct DivideResult* divide_unsigned(long dividend, struct Divisor* divisor) {

  struct DivideResult* result = malloc(sizeof(struct DivideResult));

  result->q = 0;
  result->r = 0;

  result->r = dividend;
  while (result->r >= divisor->value) {
    result->r = result->r - divisor->value;
    result->q += divisor->deltaQ;
  }
  
  return result;
} 

struct Node* buildDivisorList(long dividend, long divisor) {

  struct Node* root = malloc(sizeof(struct Node));
  root->divisor = NULL;
  root->result = NULL;
  root->prev = NULL;
  root->next = NULL;

  struct Node* anode = malloc(sizeof(struct Node));
  anode->divisor = malloc(sizeof(struct Divisor));
  anode->divisor->deltaQ = 1;
  anode->divisor->value = divisor;
  anode->result = NULL;
  anode->next = NULL;
  anode->prev = NULL;  

  root->next = anode;
  anode->prev = root;

  struct Node* iter = anode;
  long nextQ = 1;
  long nextD = divisor;

  for (int i = 0; i < 1000; i++) {

    if (nextD > dividend) {
      break;
    }

    struct Node* anode = malloc(sizeof(struct Node));
    anode->divisor = malloc(sizeof(struct Divisor));
    anode->result = NULL;
    anode->next = NULL;
    anode->prev = NULL;

    iter->next = anode;
    anode->prev = iter;

    long v = 0;
    anode->divisor->value = 0;
    for (int j = 0; j < 10; j++) {
      anode->divisor->value += nextD;
      v += nextQ;
    }

    anode->divisor->deltaQ = v;

    nextQ = v;
    nextD = anode->divisor->value;
    iter = anode;
  }

  root->prev = iter;

  return root;
}

int divide(int dividend, int divisor){

  int negSign = 0;
  long udividend = dividend;
  if (udividend < 0) {
    udividend = -udividend;
    negSign++;
  }
  long udivisor = divisor;
  if (udivisor < 0) {
    udivisor = -udivisor;
    negSign++;
  }
  
  struct Node* root = buildDivisorList(udividend, udivisor);

  struct Node* iter = root->prev;

  long q = 0;
  long r = udividend;
  while (iter->divisor != NULL) {    
    struct DivideResult* res = divide_unsigned(r, iter->divisor);
    iter->result = res;
    if (res != NULL) {
      r = res->r;
      q += res->q;
    }
    iter = iter->prev;
  }

  long actualq = negSign == 1 ? -q : q;

  if (actualq > INT_MAX) actualq = INT_MAX;

  return actualq;
}

int main() {

  int result = divide(2147483647,2645);
  printf("%d",result);

  return 0;
}