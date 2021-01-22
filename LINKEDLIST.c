#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * link;
}node;
node* head = NULL;
void insertLL(int data1){
    if(head==NULL){
    node * new=(node *)malloc (sizeof(node));
    new->data=data1;
    new->link=head;
    head=new;}
    else{
        node *temp=head;
        node * new=(node *)malloc (sizeof(node));
        new->data=data1;
        new->link=NULL;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=new;
    }
}
void deleteLL(){
    node * temp = head->link;
    free(head);
    head= temp;
    
}
int searchLL(int data2){
    node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(temp->data==data2){
            printf("Yes item %d is present at %d position\n",data2,count);
            return count;
        }
        else{
            temp=temp->link;
        }
    }
    printf("Searched item %d is not present\n",data2);
}
int main(){
    
    insertLL(10);
    insertLL(20);
    insertLL(30);
    deleteLL();
    insertLL(40);
    insertLL(50);
    insertLL(60);
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
    searchLL(20);
    searchLL(50);
    searchLL(70);
    
}