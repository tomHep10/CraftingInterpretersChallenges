#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char * data;
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
    struct Node* temp = NULL;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }    
}

void printList(struct Node *head){
    while(head != NULL){
        printf("%s\n", head->data);
        head = head->next;
    }
    printf("\n");
};

struct Node *insert(struct Node *head, struct Node *input, int index){
    struct Node *node = head;
    struct Node *start = head;

    for(int i = 0; i <= index; i++){
        // Case when index is 0
        if (index == 0) {
            input->next = head;
            if (head != NULL) {
                head->prev = input;
            }
            return input;
        }

        // Case for insertion when index is inside the list, not including index=0
        if (i+1 == index){
            struct Node *temp = node->next;
            node->next = input;
            input->prev = node;
            input->next = temp;
            if (temp != NULL){
                temp->prev = input;
            }
            return start;
        }

        //Case where index is out of range
        if (((i+1) != index) && (node->next == NULL)){
            printf("ERROR: Index out of range\n");
            return start;
        }
        
        node = node->next;
    }
    printf("Uncaught error\n");
    return NULL;
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

    printList(head);
    struct Node *new = newNode("It's a brand new");
    head = insert(head, new, 0);
    printList(head);
    freeList(head);

    return 0;
}

/*
Do the same thing for C. To get some practice
 with pointers, define a doubly linked list of
heap-allocated strings. Write functions to insert,
 find, and delete items from it. Test them.
*/