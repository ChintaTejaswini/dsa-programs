#include<stdio.h>
#define QUEUESIZE 5
int queue[QUEUESIZE];
int rear = -1;
int front = 0;
void enqueue(){
    int value;
    if(rear==QUEUESIZE-1){
        printf("queue overflow\n");
    }else{
        printf("enter the value: \n");
        scanf("%d",&value);
        rear+=1;
        queue[rear]=value;
    }
}

void dequeue(){
    if(rear<front){
        printf("queue underflow\n");
    }else{
        printf("the deleted item is %d\n",queue[front]);
        front+=1;
    }
    if(rear<front){
        rear=-1;
        front=0;
    }
}

void display(){
    int i;
    if(rear<front){
        printf("queue is empty\n");
    }else{
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

void isEmpty(){
    if(rear<front){
        printf("queue underflow\n");
    }
}

void isFull(){
    if(rear==QUEUESIZE-1){
        printf("queue overflow\n");
    }
}


int main(){
    int choice;
    while(1){
        printf("1:push(enqueue) 2:pop(dequeue) 3:display 4:exit\n");
        printf("enter ur choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
                    break;

            case 2: dequeue();
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
