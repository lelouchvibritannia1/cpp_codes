#include<stdio.h>
#include<conio.h>
// creation of singly linked list
struct node
{
   int data;
   struct node *next;
}*new,*head,*tail,*temp;

do
{
   new=(struct node *)malloc(sizeof(struct node));
   scanf("%d",&value);
   new->data=value;
   new->next=NULL;
   if(head==NULL)
   {
     head=new;
     tail=new;
   }
   else
   {
      tail->next= new;
      tail=new;
   }
   printf("Y-Continue,N-Exit");
   scanf("%c",&ch);
}while(ch='Y');
/* Display singly linked list */

temp=head;
while(temp!=NULL)
{
   printf("%d",temp->data);
   temp=temp->next; // next node is ur temporray node

}
}
/* Insertion at beginning */

scanf("%d",& value);
new->data=value;
new->next=head;
head=new;

/* insertion at ending */
scanf("%d",&value);
new->data=value;
tail->next=new;
new->next=null;
tail=new;

/*insertion at specified position */
scanf("%d",&value);
scanf("%d",&pos);
temp=head;
for(i=0;i<pos-1;i++)
{
temp=temp->next;
}
new->data=value;
new->next=temp->ne	xt
temp->next=new

/*Deletion at beginning */
//Disconnect the link  (Null at address place)
temp=head;
head=head->next;
temp->next=Null;

//Deletion at ending
temp=head;
while(temp->next!=tail)
{
temp=temp->next;
}
temp->next=Null;
tail=temp;

//Deletion at specified Location
temp=head;
scanf("%d",&pos);
for(i=0;i<pos-1;i++)
{
temp=temp->next
}
temp->next=temp->next->next


/* Creating Circular Linked List */
struct node
{
   int data;
   struct node *next;
}*new,*head,*tail,*temp;

do
{
   new=(struct node *)malloc(sizeof(struct node));
   scanf("%d",&value);
   new->data=value;
   new->next=NULL;
   if(head==NULL)
   {
     head=new;
     tail=new;
   }
   else
   {
      tail->next=new;
      tail=new;
      tail->next=head;
   }
   printf("Y-Continue,N-Exit");
   scanf("%c",&ch);
}while(ch='Y');

/* Display circular linked list */
     temp=head;
while(temp->next!=head)
{
   printf("%d",temp->data);
   temp=temp->next;

}
printf("%d",temp->data);

//Circular linked list insertion
//Insertion at beginning
scanf("%d",&value);
new->data=value;
new->next=head;
tail->next=new;
head=new;

//insertion at end
scanf("%d",&value)
new->data=value
tail->next=new;
new->next=head;
tail=new;

//insertion at specified position
scanf("%d",&value);
scanf("%d",&pos);
temp=head;
for(i=0;i<pos-1;i++)
{
 temp=temp->next
}
temp->data=value;
new->next=temp->next;
temp->next=new;

//Deletion of node at circular linked list
// Deletion at beginning
temp=head;
head=head->next;
tail->next=head;
temp->next=null;

//Deletion at end
temp=head;
while(temp->next!=tail)
{
temp=temp->next
}
tail->next=null;
temp->next=head;
tail=temp;

//Deletion at specified position
scanf("%d",&pos);
temp=head;
for(i=0;i<pos-1;i++)
{
  temp=temp->next;
}
temp->next=temp->next->next;


// creation of doubly linked list
struct node
{
   struct node *prev;
   int data;
   struct node *next;
}*new,*head,*tail,*temp;
do
{
   new=(struct node *)malloc(sizeof(struct node));
   scanf("%d",&value);
   new->prev=NULL;
   new->data=value;
   new->next=NULL;
   if(head==NULL)
   {
     head=new;
     tail=new;
   }
   else
   {
      tail->next=new;
      new->prev=tail;
      tail=new;
   }
   printf("Y-Continue,N-Exit");
   scanf("%c",&ch);
}while(ch='Y');

//Display Doubly Linked list elements
temp=head;
while(temp!=NULL)
{
 printf("%d",temp->data);
 temp=temp->next;
}

//Doubly linked list Insertion
// Insertion at Beginning
scanf("%d",&value)_;
new->data=value;
new->prev=NULL;
new->next=head;
head->prev=new;
head=new;

//insertion at end
scanf("%d",&value);
new->data=value;
new->next=NULL;
new->prev=tail;
tail->next=new;
tail=new;

//Insertion Element at Specified Location
scanf("%d",&value);
scanf("%d",&pos);
temp=head;
for(i=0;i<pos-1;i++)
{
  temp=temp->next
}
new->data=value;
new->next=temp->next;
temp->next->prev=new;
temp->next=new;
new->prev=temp;

//Deletion at beginning
temp=head;
head=head->next;
temp->next=NULL;
head->prev=NULL

//Deletion at end
temp=tail;
tail=tail->prev;
temp->prev=NULL;
tail->next=NULL;

//Deletion at Specified position
scanf("%d",&pos);
temp=head;
for(i=0;i<pos-1;i++)
{
  tem=temp->next;
}
temp->next=temp->next->next;
temp->next->prev=temp;


































































