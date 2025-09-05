#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
int data;
struct Node* next;
} Node;

Node* head1 = NULL;
Node* head2 = NULL;
Node* head3 = NULL;

void InsertAtEnd(Node** head, int data)
{
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->next = NULL;
if(*head==NULL)
{
*head = newNode;
}
else
{
Node* temp = *head;
while(temp->next!=NULL)
{
temp = temp->next;
}
temp->next = newNode;
}
}

void MergeSort(Node* head1, Node* head2, Node** SortedList)
{
Node* current1 = head1;
Node* current2 = head2;
Node* prev;
if(current1==NULL || current2==NULL)
{
printf("List is empty");
}
else
{
if(current1->data <= current2->data)
{
*SortedList = current1;
prev = current1;
current1 = current1->next;
}
else
{
*SortedList = current2;
prev = current2;
current2 = current2->next;
}
while(current1!=NULL && current2!=NULL)
{
if(current1->data < current2->data)
{
prev->next = current1;
prev = current1;
current1 = current1->next;
}
else
{
prev->next = current2;
prev = current2;
current2 = current2->next;
}
}
if(current1!=NULL)
{
prev->next = current1;
}
else
{
prev->next = current2;
}
}
}

void display(Node* head)
{
if(head==NULL)
{
printf("List is empty");
}
else
{
Node* temp = head;
while(temp!=NULL)
{
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}

void freeList(Node** head)
{
Node* current = *head;
Node* prev;
while(current->next!=NULL)
{
prev = current;
current = current->next;
free(prev);
}
}

int main()
{
int n1, n2, data;
printf("Enter Size of first linked list: ");
scanf("%d", &n1);
printf("Enter elements of first linked list: ");
for(int i=0; i<n1; i++)
{
scanf("%d", &data);
InsertAtEnd(&head1, data);
}
printf("Enter Size of second linked list: ");
scanf("%d", &n2);
printf("Enter elements of second linked list: ");
for(int i=0; i<n2; i++)
{
scanf("%d", &data);
InsertAtEnd(&head2, data);
}
display(head1);
display(head2);
MergeSort(head1, head2, &head3);
display(head3);
freeList(&head3);
}
