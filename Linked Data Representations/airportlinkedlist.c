#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char AirportCode[4];

typedef struct NodeTag{
  AirportCode Airport;
  struct NodeTag *Link;
}Node;

Node *N, *L;

void InsertNewSecondNode(){
  Node *N;
  N = (Node*)malloc(sizeof(Node));
  strcpy(N->Airport, "BRU");
  N->Link = L->Link;
  L->Link = N;
}

Node* ListSearch(char *A, Node *L){
  N = L;
  while (N!= NULL){
    if(strcmp(N->Airport,A) == 0){
      return N;
    } else {
      N = N-> Link;
    }
  }
  return N;
}

void DeleteLastNode(Node **L) {
  Node *PreviousNode, *CurrentNode;

  if(*L!= NULL){
    if((*L)->Link == NULL){
      free(*L);
      *L = NULL;
    } else{
      PreviousNode = *L;
      CurrentNode = (*L)->Link;

      while (CurrentNode -> Link != NULL) {
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->Link;
        PreviousNode->Link = NULL;
        free(CurrentNode);
      }
    }
  }
}

void InsertNewLastNode(char *A, Node **L){
  Node *N, *P;
  N = (Node*)malloc(sizeof(Node));
  strcpy(N->Airport, A);
  N->Link = NULL;

  if(*L == NULL){
    *L = N;
  } else{
    P = *L;
    while(P->Link != NULL){
      P = P->Link;
    }
    P->Link = N;
  }
}

void PrintList(Node *L){
  Node *N;
  printf("(");
  N = L;
  while(N != NULL){
    printf("%s", N->Airport);
    N = N->Link;
    if(N != NULL){
      printf(", ");
    }
  }
  printf(")\n");
}


int main(){
  L = NULL;
  InsertNewLastNode("DUS", &L);
  InsertNewLastNode("ORD", &L);
  InsertNewLastNode("SAN", &L);
  PrintList(L);
  InsertNewSecondNode();
  PrintList(L);
  DeleteLastNode(&L);
  PrintList(L);
  return 0;
}
