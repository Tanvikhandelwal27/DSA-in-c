#include<stdio.h>
#define Max 5
int arr[Max][Max]={0};
void Create(){
    int i,j,temp;
    printf("Enter values");
    for(i=0;i<Max;i++){
        for(j=0;j<Max;j++){
            scanf("%d",&temp);
            arr[i][j]=temp;

        }

    }
}
void BFS(int s){
    int front=-1;
    int rear=-1;
     int q[Max];
   int visited[Max]={0};
   q[++rear]=s;
   visited[s]=1;
   while(front<rear){
    front++;
    int curr=q[front];
    printf("%d",curr);
    for(int i=0;i<Max;i++){
        if(arr[curr][i]==1&&visited[i]!=1){
            q[++rear]=i;
            visited[i]=1;

        }
    }
   }
   printf("\n");

}
void display(){
    int i,j;
    for(i=0;i<Max;i++){
        for(j=0;j<Max;j++){
            printf("%d ",arr[i][j]);

        }
        printf("\n");
    }
}

int main(){
    Create();
    BFS(5);
    display();
    return 0;

}
