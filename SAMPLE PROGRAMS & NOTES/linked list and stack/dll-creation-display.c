#include<stdio.h>
#include<stdlib.h>
struct linkedlist
{
	struct linkedlist * prev;
	int data ;
	struct linkedlist * next;
};
struct linkedlist * head, *last;
void create ();
void fdisplay();
void bdisplay();

main()
{
	int ch;
	char c;
	do 
	{
	
	printf("program to demonstarate Doubly Linkedlist creation , fdisplay, Bdisplay\n 1. CREATION \n 2. FDisplay \n 3. BDISPLAY\n enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: 
		if (head==NULL)
		{
			create ();
	    }
		else
		printf("List is already created\n");
		break;
		case 2:
		if (head==NULL)
		printf("list is empty\n");
		else
		fdisplay (head);	
		break;
	case 3:
		if (last==NULL)
		printf("list is empty\n");
		else
		bdisplay (last);	
	}
	printf(" do you want to continue\n");
	c=getch();
}while(c=='y');
}
void create()
{
	char c;
	struct linkedlist * newnode;
	newnode =(struct linkedlist *)malloc (sizeof(struct linkedlist));
	printf("enter data \n");
	scanf("%d", &newnode->data);
	if (head==NULL)
	{
		newnode->prev=NULL;
		newnode->next=NULL;
		head=newnode;
		last=newnode;
	}
	else
	{
		last->next=newnode;
		newnode->prev=last;
		newnode->next=NULL;
		last=newnode;
	}
	
	printf("do you want to add more nodes\n");
	c=getch();
	if (c=='y')
	{
		create();
	}

}


void fdisplay(struct linkedlist*ptr)
{
	while (ptr!=NULL)
	{
		printf("%d ---->", ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}

void bdisplay(struct linkedlist*ptr)
{
	while (ptr!=NULL)
	{
		printf("%d ---->", ptr->data);
		ptr=ptr->prev;
	}
	printf("NULL\n");
}

