#include <stdio.h>
#define N 5
int queue[N];
int rear = -1, front = -1;
int size=N;
void enqueue(int val){
    if(rear==size-1)
    {
    printf("\nQueue is overflow");
    }
    else{
        rear=rear+1;
        queue[rear]=val;
    }
    if(front==-1){
        front=0;
    }
}
int dequeue(){
    if (front==-1||front>rear){
        printf("\nQueue is underflow");
    }
    else{
        int ele=queue[front];
        front=front+1;
        return ele;
    }
}
void display(){
    int i;
    i=front;
    while(i!=rear){
        printf("%d--->",queue[i]);
        i=(i+1);
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
    printf("\nElement deleted is %d\nQueue is:",d);
    display();
   
}
