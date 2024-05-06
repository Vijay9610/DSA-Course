#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node{
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int val, int index){
    // Node creation
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;

    if(!temp){
        printf("Node not created!");
        return;
    }

    if(*head == NULL){
        *head = temp;
        return;
    }

    struct Node* current = *head;
    //* Insert at start
    if(index == 0){
        temp->next = *head;
        *head = temp;
    }

    //* Insertion at the end
    else if(index == -1){
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }

    //* Insertion at any position
    else{
        for(int i=1; i<index; i++){
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void deleteNode(struct Node** head, int index){
    //* Delete from start
    if(index == 0){
        struct Node* current = *head;
        current = current->next;
        *head = current;
    }

    //* Delete from the end
    else if(index == -1){
        struct Node* current = *head;
        while(current->next->next != NULL){
            current = current->next;
        }
        current->next = NULL;
    }

    //* Delete from any index
    else{
        struct Node* current = *head;
        for(int i=1; i<index; i++){
            current = current->next;
        }

        current->next = current->next->next;
    }
}

void printList(struct Node* head){
    struct Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 0);
    insertNode(&head, 3, -1);
    insertNode(&head, 4, -1);
    printList(head);

    insertNode(&head, 5, 2);
    printList(head);
    insertNode(&head, 6, 2);
    printList(head);

    deleteNode(&head, 0);
    printList(head);
    deleteNode(&head, -1);
    printList(head);

    deleteNode(&head, 2);
    printList(head);

    return 0;
}