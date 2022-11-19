#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
    struct st *lptr;
    int info;
    struct st *rptr;
}Node;
Node *start=NULL,*last=NULL;

void add_end(int value)
{
    Node *newptr,*ptr;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=value;
    newptr->lptr=NULL;
    newptr->rptr=NULL;
    if(start==NULL)
    {
        start=newptr;
        last=newptr;
        start->rptr=start;
        start->lptr=last;
    }
    else
    {
        ptr=start;
        while(ptr->rptr!=start)
        {
            ptr=ptr->rptr;
        }
        ptr->rptr=newptr;
        newptr->lptr=ptr;
        newptr->rptr=start;
        last=newptr;
        start->lptr=last;
    }
}

void add_beg(int value)
{
    Node *newptr,*ptr;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=value;
    newptr->lptr=NULL;
    newptr->rptr=NULL;
    if(start==NULL)
    {
        start=newptr;
        last=newptr;
        start->rptr=start;
        start->lptr=last;
    }
    else
    {
        newptr->rptr=start;
        start->lptr=newptr;
        start=newptr;
        start->lptr=last;
        last->rptr=start;
    }
}

void any_pos(int value,int pos)
{
    if (pos==1)
    {
        add_beg(value);
    }
    else
    {
        int steps=1;
        Node *newptr,*ptr;
        newptr=(Node*)malloc(sizeof(Node));
        newptr->info=value;
        newptr->lptr=NULL;
        newptr->rptr=NULL;
        ptr=start;
        while(steps<pos)
        {
            ptr=ptr->rptr;
            steps++;
        }
        (ptr->lptr)->rptr=newptr;
        newptr->lptr=ptr->lptr;
        ptr->lptr=newptr;
        newptr->rptr=ptr;
    }
}

void display()
{
    Node *ptr;
    ptr=start;
    do
    {
        printf("%d -> ",ptr->info);
        ptr=ptr->rptr;
    } while (ptr!=start);
    
    do
    {
        printf("%d -> ",ptr->info);
        ptr=ptr->rptr;
    } while (ptr!=start);

    printf("start\n");

    printf("The sequence is repeated twice to show that it is circular linked list.\n");

}

void reverse_display()
{
    Node *ptr;
    ptr=last;
    do
    {
        printf("%d -> ",ptr->info);
        ptr=ptr->lptr;
    } while (ptr!=last);
    
    do
    {
        printf("%d -> ",ptr->info);
        ptr=ptr->lptr;
    } while (ptr!=last);

    printf("last\n");

    printf("The sequence is repeated twice to show that it is circular linked list.\n");
}


void delete_end()
{
    Node *ptr;
    ptr=last;
    (ptr->lptr)->rptr=start;
    last=ptr->lptr;
    start->lptr=last;
    free(ptr);
    ptr=NULL;
}

void delete_beg()
{
    Node *ptr;
    ptr=start;
    start=ptr->rptr;
    start->lptr=last;
    last->rptr=start;
    free(ptr);
    ptr=NULL;
}

void delete_pos(int pos)
{
    int steps=1;
    Node *ptr;
    ptr=start;
    if(pos==1)
    {
        delete_beg;
    }
    else
    {
        while(steps<pos)
        {
            ptr=ptr->rptr;
            steps++;
        }
        if(ptr->rptr==start)
        {
            delete_end;
        }
        else
        {
            (ptr->lptr)->rptr=ptr->rptr;
            (ptr->rptr)->lptr=ptr->lptr;
            free(ptr);
            ptr=NULL;
        }
    }
   
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
                default:
                    printf("Wrong Input!!");
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
    printf("\nThe Reverse linked list is: ");
    reverse_display();

    while(1)
	{
		printf("\nDo you want to Delete any info(y/n)");
		scanf(" %c",&ch);
		if (ch=='y' || ch=='Y')
		{
			printf("\nFrom where will you like to delete info:\n1. From End\n2. From Begnning\n3. From Given Position\n");
			scanf("%d",&choice);
			switch (choice)
			{
				case 1:
					delete_end();
					break;
				case 2:
					delete_beg();
					break;
				case 3:
					printf("\nEnter the Position:");
					scanf("%d",&pos);
					delete_pos(pos);
					break;
                default:
                    printf("Wrong Input!!");
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
    printf("\nThe Reverse linked list is: ");
    reverse_display();
    return 0;
}