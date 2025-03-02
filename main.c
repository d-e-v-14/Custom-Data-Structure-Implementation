#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *link;
    
};

struct node *push(struct node *head,int value){
    
    struct node *temp=(struct node*)malloc(sizeof(node));
    
    temp->value=value;
    temp->link=head;
    head=temp;
    printf("\nAdded");
    
    return head;
    
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

void top(struct node *head){
    
    struct node *temp=(struct node*)malloc(sizeof(node));
    temp=head;
    
    if(temp==NULL){
        printf("\nStack is empty");
    }else if(temp->link==NULL){
        printf("\nDefault value: 0");
    }else{
        printf("\nThe top value is: %d",temp->value);
    }
    
}

void print(struct node *head){
    
    struct node *ptr=(struct node*)malloc(sizeof(node));
    ptr=head;
    
    if(ptr==NULL){
        printf("\nThe Stack is empty");
    }else if(ptr->link==NULL){
        printf("\nStack only has default value 0");
    }else{
        printf("\n");
        printf("Updated Stack: ");
        while(ptr->link!=NULL){
            printf("%d ",ptr->value);
            ptr=ptr->link;
        }
    }
}
int main(){
    
    struct node *head;
    head=(struct node*)malloc(sizeof(node));
    
    head->value=0;
    head->link=NULL;
    

    head=push(head,1);
    head=push(head,2);
    
    print(head);
    
    top(head);
    
    print(head);
    
    head=pop(head);
    
    print(head);

    
    
    
}