#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int info;
	struct st *link;
}Node;
Node *start=NULL;

void add_end(int);
void add_beg(int);
void any_pos(int,int);
void display();

void add_end(int value)
{
	Node *newptr = NULL ,*ptr=NULL;
	newptr = (Node*)malloc(sizeof(Node));
	newptr->info=value;
	newptr->link=NULL;
	if (start==NULL)
	{
		start = newptr;
        start->link=start;
	}
	else
	{
		ptr=start;
		while (ptr->link!=start)
		{
			ptr=ptr->link;
		}
		ptr->link=newptr;
        newptr->link=start;
	}
}


void add_beg(int value)
{
	Node *newptr = NULL ,*ptr=NULL;
	newptr = (Node*)malloc(sizeof(Node));
	newptr->info=value;
	newptr->link=NULL;
	if (start==NULL)
	{
		start = newptr;
	}
	else
	{
		ptr=start;
		while (ptr->link!=start)
		{
			ptr=ptr->link;
		}
		newptr->link=start;
		start=newptr;
		ptr->link=start;
	}
}


void any_pos(int value,int pos)
{
	int steps = 1;
	Node *newptr = NULL ,*ptr=start;
	newptr = (Node*)malloc(sizeof(Node));
	newptr->info=value;
	newptr->link=NULL;
	while(steps<pos-1)
	{
		ptr=ptr->link;
		steps++;
	}
	if (pos==1)
	{
		add_beg(value);
	}
	else
	{
		newptr->link=ptr->link;
		ptr->link=newptr;
	}
}


void display()
{
	Node *ptr;
	ptr = start;
	do
	{
		printf("%d ->",ptr->info);
		ptr=ptr->link;
	}while(ptr!=start);

    do
	{
		printf("%d ->",ptr->info);
		ptr=ptr->link;
	}while(ptr!=start);
	printf("start\n");

    printf("The sequence is repeated twice to show that it is circular linked list.\n");
}


int main()
{
	int value,choice,pos;
	char ch;
	while(1)
	{
		printf("\nDo you want to enter a info(y/n)");
		scanf("%c",&ch);
		if (ch=='y' || ch=='Y')
		{
			printf("\nWhere will you like to enter the info:\n1. In End\n2. In Begnning\n3. In Given Position\n");
			scanf("%d",&choice);
			switch (choice)
			{
				case 1:
					printf("\nEnter the info: ");
					scanf("%d",&value);
					add_end(value);
					break;
				case 2:
					printf("\nEnter the info: ");
					scanf("%d",&value);
					add_beg(value);
					break;
				case 3:
					printf("\nEnter the info: ");
					scanf("%d",&value);
					printf("\nEnter the Position:");
					scanf("%d",&pos);
					any_pos(value,pos);
					break;
			}
			fflush(stdin);
		}
		else
		{
			break;
		}
	}
	printf("\nThe linked list is: ");
	display();
	return 0;
}
