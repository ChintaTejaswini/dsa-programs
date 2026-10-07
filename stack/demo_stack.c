#include<stdio.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top = -1;
void push(){
    int value;
    if(top==MAXSIZE-1){
        printf("stack overflow\n");
    }else{
        printf("enter the value\n");
        scanf("%d",&value);
        top+=1;
        stack[top]=value;
    }
}

void pop(){
    if(top==-1){
        printf("stack underflow\n");
    }else{
        printf("item deleted is %d\n",stack[top]);
        top-=1;
    }
}

void display(){
    int i;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack elemetns are : \n");
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}

void isFull(){
    if(top==MAXSIZE-1){
        printf("stack overflow\n");
    }
}

void isEmpty(){
    if(top==-1){
        printf("Stack underflow\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("1:push 2:pop 3:display 4:exit\n");
        printf("enter ur choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4:
                    printf("program is exiting\n");
                    return 0;

            default: 
                    printf("invalid choice\n");
                
        }
    }
    return 0;
}

/*
Stack
↓
array + top
↓
top = -1 initially

PUSH:
check full
take value
top++
stack[top] = value

POP:
check empty
use stack[top]
top--

DISPLAY:
check empty
i = top
go down to 0
*/
