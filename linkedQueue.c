#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* createNode(){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Memary making failed");
        return NULL;
    }
    return ptr;
}
struct node* enQueue(struct node *head,int value){
    struct node *ptr=head;
    if(head==NULL){
        head=createNode();
        head->data=value;
        head->link=NULL;
    }
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=createNode();
        ptr->link->link=NULL;
        ptr->link->data=value;
    }
    return head;
}
struct node *deQueue(struct node *head){
    struct node *ptr=head;
    if(head==NULL)
        printf("Queue is Underflow\n");
    else{
        head=head->link;
        printf("You remove %d \n",ptr->data);
        free(ptr);
        ptr=NULL;
    }
    return head;
}
void view(struct node *head){
    struct node *ptr=head;
    if(head==NULL)
        printf("Quele is Empty\n");
    else {
        printf("\nQueue\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}
void main(){
    struct node *head=NULL;
    int dis,value;
    do{
        printf("1-ENDQUE\n2-DEQUEUE\n3-VIEW\nENTER : ");
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter value : ");
                    scanf("%d",&value);
                    head=enQueue(head,value);
                    break;
            case 2:head=deQueue(head);
                    break;
            case 3:view(head);
            case 4:break;
            default:printf("Wrong input\n");
        }
    }while(dis!=4);
}