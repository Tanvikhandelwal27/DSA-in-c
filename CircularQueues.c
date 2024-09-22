#include<stdio.h>

int queue[5];
int max=5;
int front=-1;
int rear=-1;
void enqueue(int val){
    if ((rear+1)%max==front){
        printf("queue is overflow");
    }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        //printf("\nElement inserted is %d",val);
        queue[rear]=val;
    }
    else{
        rear=((rear+1)%max);
         //printf("\nElement inserted is %d",val);
        queue[rear]=val;
    }
}
int dequeue(){
    int del_ele;
     if(front==-1 && rear==-1){
        printf("queue is underflow");
        return 0;
     }
     if(rear==front){
        del_ele=queue[front];
        front=-1;
        rear=-1;
        printf("\nElement deleted is %d",del_ele);
        return del_ele;
     }
     else{
        del_ele=queue[front];
        front=(front+1)%max;
        printf("\nElement deleted is %d",del_ele);
        return del_ele;
     }
}
void display(){
    int i;
    i=front;
    while(i!=rear){
        printf("%d--->",queue[i]);
        i=(i+1)%max;
    }
    printf("%d\n",queue[rear]);
}

void main(){
    int d;
    enqueue(10);
    display();
    enqueue(20);
    display();
    enqueue(30);
    display();
    enqueue(40);
    display();
    enqueue(50);
    display();
    d=dequeue();
    printf("\nElement deleted is %d",d);
    display();
    enqueue(60);
    display();
    

}