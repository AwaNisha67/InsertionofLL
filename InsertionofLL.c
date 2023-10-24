#include<stdio.h>
#include <stdlib.h>
struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist ll;
ll *start=NULL,*nn,*temp;

void insertatBeg(int value){
    if(start == NULL){
        start=(ll*)malloc(sizeof(ll));
        start->data=value;
        start->next=NULL;
        printf("\nValue has been inserted for the first time");
    }
    else{
        nn=(ll*)malloc(sizeof(ll));
        if(nn!=NULL){
            nn->data=value;
            nn->next=start;
            start=nn;
            printf("\nValue has been inserted");
        }else{
            printf("Linked list is Full");
        }
    }
}
void insertatEnd(int value){
    temp=start;
    
    nn=(ll*)malloc(sizeof(ll));
    nn->data=value;
    nn->next=NULL;
    
    if(start == NULL){
        start=nn;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=nn;
    printf("\nInsertred at the end");
}
void insertatPos(int value ,int pos){
    int i=1;//it will traverse till the Position where we have to add the value;
    temp=start;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    nn=(ll*)malloc(sizeof(ll));
    nn->data=value;
    nn->next=temp->next;
    temp->next=nn;
    printf("\nInserted at %dth postion",pos);
}
void display(){
    temp=start;
    if(start==NULL){
        printf("Linked list is empty");
        return;
    }
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    // if(temp == NULL){
    // printf("NULL");
    // }
}
void main(){
    int ch,value,pos;
    printf("\nPress 1: To insert value at Beggining");
    printf("\nPress 2: To insert value at End");
    printf("\nPress 3: To insert value at Particular Postion");
    printf("\nPress 4: To Display All Values");
    printf("\nPress 5: To Exit the code");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        
        switch(ch){
        
        case 1:printf("\nInsert value at Beginning");
        printf("\nEnter Value: ");
        scanf("%d",&value);
        insertatBeg(value);
        break;
        
        case 2:printf("\nInsert Value at End");
        printf("\nEnter Value: ");
        scanf("%d",&value);
        insertatEnd(value);
        break;
        
        case 3:printf("\nInsert Value at a particular Position");
        printf("\nEnter Value: ");
        scanf("%d",&value);
        printf("\nEnter the Position: ");
        scanf("%d",&pos);
        insertatPos(value,pos);
        break;
        
        case 4:display();
        break;
        
        case 5:exit(1);
        break;
        
        default:printf("\nInvalid Choice");
        break;
            
        }
        
    }
}