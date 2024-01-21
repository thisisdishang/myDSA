//Implement following operations on the singly linked list:-
//(a) Insert a node at the front of the linked list.
//(b) Insert a node at the end of the linked list.
//(c) Insert a node such that the linked list is in ascending order.
//(d) Delete the First node of the linked list.
//(e) Delete a node before specified position.
//(f) Delete a node after specified position.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to insert a node in ascending order
void insertInAscendingOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
    } else {
        // Insert in the middle or at the end
        prev->next = newNode;
        newNode->next = current;
    }
}

// Function to delete the first node of the linked list
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position or list is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    for (int i = 1; i < position - 1 && current != NULL; ++i) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Invalid position or list is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;

    for (int i = 1; i <= position && current != NULL; ++i) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert at front
    insertAtFront(&head, 3);
    insertAtFront(&head, 1);
    insertAtFront(&head, 5);

    printf("List after inserting at front: ");
    printList(head);

    // Insert at end
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);

    printf("List after inserting at end: ");
    printList(head);

    // Insert in ascending order
    insertInAscendingOrder(&head, 6);
    insertInAscendingOrder(&head, 2);

    printf("List after inserting in ascending order: ");
    printList(head);

    // Delete first node
    deleteFirstNode(&head);

    printf("List after deleting first node: ");
    printList(head);

    // Delete a node before specified position
    deleteBeforePosition(&head, 4);

    printf("List after deleting a node before position 4: ");
    printList(head);

    // Delete a node after specified position
    deleteAfterPosition(&head, 2);

    printf("List after deleting a node after position 2: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(&head);

    return 0;
}