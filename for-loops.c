#include <stdio.h>

int main() {
  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int array_len = sizeof(array) / sizeof(int);

  int factorial = 1;

  for (int i = 0; i < array_len; i++) {
    factorial += factorial * i;
  }

  printf("10! is %d.\n", factorial);

  return 0;
}
