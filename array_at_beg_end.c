#include<stdio.h>
void main()
{
    int i,size,item,pos;
    printf("Enter size of array:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements which you want in your array:");
    for(i=0;i<size;i++)
    {
      scanf("%d",&arr[i]);  
    }
    printf("Enter number at starting:");
    scanf("%d",&item);
    for(i=size;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    
    arr[0]=item;
    size++;
    printf("Enter number at ending:");
    scanf("%d",&item);
    size++;
    arr[size-1]=item;
    printf("Enter other position at which you want to add number:");
    scanf("%d",&pos);
    printf("Enter number at other position:");
    scanf("%d",&item);
    for(i=size-i;i>pos-1;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=item;
    size++;
    printf("Elements in array are :");
    for(i=0;i<size;i++)
    {
      printf("%d\n",arr[i]);
    }
}