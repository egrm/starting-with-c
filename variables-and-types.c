#include <stdio.h>

#define bool char
#define false 0
#define true 1

int main() {
  int a = 2;
  float b = 4.5;
  double c = 5.25;

  float sum = a + b + c;

  printf("%f", sum);
  return 0;
}
