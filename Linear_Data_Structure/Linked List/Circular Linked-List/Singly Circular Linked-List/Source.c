#include<stdio.h>
#include<stdlib.h>

//Struct Node
struct node
{
	int data;
	struct node* next;
};

// CreateNode-Function
struct node* CreateNode()
{
	int value;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));

	if(newnode==NULL)
	{
		printf("Memory Not Allocated\n");
	}	//end if
	else
	{
		printf("Please enter a value\n");
		scanf("%d",&value);

		newnode->data = value;
		newnode->next = NULL;

		return newnode;
	}	//end else

}	//end CreateNode


//CreateLinkedList-Function
void CreateLinkedList(struct node** Tail)
{
	struct node* newnode = CreateNode();

	if(*(Tail)==NULL)
	{
		*Tail = newnode;
		(*Tail)->next = newnode;
	}	//end if
	else
	{
		newnode->next = (*Tail)->next;
		(*Tail)->next = newnode;
		*Tail = newnode;
	}	//end else

}	//end CreateLinkedList()


//DisplayLinkedList-Function
void DisplayLinkedList(struct node* Tail)
{
	struct node* TempNode = NULL;
	if(Tail==NULL)
	{
		printf("Linked-List is Empty\n\n");
	}	//end if
	else
	{
		TempNode = Tail->next;
		printf("The Elements in Linked List are[ ");
		do
		{
			printf("%d ",TempNode->data);
			TempNode = TempNode->next;
		}while(Tail->next!=TempNode);	//end do-while
		printf("]\n");
	}	//end else
}	//end DisplayLinkedList


//InsertAtFirst-Function
void InsertAtFirst(struct node** Tail)
{
	struct node* newnode = NULL;
	newnode = CreateNode();

	if(*(Tail)==NULL)
	{
		*Tail = newnode;
		(*Tail)->next = newnode;
	}	//end if
	else
	{
		newnode->next = (*Tail)->next;
		(*Tail)->next = newnode;
	}	//end else

}	//end InsertAtFirst-Function



//InsertALast-Function
void InsertAtLast(struct node** Tail)
{
	CreateLinkedList(Tail);
}	//end InsertAtLast-Function


//InsertOnElement-Function
void InsertOnElement(struct node** Tail)
{
	int Search , Flag;
	struct node* NewNode = NULL;
	struct node* TempNode = NULL;
	
	printf("Enter Element: ");
	scanf("%d",&Search);

	if((*Tail)==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else if(Search==(*Tail)->next->data)
	{
		InsertAtFirst(Tail);
	}	//end else-if
	else if(Search==(*Tail)->data)
	{
		TempNode = (*Tail)->next;
		while((*Tail)!=TempNode->next)
		{
			TempNode = TempNode->next;
		}	//end while

		NewNode=CreateNode();

		NewNode->next = TempNode->next;
		TempNode->next  = NewNode;

	}	//end else-if
	else
	{
		TempNode = (*Tail)->next;
		Flag = 0;
		while((*Tail)!=TempNode)
		{
			if(Search == TempNode->next->data)
			{
				NewNode = CreateNode();
	
				NewNode->next = TempNode->next;
				TempNode->next = NewNode;
				Flag = 1;
				break;
			}	//end if
			TempNode = TempNode->next;
		}	//end while

		if(Flag==0)
		{
			printf("Invalid Element\n");
			InsertOnElement(Tail);
		}	//end if
	}	//end else	
}	//end InsertOnElement-Function


//DeleteAllNode-Function
void DeleteAllNode(struct node** Tail)
{
	struct node* DeleteNode = NULL;
	struct node* TempNode = NULL;

	TempNode = *Tail;
	do
	{
		DeleteNode = (*Tail)->next;
		(*Tail)->next = (*Tail)->next->next;
		free(DeleteNode);
	}while(TempNode!=(*Tail)->next);	//end do-While
	free(*Tail);
	*Tail = NULL;
}	//end DeleteAllNode-Function



//main-Function
void main()
{
	int choice , Count ;
	struct node* last = NULL;

	do
	{
		printf("1. Create Linked List\n");
		printf("2. Display Linked List\n");
		printf("3. Insert At First\n");
		printf("4. Insert At Last\n");
		printf("5. Insert on Element\n");
		printf("6. Delete All Node\n");
		printf("0. Exit\n");

		printf("Please Enter Your Choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:CreateLinkedList(&last);
			break;
		case 2:DisplayLinkedList(last);
			break;
		case 3:InsertAtFirst(&last);
			break;
		case 4:InsertAtLast(&last);
			break;
		case 6:DeleteAllNode(&last);
			break;
		case 5:InsertOnElement(&last);
			break;
		
		case 0:printf("Thank You\n");
			exit;
		}	//end switch

	}while(choice!=0);	//end do-while

}	//end main