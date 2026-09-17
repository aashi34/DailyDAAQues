/* Question 16:
  Write a program to detect a cycle in a linked list. Use Floyd's Cycle Detection Algorithm (Two Pointers).
  Time Complexity: O(n)
  Space Complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    // Create nodes
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    struct Node *fourth = malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;

    // Create a cycle: 4 -> 2
    fourth->next = second;

    struct Node *slow = head;
    struct Node *fast = head;

    // Floyd's Cycle Detection
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;          // Move one step
        fast = fast->next->next;    // Move two steps

        if (slow == fast) {
            printf("Cycle detected");
            return 0;
        }
    }

    printf("No cycle detected");

    return 0;
}
