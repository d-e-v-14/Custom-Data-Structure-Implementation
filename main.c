#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *link;
    
};

void push(struct node *tail,int value){
    
    struct node *temp=(struct node*)malloc(sizeof(node));
    
    temp->value=value;
    temp->link=tail;
    tail=temp;
    printf("added");
    
}

int main(){
    
    struct node *tail;
    tail=(struct node*)malloc(sizeof(node));
    
    tail->value=0;
    tail->link=NULL;
    
    int val;
    scanf("%d",&val);
    push(tail,val);
    
    
    
    
}