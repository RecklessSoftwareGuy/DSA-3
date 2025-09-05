#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
struct Node* prev;
int data;
struct Node* next;
} Node;

Node* head1 = NULL;
Node* head2 = NULL;

void InsertAtBeg(Node** head, int data)
{
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->prev = NULL;
newNode->data = data;
if(*head==NULL)
{
*head = newNode;
newNode->next = NULL;
}
else
{
newNode->next = *head;
*head = newNode;
}
}

void InsertAtEnd(Node** head, int data)
{
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->next = NULL;
newNode->data = data;
if(*head==NULL)
{
*head = newNode;
newNode->next = NULL;
}
else
{
Node* temp = *head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newNode;
newNode->prev = temp;
}
}

int NodeCount(Node* head)
{
Node* temp = head;
int count=0;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
return count;
}

void InsertAtPos(Node** head, int pos, int data)
{
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
int count = NodeCount(*head);
if(pos<=count && pos>=0)
{
if(pos==0)
{
InsertAtBeg(head, data);
}
else if(pos==count)
{
InsertAtEnd(head, data);
}
else
{
Node* temp = *head;
Node* next;
for(int i=1; i<pos; i++)
{
temp=temp->next;
next = temp->next;
}
temp->next=newNode;
next->prev=newNode;
newNode->prev=temp;
newNode->next=next;
}
}
else
{
printf("Invalid Position");
}
}

void display(Node* head)
{
if(head==NULL)
{
printf("Linked List is empty!");
}
else
{
Node* temp = head;
while(temp!=NULL)
{
printf("%d ", temp->data);
temp=temp->next;
}
}
printf("\n");
}

int main()
{
int n, data;
printf("Enter size of linked list: ");
scanf("%d", &n);
for(int i=0; i<n; i++)
{
scanf("%d", &data);
InsertAtBeg(&head1, data);
InsertAtEnd(&head2, data);
}
display(head1);
display(head2);
printf("Inserting 2 at pos 2: ");
InsertAtPos(&head1, 2, 2);
display(head1);
return 0;
}
