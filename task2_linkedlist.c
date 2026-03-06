#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct node {
    int data;
    struct node *next;
};

// Head pointer of linked list
struct node *head = NULL;

// Function to insert node at beginning
void insert(int value) {

    struct node *newnode;

    // Allocate memory for new node
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;   // store data
    newnode->next = head;    // point to previous head

    head = newnode;          // new node becomes head
}

// Function to delete first node
void deleteNode() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    head = head->next;

    free(temp);

    printf("First node deleted\n");
}

// Function to display linked list
void display() {

    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {

        printf("%d -> ", temp->data);

        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    // Insert elements
    insert(10);
    insert(20);
    insert(30);

    // Display list
    display();

    // Delete first node
    deleteNode();

    // Display again
    display();

    return 0;
}