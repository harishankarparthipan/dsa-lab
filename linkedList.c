#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
int size = 0;

void insertBeg();
void insertEnd();
void insertPos();
void deleteEnd();
void deleteBeg();
void deletePos();
void display();

struct node* createNode();

void main(){
    int ch = NULL;
    while(ch!=0){
        printf("1. Insert @ Beginning\n2. Insert @ End\n3.Insert @ Pos\n4. Delete @ End\n");
        printf("5. Delete @ Beginning\n6.Delete @ Pos\n7.Display");
        switch (ch)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertPos();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            deleteBeg();
            break;
        case 6:
            deletePos();
            break;
        case 7:
            display();
            break;
        default:
            printf("Enter the correct option.\n");
            break;
        }
    }
}

void insertBeg(){
    struct node* newNode = createNode();
    struct node* temp = head;
    newNode->next = head;
    head = newNode;
    printf("Element: %d inserted at beginning succesfully!\n",newNode->data);
    size++;
}

void insertEnd(){
    struct node* newNode = createNode();
    if(head==NULL){
        head = newNode;
    } else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = NULL;
    printf("Element: %d inserted at end succesfully!\n",newNode->data);
    size++;
}

void insertPos()
{
    int pos=0;
    printf("Enter Position to Insert: ");
    scanf("%d",&pos);
    if((pos < 0) || (pos > size-1)){
        printf("Invalid position to insert. Position must be less than size\n");
    } 
    else if(pos == 0){
        struct node* newNode = createNode();
        newNode->next = head; 
        head = newNode;
    }
    else {
        struct node* newNode = createNode();
        struct node* temp = head; 
        while(--pos)
            temp=temp->next;
        newNode->next= temp->next;
        temp->next = newNode;
        size++;
    }
}
void display(){
    struct node* temp = head;
    printf("Linked List: ");
    if(temp==NULL){
        printf("Empty List!");
    }else{
        while(temp->next!=NULL){
            printf("%d-->",temp->data);
            temp = temp->next;
        }
        printf("%d \n",temp->data);
    }
}

void deleteEnd(){
    struct node* prevPtr = head;
    struct node* ptr = head;
    while(ptr->next!=NULL){
        prevPtr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    size--;
    if(size==0){
        head = NULL;
    } else{
        prevPtr->next=NULL;
    }
    printf("Last Element deleted\n");
}

void deleteBeg(){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    size--;
    printf("First Element deleted\n");
}

void deletePos(){
    int pos=0;
    printf("Enter Position to delete: ");
    scanf("%d",&pos);
    if((pos < 0) || (pos > size-1)){
        printf("Invalid position to insert. Position must be less than size of list\n");
    } 
    else {
        int counter=0;
        struct node* prevPtr = head;
        struct node* ptr = head;
        if((pos==0)&&(ptr->next!=NULL)){
            head = ptr->next;
        }
        else{
            while(counter!=pos)
            {
                prevPtr = ptr;
                ptr=ptr->next;
                counter++;
            }    
            prevPtr->next = ptr->next;   
        }
        free(ptr);
        size--;
    }
}

struct node* createNode(){
    struct node* newNode = malloc(sizeof(struct node));
    printf("Enter the Integer to insert: ");
    scanf("%d",&newNode->data);
    return newNode;
}