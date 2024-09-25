#include<stdio.h>
#define max 100
#define k 3
int arr[max];
int top[k];
int next[max];
int freespace=0;
void limit()
{
    int i;
    for(i=0;i<k;i++)
    {
        top[i]=-1;
    }
    for(i=0;i<max-1;i++)
    {
        next[i]=i+1;
    }
    next[max-1]=-1;
}
int isfull()
{
    return freespace==-1;
}
int isempty(int em)
{
    return top[em]==-1;
}
void push(int em,int val)
{
    if(isfull())
    {
        printf("overflow\n");
        return;
    }
    int i=freespace;
    freespace=next[i];
    next[i]=top[em];
    top[em]=i;
    arr[i]=val;
}
int pop(int em)
{
    if(isempty(em))
    {
        printf("underflow\n");
        return -1;
    }
    int i=top[em];
    top[em]=next[i];
    next[i]=freespace;
    freespace=i;
    return arr[i];
}
void display(int em)
{
    if(isempty(em))
    {
        printf("underflow\n");
        return ;
    }
    for(int i=top[em];i!=-1;i=next[i])
    {
        printf("%d\n",arr[i]);
    }
    printf("\n");
    
    
}
int main()
{
    limit();
    push(0,20);
    push(0,30);
    push(1,40);
    push(1,50);
    push(2,123);
    push(2,234);
    display(0);
    display(1);
    display(2);
    return 0;
}