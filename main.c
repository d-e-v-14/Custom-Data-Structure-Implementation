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
    

    
    int menu=0;
            
        printf("\n=====================================");
        printf("\n           STACK OPERATIONS          ");
        printf("\n=====================================");
        printf("\n1. Push a value onto the stack");
        printf("\n2. Pop a value from the top of the stack");
        printf("\n3. Print the top value of the stack");
        printf("\n4. Get the maximum value in the stack");
        printf("\n5. Get the minimum value in the stack");
        printf("\n6. Exit");
        printf("\n-------------------------------------");
        
    while(menu==0){

        printf("\nEnter your choice: ");

        scanf("%d",&menu);
        
        if (menu == 1) {
        int push_value;
        printf("Enter value to push: ");
        scanf("%d", &push_value);
        
        head = push(head, push_value);
        menu = 0;
    } else if (menu == 2) {
        head = pop(head);
        menu = 0; 
    } else if (menu == 3) {
        top(head);
        menu = 0;      
    } else if (menu == 4) {
        getMax(head);
        menu = 0;        
    } else if (menu == 5) {
        getMin(head);
        menu = 0;
    } else if (menu == 6) {
        printf("Exited Successfully!\n");
        break;
    } else {
        printf("Invalid entry!\n");
        printf("Enter your choice: ");
    }
       
    }
   
}