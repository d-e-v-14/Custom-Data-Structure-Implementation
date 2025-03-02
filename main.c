#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *link;
    
};

void push(struct node *head,int value){
    
    struct node *temp=(struct node*)malloc(sizeof(node));
    
    temp->value=value;
    temp->link=head;
    head=temp;
    printf("\nAdded");
    
}

struct node *pop(struct node *head){
    

    if(head==NULL){
        printf("\nThe list is empty");
    }else{
        struct node *temp=(struct node*)malloc(sizeof(node));
        temp=head;
        head=head->link;
        free(temp);
        printf("\nElement popped");
    
    }
    
    return head;
    
}


int main(){
    
    struct node *head;
    head=(struct node*)malloc(sizeof(node));
    
    head->value=0;
    head->link=NULL;
    
    int val;
    scanf("%d",&val);
    push(head,val);
    
    head=pop(head);
    
    
    
    
}