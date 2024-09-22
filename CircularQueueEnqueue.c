#include<stdio.h>
#define max 5
int queue[5];
int front=-1;
int rear=-1;
void enqueue(int val){
    if((rear+1)%max==front){
        printf("queue is overflow\n");
    }
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=val;

    }
    else{
        rear=(rear+1)%max;
        queue[rear]=val;

    }
}
void display(){
    printf("elements in queue are:");
    for(int i=0;i<max;i++){
        printf("%d\n",queue[i]);
    }
}
void main(){
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
    enqueue(50);
   enqueue(60);
    enqueue(70);
   display();
}