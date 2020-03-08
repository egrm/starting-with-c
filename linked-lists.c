#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    if (head == NULL) {
        printf("empty linked list");
    }

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

int remove_first(node_t **head) {
    if (*head == NULL) return 0;

    if ((*head)->next == NULL) {
        int val = (*head)->val;
        free(*head);
        *head = NULL;
        return val;
    }

    node_t *new_head = (*head)->next;
    int val = (*head)->val;

    free(*head);

    *head = new_head;

    return val;
}

int remove_last(node_t **head) {
    if (*head == NULL) {
        return 0;
    }

    if ((*head)->next == NULL) {
        int val = (*head)->val;
        free(*head);
        *head = NULL;
        return val;
    }

    node_t *current = (*head);

    while (current->next->next != NULL) {
        current = current->next;
    }

    node_t *last = current->next;

    int val = last->val;

    current->next = NULL;

    free(last);

    return val;
}

int remove_by_index(int index, node_t **head) {
    int current_index = 0;
    node_t *current = *head;

    if (*head == NULL) return 0;

    if ((*head)->next == NULL) {
        int val = (*head)->val;
        *head = NULL;
        return val;
    }

    while (current_index != (index - 1) && current->next->next != NULL) {
        current_index++;
        current = current->next;
    }

    int val = current->next->val;

    free(current->next);

    current->next = current->next->next;

    return val;
}

int main() {
    // 3 -> 2 -> 1
    node_t *head = (node_t *)malloc(sizeof(node_t));

    head->val = 2;

    prepend(&head, 1);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    int last = remove_last(&head);
    printf("last: %d\n", last);

    int first = remove_first(&head);
    printf("first: %d\n", first);

    int removed_by_index = remove_by_index(2, &head);
    printf("removed_by_index: %d\n", removed_by_index);

    removed_by_index = remove_by_index(2, &head);
    printf("removed_by_index: %d\n", removed_by_index);

    removed_by_index = remove_by_index(2, &head);
    printf("removed_by_index: %d\n", removed_by_index);

    print_list(head);

    return 0;
}
