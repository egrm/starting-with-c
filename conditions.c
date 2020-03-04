#include <stdio.h>

void guess_number(int guess) {
  int correct_guess = 500;

  if (guess > correct_guess) {
    printf("too large");
  } else if (guess < correct_guess) {
    printf("too small");
  } else {
    printf("correct");
  }
}

int main() {
  guess_number(666);

  return 0;
}
