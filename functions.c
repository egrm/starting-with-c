#include <stdio.h>

void print_big(int a) {
    if (a > 10) printf("%d", a);
}

int main() {
    print_big(12);

    return 0;
}
