//Program to create and perform operations on a singly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node* next;
};

struct Node* head = NULL;

void InsertAtBeg(struct Node** head, int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if(!newNode)
{
printf("Memory Allocation Failed!");
}
else
{
newNode->data=data;
if(*head==NULL)
{
*head=newNode;
newNode->next=NULL;
}
else
{
newNode->next=*head;
*head=newNode;
}
}
}

void InsertAtEnd(struct Node** head, int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if(!newNode)
{
printf("Memory Allocation Failed!");
}
else
{
newNode->data=data;
newNode->next=NULL;
if(*head==NULL)
{
*head=newNode;
}
else
{
struct Node* temp = *head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newNode;
}
}
}

int LengthOfLinkedList(struct Node** head)
{
if(*head==NULL)
{
return 0;
}
else
{
struct Node* temp = *head;
int count = 0;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
return count;
}
}

void InsertAtPos(struct Node** head, int data, int pos)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if(!newNode)
{
printf("Memory Allocation Failed!");
}
else
{
newNode->data=data;
newNode->next=NULL;
int len = LengthOfLinkedList(head);
if(pos==0)
{
InsertAtBeg(head, data);
}
else if(pos==len)
{
InsertAtEnd(head, data);
}
else if(pos>0 && pos<len)
{
int i=1;
struct Node* temp= *head;
struct Node* prev;
while(pos!=i)
{
prev = temp;
temp=temp->next;
i++;
}
prev->next=newNode;
newNode->next=temp;
}
else
{
free(newNode);
printf("Invalid Position");
}
}
}

void DeleteAtBeg(struct Node** head)
{
if(*head==NULL)
{
printf("Linked List is empty");
}
else
{
struct Node* current = *head;
*head = current->next;
free(current);
printf("Deleted First element of the linked list: ");
}
}

void DeleteAtEnd(struct Node** head)
{
if(*head==NULL)
{
printf("Linked list is empty");
}
else
{
struct Node* temp = *head;
struct Node* prev = NULL;
while(temp->next!=NULL)
{
prev = temp;
temp=temp->next;
}
if(prev==NULL)
{
*head=NULL;
}
else
{
prev->next=NULL;
}
free(temp);
printf("Deleted Last Element of the linked list: ");
}
}

void DeleteAtPos(struct Node** head, int pos)
{
if(*head==NULL)
{
printf("Linked list is empty");
}
else
{
int len = LengthOfLinkedList(head);
if(pos==1)
{
struct Node* current = *head;
*head = current->next;
free(current);
}
else if(pos==len)
{
struct Node* temp = *head;
struct Node* prev;
while(temp->next!=NULL)
{
prev = temp;
temp=temp->next;
}
if(prev==NULL)
{
*head=NULL;
}
else
{
prev->next=NULL;
}
}
else if(pos>1 && pos<len)
{
struct Node* temp = *head;
struct Node* prev;
int i=1;
while(pos!=i)
{
prev = temp;
temp=temp->next;
i++;
}
prev->next=temp->next;
free(temp);
}
else
{
printf("Invalid Position");
}
}
}

void DeleteList(struct Node** head)
{
if(*head==NULL)
{
printf("Linked List is empty");
}
else
{
struct Node* current = *head;
struct Node* prev;
while(current!=NULL)
{
prev = current;
current = current->next;
free(prev);
}
*head=NULL;
}
}

void display(struct Node** head)
{
if(*head==NULL)
{
printf("Linked List is empty");
}
else
{
struct Node* temp = *head;
while(temp!=NULL)
{
printf("%d ", temp->data);
temp=temp->next;
}
}
}

int main()
{
printf("Creating a linked list by entering at the beginning: ");
for(int i=1;i<=10; i++)
{
InsertAtBeg(&head, i);
}
display(&head);
DeleteList(&head);
printf("\nCreating a linked list by entering at the end: ");
for(int i=1; i<=10; i++)
{
InsertAtEnd(&head, i);
}
display(&head);
printf("\nInserting element 99 as 5th node: ");
InsertAtPos(&head, 99, 5);
display(&head);
printf("\nDeleting First Element: ");
DeleteAtBeg(&head);
display(&head);
printf("\nDeleting Last element: ");
DeleteAtEnd(&head);
display(&head);
printf("\nDeleting 4th node: ");
DeleteAtPos(&head,4);
display(&head);
DeleteList(&head);
printf("\n");
}
