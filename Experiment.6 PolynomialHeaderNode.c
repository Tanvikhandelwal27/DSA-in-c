#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int exp;
    struct Node* next;

};
struct Node* createHeaderNode(){
    struct Node* header=(struct Node*)malloc(sizeof(struct Node));
    if(!header){
        printf("Not Defined");
    }
    header->coeff=0;
    header->exp=-1;
    header->next=NULL;
    return header;

}
void insert(struct Node* header,int coeff, int exp){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;

     struct Node* current = header;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void display(struct Node*result){
    while(result!=NULL){
        printf("%dx^%d ",result->coeff,result->exp);
        result=result->next;
    }
   
}
void addPolynomial(struct Node*p1,struct Node*p2){
    struct Node* temp1=p1->next;
    struct Node* temp2=p2->next;
    struct Node*result=createHeaderNode();
        while(temp1!=NULL&&temp2!=NULL){
      if(temp1->exp > temp2->exp)
      {
        insert(result,temp1->coeff,temp1->exp);
        temp1=temp1->next;

      }
      else if(temp2->exp > temp1->exp){
        insert(result,temp2->coeff,temp2->exp);
        temp2=temp2->next;
      }
      else{
        int sumcoeff=temp1->coeff+temp2->coeff;
        if(sumcoeff!=0){
            insert(result,sumcoeff,temp1->exp);
        }
        temp1=temp1->next;
        temp2=temp2->next;
      }
    }

    while (temp1 != NULL) {
        insert(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insert(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
      display(result);
}

int main(){
    struct Node* p1=createHeaderNode();
     struct Node* p2=createHeaderNode();
     printf("\nFOR POLYNOMIAL-1");
     insert(p1,4,3);
     insert(p1,3,2);
     insert(p1,2,1);
     insert(p1,4,0);

     printf("\nFOR POLYNOMIAL-2\n");
     insert(p2,6,3);
     insert(p2,5,2);
     insert(p2,1,1);
     insert(p2,7,0);
     addPolynomial(p1,p2);
     return 0;

}
