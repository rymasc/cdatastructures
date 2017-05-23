#include <stdio.h>
#include <stdlib.h>

int *A, *B, *C, *D;

void pointerTest1() {
  A = (int*)malloc(sizeof(int));
  B = (int*)malloc(sizeof(int));
  *A = 19;
  *B = 5;
  A = B;
  *B = 7;
  printf("Pointer Test 1 *A = %d\n", *A);
}

void pointerTest2(){
  C = (int*)malloc(sizeof(int));
  D = (int*)malloc(sizeof(int));
  *C = 19;
  *D = 5;
  *C = *D;
  *D = 7;
  printf("Pointer Test 1 *C = %d\n", *C);
}

int main(){
  pointerTest1();
  pointerTest2();
  // free(A);
  // free(B);
  // free(C);
  // free(D);
  //Test
  int* testptr = NULL;
  int ans = *testptr; //causes seg fault
  return 0;
}
