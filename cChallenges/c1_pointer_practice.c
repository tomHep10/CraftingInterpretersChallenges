#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node *newNode(int new_data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    return new_node;
}

int main(){
    printf("Hello, World!\n");
    return 0;
}

/*
Do the same thing for C. To get some practice
 with pointers, define a doubly linked list of
heap-allocated strings. Write functions to insert,
 find, and delete items from it. Test them.
*/