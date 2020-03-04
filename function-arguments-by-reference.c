#include <stdio.h>

typedef struct {
    char * name;
    int age;
} person;

void birthday(person * p) {
    (*p).age++;
}

void print_person(person p) {
    printf("%s is %d years old\n", p.name, p.age);
}

int main() {
    person john;
    john.name = "John";
    john.age  = 30;

    print_person(john);

    birthday(&john);

    print_person(john);


    return 0;
}
