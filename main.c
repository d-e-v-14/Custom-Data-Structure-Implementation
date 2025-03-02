#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *link;
    int minValue;
    int maxValue;
};

struct node *push(struct node *head,int value){
    
    struct node *temp=(struct node*)malloc(sizeof(node));
    
    temp->value=value;
    temp->link=head;
    head=temp;
    printf("\nAdded");
    
    if(temp->link->minValue==NULL){
        temp->minValue=value;
    }else if((temp->link->minValue)>value){
        temp->minValue=value;
    }else{
        temp->minValue = temp->link->minValue;
    }
    
    if(temp->link->maxValue==NULL){
        temp->maxValue=value;
    }else if((temp->link->maxValue)<value){
        temp->maxValue=value;
    }else{
        temp->maxValue = temp->link->maxValue;
    }
    
    printf("Min: %d , Max: %d",temp->minValue,temp->maxValue);

    
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
void getMax(struct node *head){
    struct node *ptr=(struct node*)malloc(sizeof(node));
    ptr=head;
    printf("\nMax Value is: %d",ptr->maxValue);
    
}

void getMin(struct node *head){
    struct node *ptr=(struct node*)malloc(sizeof(node));
    ptr=head;
    printf("\nMin Value is: %d",ptr->minValue);
    
}
int main(){

    
    struct node *head;
    head=(struct node*)malloc(sizeof(node));
    
    head->value=0;
    head->link=NULL;
    

    head=push(head,1);
    head=push(head,2);
    head=push(head,3);
    head=push(head,4);
    head=push(head,1);
    head=push(head,2);
    head=push(head,0);
    
    print(head);
    
    top(head);
    
    print(head);
    
    getMax(head);
    getMin(head);
    
    head=pop(head);
    
    print(head);

    
    
    
}