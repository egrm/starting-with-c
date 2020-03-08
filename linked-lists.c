#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void append(node_t *head, int val) {
    node_t *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t *)malloc(sizeof(node_t));

    current->next->val = val;
    current->next->next = NULL;
}

void prepend(node_t **head, int val) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void pop(node_t **head) {
    node_t *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

int main() {
    // 3 -> 2 -> 1
    node_t *head = (node_t *)malloc(sizeof(node_t));

    head->val = 2;

    append(head, 1);
    prepend(&head, 3);

    print_list(head);

    return 0;
}
