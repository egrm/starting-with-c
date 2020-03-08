#include <stdio.h>
#include <stdlib.h>

void display_pointers(int *pa, int *pb) {
    printf("*pa == %d, *pb == %d\n", *pa, *pb);
    printf("*pa => %p, *pb => %p\n", pa, pb);
}

void value_swap(int *pa, int *pb) {
    int *temp = (int *)malloc(sizeof(int));
    *temp = *pa;

    *pa = *pb;
    *pb = *temp;

    free(temp);
}

void pointer_swap(int **pa, int **pb) {
    int *temp = malloc(sizeof(*int));

    temp = *pa;

    *pa = *pb;
    *pb = temp;

    free(*temp);
}

int main() {
    int a = 1, b = 2;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf("start:\n");
    display_pointers(pa, pb);
    printf("\n");

    value_swap(pa, pb);

    printf("post value swap:\n");
    display_pointers(pa, pb);
    printf("\n");

    pointer_swap(&pa, &pb);

    // swap values back
    value_swap(pa, pb);

    printf("post pointer swap:\n");
    display_pointers(pa, pb);
    printf("\n");

    return 0;
}
