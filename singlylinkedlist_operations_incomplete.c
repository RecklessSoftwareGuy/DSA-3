//Operations on a linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node* next;
};

struct List
{
struct Node* head;
int length;
};

struct List list1 = {NULL, 0};

void InsertAtEnd(struct Node** head, int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if(!newNode)
{
printf("Memory Allocation Failed!");
}
else
{
list1.length++;
newNode->data = data;
newNode->next = NULL;
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
temp->next = newNode;
}
}
}


void CreateList(struct Node** head)
{
int n;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter Elements of the linked list (Enter any alphabet to end): ");
int num;
while(n>0)
{
scanf("%d", &num);
InsertAtEnd(head, num);
n--;
}
printf("\nLinked List Created Successfully!: ");
}

void display(struct Node* head)
{
if(head==NULL)
{
printf("\nLinked list is empty");
}
else
{
struct Node* temp = head;
while(temp!=NULL)
{
printf("%d ", temp->data);
temp=temp->next;
}
}
printf("\n");
}

void FreeList(struct Node** head)
{
if(*head==NULL)
{
continue;
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
*head = NULL;
list1.length = 0;
printf("\nDeleted Linked List\n");
}
}

void SearchList(struct Node* head)
{
int key; int found = 0; int atNode = 0;
struct Node* temp = head;
printf("Enter Element to be searched: ");
scanf("%d", &key);
while(temp!=NULL)
{
atNode++;
if(key==temp->data)
{
found++;
break;
}
temp=temp->next;
}
if(found)
{
printf("Found at %d Node", atNode);
}
else
{
printf("Not Found!");
}
}

void SwapElements(struct List list, int pos1, int pos2)
{
if(list.head==NULL)
{
printf("Linked List is empty\n");
}
else
{
if(pos1 != pos2)
{
if((pos1>0 && pos1<=list.length)&&(pos2>0 && pos2<=list.length))
{
struct Node* node1 = list.head, node2 = list.head;
while(pos1!=0)
{
node1 = node1->next;
pos1--;
}
while(pos2!=0)
{
node2 = node2->next;
pos2--;
}
}
else
{
printf("Invalid Positions");
}
}
}
}

int main()
{
int ch;
printf("1. Create A linked list\n2. Search for elements in a linked list\n3. Display linked list\n4. Delete List\nX. Exit\nEnter Selection: ");
while(scanf("%d", &ch)==1)
{
switch(ch)
{
case 1:
CreateList(&list1.head);
printf("\n\nEnter Selection: ");
break;
case 2:
SearchList(list1.head);
printf("\n\nEnter Selection: ");
break;
case 3:
display(list1.head);
printf("\n\nEnter Selection: ");
break;
case 4:
FreeList(&list1.head);
printf("\n\nEnter Selection: ");
}
}
FreeList(&list1.head);
}
