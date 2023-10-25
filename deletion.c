#include<stdio.h>
struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist ll;
ll *start=NULL,*nn,*temp;

void insert(int value){
    if(start == NULL){
        start=(ll*)malloc(sizeof(ll));
        start->data=value;
        start->next=NULL;
        // printf("\nValue has been inserted for the first time");
    }
    else{
        nn=(ll*)malloc(sizeof(ll));
        if(nn!=NULL){
            nn->data=value;
            nn->next=start;
            start=nn;
            // printf("\nValue has been inserted");
        }else{
            printf("Linked list is Full");
        }
    }
}
void deleteatBeg(){

    if(start==NULL){
        printf("Empty");
    return;
    }
    
    temp = start;
    start=start->next;
    free(temp);
}
void deleteatEnd(){
    
    if(start==NULL){
        printf("Empty");
    return;
    }
    ll *secondnode,*lastnode;
    lastnode=start;
    
    while(lastnode->next != NULL){
        secondnode=lastnode;
        lastnode=lastnode->next;
    }
    if(lastnode == start){
        start=NULL;
      
    }else{
        secondnode->next=NULL;
     }
       free(lastnode);
    
}
void deleteatPos(int Pos){
    int i=1;
    temp=start;
    while(i < Pos){
        temp=temp->next;
        i++;    
    }
    deletenode=temp->next;
    temp->next=deletenode->next;
    free(deletenode);
    printf("Value has been deleted from %dth Pos\n",Pos);
}
void display(){
     temp=start;
    if(start==NULL){
        printf("Linked list is empty");
        return;
    }
    while(temp != NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    // if(temp == NULL){
    // printf("NULL");
    // }
}
void main(){
    int ch,value,pos;
    printf("\nPress 1: To Delete value at Beggining");
    printf("\nPress 2: To Delete value at End");
    printf("\nPress 3: To Delete value at Particular Postion");
    printf("\nPress 4: To Display All Values");
    printf("\nPress 5: To Exit the code\n");
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    while(1){
        display();
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        
        switch(ch){
        
        case 1:deleteatBeg();
        break;
        
        case 2:deleteatEnd();
        break;
        
        case 3:
       printf("\nEnter the Position:(as startong from 0) ");
        scanf("%d",&pos);
        deleteatPos(pos);
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
