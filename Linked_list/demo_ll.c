#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head = NULL;

Node *getNode(int value){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void insertAtFront(int value){
    Node *newNode;
    newNode = getNode(value);
    newNode -> next = head;
    head = newNode;
}

void insertAtEnd(int value){
    Node *newNode, *cur;
    newNode = getNode(value);
    if(head==NULL){
        head = newNode;
        return;
    }
    cur = head;
    while(cur->next!=NULL){
        cur = cur -> next;
    }
    cur -> next = newNode;
    return;
}

void insertAtPos(int value, int pos){
    int i;
    Node *newNode, *cur, *prev;

    if(pos==1){
        insertAtFront(value);
        return;
    }
    newNode = getNode(value);
    cur = head;
    prev = NULL;
    for(i=1;i<pos && cur!=NULL;i++){
        prev = cur;
        cur = cur->next;
    }if(i!=pos){
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode -> next = cur;
    prev -> next = newNode;
}

void deleteFront(){
    Node *cur;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    cur = head;
    head = head -> next;
    free(cur);
}

void deleteEnd(){
    Node *cur, *prev;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    prev=NULL;
    cur=head;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
}


void deleteAtPos(int pos){
    Node *prev, *cur;
    int i;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(pos==1){
        deleteFront();
        return;
    }
    prev = NULL;
    cur = head;
    for(i=1;i<pos && cur!=NULL;i++){
        prev = cur;
        cur = cur -> next;
    }
    if(cur==NULL || i!=pos){
        printf("Invalid position\n");
        return;
    }
    prev -> next = cur -> next;
    free(cur);
}


void display(){
    Node *cur;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    cur = head;
    printf("Linked list\n");
    while(cur!=NULL){
        printf("%d -> ",cur->data);
        cur = cur -> next;
    }
    printf("NULL\n");
}

int main(){
    int choice, value, pos;
    while(1){
        printf("1. Insert at front\n2. Insert at end\n3. Insert at pos\n4. Delete at front\n5. Delete at end\n6. Delete at pos\n7. Display\n8. Exit\n");
        printf("enter choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter value:\n");
                scanf("%d",&value);
                insertAtFront(value);
                break;

            case 2:
                printf("Enter value:\n");
                scanf("%d",&value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value:\n");
                scanf("%d",&value);
                printf("Enter position: \n");
                scanf("%d",&pos);
                insertAtPos(value,pos);
                break;
            
            case 4:
                deleteFront();
                break;
            
            case 5:
                deleteEnd();
                break;

            case 6:
                printf("enter position: \n");
                scanf("%d",&pos);
                deleteAtPos(pos);
                break;

            case 7:
                display();
                break;
            
            case 8:
                exit(0);
            
            default:
                printf("Invalid choice\n");
        }
        
    }
    return 0;
}



