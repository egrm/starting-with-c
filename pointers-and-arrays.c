#include <stdio.h>
#include <stdlib.h>

int main() {
    // int items[4];
    int *items = (int *)malloc(sizeof(int) * 4);

    int sum = 0;

    for (int i = 0; i < 4; i++) {
        scanf("%d", items + i);
        sum += *(items + i);
    }

    printf("%d\n", sum);

    return 0;
}
