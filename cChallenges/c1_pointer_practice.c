#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

// Creates new node with heap allocated input string
struct Node *newNode(const char * new_data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = (char *)malloc(strlen(new_data)+1);
    strcpy(new_node->data, new_data);

    new_node->next = NULL;
    new_node->prev = NULL;
    
    return new_node;
}

void freeList(struct Node *head){
    struct Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }    
}

int main(){
    // Nodes with heap allocated strings
    struct Node *head = newNode("Hello");
    struct Node *second = newNode("World");
    struct Node *third = newNode("Practice");

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    freeList(head);

    return 0;
}

/*
Do the same thing for C. To get some practice
 with pointers, define a doubly linked list of
heap-allocated strings. Write functions to insert,
 find, and delete items from it. Test them.
*/