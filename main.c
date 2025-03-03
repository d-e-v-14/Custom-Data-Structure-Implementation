#include<stdio.h>
#include<stdlib.h>

//structure for node creation

struct node{
    int value;
    struct node *link; 
    int minValue; //updates minimum value 
    int maxValue; //updates the maximum value
};

//Push function: Pushes element x onto the stack.
//Time Complexity: O(1)
struct node *push(struct node *head,int value){
    
    struct node *temp=(struct node*)malloc(sizeof(struct node)); //allocation of memory
    
    temp->value=value; //assigning value to empty structure temp
    temp->link=head;  //temp is an independant node 

    if(head==NULL){  
        temp->minValue = value;
        temp->maxValue = value;
    }else{
        temp->minValue=(head->minValue < value)?head->minValue:value; //updation of minimum value
        temp->maxValue=(head->maxValue > value)?head->maxValue:value; //updation of maximum value
        }

    head=temp; //temp is the new head

    printf("\nAdded");
   
    return head; 
    
}

//Pop function: Removes the top element of the stack
//Time Complexity: O(1)
struct node *pop(struct node *head){
    

    if(head==NULL){
        printf("\nStack is empty"); //if head is empty, returns a stack is empty prompt
    }else{

        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=head; //stores the head->link in a new structure temp
        head=head->link; //assigns the new head as head->link

        free(temp); //frees the temp node for preventing memory leaks
        printf("\nElement popped");
        
        if (head == NULL) //returns null is head is empty after element removal
        return NULL; 
        
        head->maxValue=head->value; //assigns max and min value as value in the new head
        head->minValue=head->value;
        
        struct node *ptr=(struct node*)malloc(sizeof(struct node)); 
        ptr=head; //creates a temporary node for assigning as head
        
        // iterates through the stack to fetch the new min and max values
         while(ptr->link!=NULL){
                if(ptr->value>head->maxValue)
                head->maxValue=ptr->value;
                else if(ptr->value<head->minValue)
                head->minValue=ptr->value;
                
               ptr=ptr->link;
             
         }
        
    }

 
        return head;
    
   
}
//Top functio:  Returns the top element without removing it
//Time Complexity: O(1)
void top(struct node *head){
    //creates a temporary node
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head; //temporary node is assigned as head
    
    if(temp==NULL){
        printf("\nStack is empty"); //returns a prompt if stack is empty
    }else if(temp->link==NULL){
        printf("\nDefault value: 0"); //defaultvalue prestored in stack is 0 (as base value)
    }else{
        printf("\nThe top value is: %d",temp->value); //returns the value of head(top most)
    }
    
}
//Print function: Prints the current stack
//Time Complexity: O(n)
void print(struct node *head){
    
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head; 
    
    if(ptr==NULL){
        printf("\nThe Stack is empty");
    }else if(ptr->link==NULL){
        printf("\nStack only has default value 0");
    }else{
        printf("\n");
        printf("Updated Stack: ");
        while(ptr->link!=NULL){ //runs until link of node is null i.e. last value is reached
            printf("%d ",ptr->value); //prints the value of current node
            ptr=ptr->link; //assigns the ptr to the value of next node which is stored in link of current node
        }
    }
}
//Maximum value function: Returns the largest element in the stack
//Time Complexity: O(1)
void getMax(struct node *head) {
    if(head==NULL){
        printf("\nStack is empty!");
        return;
    }
    printf("\nMax Value is: %d", head->maxValue); //returns the maxValue element from the current head
}

//Minimum value function: Returns the smallest element in the stack
////Time Complexity: O(1)
void getMin(struct node *head) {
    if(head==NULL){
        printf("\nStack is empty!");
        return;
    }
    printf("\nMin Value is: %d", head->minValue);
}

int main(){

    //head is created 
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    
    head->value=0;//default value in head set to 0
    head->link=NULL;//default link set to null i.e. head is the tail
    

    //menu incorporated 
    int menu=0;
            
        printf("\n=====================================");
        printf("\n           STACK OPERATIONS          ");
        printf("\n=====================================");
        printf("\n1. Push a value onto the stack");
        printf("\n2. Pop a value from the top of the stack");
        printf("\n3. Print the top value of the stack");
        printf("\n4. Get the maximum value in the stack");
        printf("\n5. Get the minimum value in the stack");
        printf("\n6. Print the present stack");
        printf("\n7. Exit");
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
    }else if(menu==6){
        print(head);
        menu=0;
    }else if (menu == 7) {
        printf("Exited Successfully!\n"); //ends the while loop if menu == 7
        break;
    } else {
        printf("Invalid entry!\n"); //checks for invalid entries
        printf("Enter your choice: ");
    }
       
    }
   
}