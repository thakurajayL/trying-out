#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
typedef struct queue Q;
void add(Q **head)
{
	Q *temp,*new,**addr;
	if(*head==NULL)
	{
		addr= head;
	}
	else
	{
		for(temp=*head;temp->next!=NULL;temp=temp->next);
		addr = &temp->next;
	}
	*addr=(Q *)malloc(sizeof(Q));
	(*addr)->next=NULL;
	printf("\n Enter data=");
	scanf("%d",&(*addr)->data);
}

void delete(Q **head)
{
	Q *temp,*temp1,*temp2;
	int n;
	printf("\n enter the data to delete");
	scanf("%d",&n);
	if((*head)->data!=n)
	{
		for(temp=*head;temp->data!=n;temp=temp->next)
		{
			temp2=temp;
		}
		temp2->next= temp->next;
	}
	else
	{
		temp=*head;
		*head=(*head)->next;
	}
	free(temp);
}

void display(Q **head)
{
	Q *temp;
	for(temp=*head;temp!=NULL;temp=temp->next)
	printf(" %d ",temp->data);
}
int main(void)
{
	int choice;
	Q *head=NULL;
	while(1)
	{
		printf("\nEnter ur choice");
		printf("\n1.Add element ");
		printf("\n2.Delete Element");
		printf("\n3.Display link list");
		printf("\n4.quit");
		printf("\nwhat is ur choice....");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			add(&head);
			break;
		case 2:
			delete(&head);
			break;
		case 3:
			display(&head);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\n Eneter valid choice");
		}
	}
return 0;
}
