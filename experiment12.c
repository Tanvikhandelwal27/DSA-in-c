#include<stdio.h>
#define max 5
#define word 9999999
int arr[max][max];
void create()
{
    int i,j;
    printf("enter weights:\n");
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
int minimum(int weight[],int visited[])
{
    int i, min=word,min_index=-1;
    for(i=0;i<max;i++)
    {
        if(visited[i]==0&&weight[i]<min)
        {
            min=weight[i];
            min_index=i;
        }
    }
    return min_index;
}
void display(int weight[])
{
    int i;
    printf("vertex \t distance\n");
    for(i=0;i<max;i++)
    {
        printf("%d \t %d\n",i,weight[i]);
    }
}
void dijkastra(int source)
{
    int i,j,visited[max],weight[max];
    for(i=0;i<max;i++)
    {
       weight[i]=word;
       visited[i]=0;
    }
    weight[source]=0;
    for(i=0;i<max;i++)
    {
        int ele=minimum(weight,visited);
        visited[ele]=1;
        for(j=0;j<max;j++)
        {
            if(visited[j]==0&&arr[ele][j]!=0&&weight[ele]+arr[ele][j]<weight[j])
            {
                weight[j]=arr[ele][j]+weight[ele];
            }

        }
    }
    display(weight);
}
void main()
{
    create();
    int source=0;
    dijkastra(source);
}