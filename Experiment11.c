#include<stdio.h>
int missing(int arr[],int n)
{
    int curr=0,acc,i;
    acc=n*(n+1)/2;
    for(i=0;i<n;i++)
    {
        curr+=arr[i];
    }
    int res=acc-curr;
    return res;

}
void main()
{
    int arr[]={0,1,2,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d is missing",missing(arr,n));
}