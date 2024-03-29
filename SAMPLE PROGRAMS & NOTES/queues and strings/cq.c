// Circular Queue implementation in C
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
void enQueue(int);
void deQueue();
void display();
int queue[SIZE], front = -1, rear = -1;
void main()
{
   int value, choice;
   while(1){
      printf("\n\n***** MENU *****\n");
      printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Try again!!!");
      }
   }
}
void enQueue(int value)
{
  // if(rear == SIZE-1) //condition for linear queue
  if ((rear+1 == front)||((front==0) && (rear==SIZE-1)))//condition for circular q
      printf("\nQueue is Full!!! Insertion is not possible!!!");
   else if((front == -1) && (rear==-1))
	 {
	 front = 0;
	 rear=0;
	 queue[rear] = value;
      printf("\nInsertion success!!!");
     }
	 else {
	  rear=(rear + 1)% SIZE;
	  queue[rear] = value;
      printf("\nInsertion success!!!");
  }	
}
void deQueue()
{
   if(front == -1 && rear==-1)
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
   else if ((front==rear) )
	 {
	printf("\nDeleted : %d", queue[front]);
	front=rear=-1;
}
else 
     {
	   printf("\nDeleted : %d", queue[front]);
      front=(front+1 )% SIZE;
	}
}
void display()
{
int i;
if (front == -1)
    {
        printf("\nQueue is Empty");
    }
    else
	{
	printf("\nElements in Circular Queue are: ");
    for ( i = front; i != rear; i=((i+1) % SIZE))
	{
           printf("%d\t",queue[i]);
    }
	        printf("%d ", queue[i]);
    }
}

