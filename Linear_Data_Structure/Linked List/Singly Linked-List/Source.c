#include<stdio.h>
#include<conio.h>
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
void CreateLinkedList(struct node** head)
{
	struct node* newnode = CreateNode();

	if(*(head)==NULL)
	{
		*head = newnode;
	}	//end if
	else
	{
		struct node* TempNode = *head;

		while(TempNode->next!=NULL)
		{
			TempNode = TempNode->next;
		}	//end while
		TempNode->next = newnode;
	}	//end else

}	//end CreateLinkedList()


//DisplayLinkedList-Function
void DisplayLinkedList(struct node* Head)
{
	if(Head==NULL)
	{
		printf("Linked-List is Empty\n\n");
	}	//end if
	else
	{
		printf("The Elements in Linked List are[ ");
		while(Head!=NULL)
		{
			printf("%d ",Head->data);
			Head = Head->next;
		}	//end while
		printf("]\n");
	}	//end else
}	//end DisplayLinkedList


//InsertAtFirst-Function
void InsertAtFirst(struct node** Head)
{
	struct node* newnode = NULL;
	newnode = CreateNode();

	newnode->next = *Head;
	*Head = newnode;
}	//end InsertAtFirst-Function



//InsertALast-Function
void InsertAtLast(struct node** Head)
{
	CreateLinkedList(Head);
}	//end InsertAtLast-Function


//CountNode-Function
int Count_node(struct node* Head)
{
	int Count = 0 ;
	while(Head!=NULL)
	{
		Count++;
		Head = Head->next;
	}	//end while
	return Count;
}	//end CountNode-Function


//InsertAtPosition-Function
void InsertAtPositon(struct node** Head)
{
	int Position , Count , i ;
	struct node* newnode = NULL;
	struct node* TempNode = *Head;

	printf("Please Enter Position: ");
	scanf("%d",&Position);

	Count = Count_node(*Head);
	
	if(Position==1)
	{
		InsertAtFirst(Head);
	}	//end if
	else if(Position==Count+1)
	{
		CreateLinkedList(Head);
	}	//end else-if
	else if(Position<1 || Position>Count+1)
	{
		printf("Invalid Position\n");
		InsertAtPositon(Head);
	}	//end else-if
	else
	{
		newnode = CreateNode();

		for(i=1;i<Position-1;i++)
		{
			TempNode=TempNode->next; 
		}	//end For
		newnode->next = TempNode->next;
		TempNode->next = newnode;

	}	//end else
}	//end InsertAtPosition-Function


// DeleteAtFirst-Function
void DeleteAtFirst(struct node** Head)
{
	struct node* TempNode = *Head;
	if( (*Head)==NULL )
	{
		printf("Linked-List is Empty\n\n");
	}	//end if
	else
	{
		*Head = TempNode->next;
		free(TempNode);
	}	//end else
}	//end DeleteAtFirst-Function


// DeleteAtLast-Function
void DeleteAtLast(struct node** Head)
{
	struct node* TempNode = *Head;
	if( (*Head)==NULL )
	{
		printf("Linked-List is Empty\n\n");
	}	//end if
	else if(TempNode->next==NULL)
	{
		DeleteAtFirst(Head);
	}	//end else-if
	else
	{
		while(TempNode->next->next!=NULL)
		{
			TempNode=TempNode->next;
		}
		free(TempNode->next);
		TempNode->next=NULL;
	}	//end else
}	//end DeleteAtLast-Function


//DeleteAtPosition-Function
void DeleteAtPosition(struct node** Head)
{
	int Position , Count , i ;
	struct node* TempNode = *Head ;
	struct node* DeleteNode = NULL;

	Count = Count_node(*Head);

	if(*Head==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else
	{
		printf("Please Enter Position\n");
		scanf("%d",&Position);

		if(Position==1)
		{
			DeleteAtFirst(Head);
		}	//end if
		else if(Position==Count)
		{
			DeleteAtLast(Head);
		}	//end else-if
		else if(Position<1 || Position>Count)
		{
			printf("Invalid Position\n");
			DeleteAtPosition(Head);
		}	//end else-if
		else
		{
			for(i=1;i<Position-1;i++)
			{
				TempNode=TempNode->next;
			}	//end for
		
			DeleteNode=TempNode->next;
			TempNode->next=DeleteNode->next;
			free(DeleteNode);
		}	//end else
	}	//end else
	
}	//end DeleteAtPosition-Function



//DeleteAllNodes-Function
void DeleteAllNodes(struct node** Head)
{
	struct node* TempNode = NULL;

	while((*Head)!=NULL)
	{
		TempNode=*Head;
		*Head=(*Head)->next;

		free(TempNode);
	}	//end while
}	//end DeleteAllNodes-Function




//main-Function
void main()
{
	int choice , Count ;
	struct node* first = NULL;

	do
	{
		printf("1. Create Linked List\n");
		printf("2. Display Linked List\n");
		printf("3. Insert At First\n");
		printf("4. Insert At Last\n");
		printf("5. Insert At Position\n");
		printf("6. No.of Nodes in Linked List\n");
		printf("7. Delete At First\n");
		printf("8. Delete At Last\n");
		printf("9. Delete At Position\n");
		printf("10. Delete All Nodes In Linked-List\n");
		printf("0. Exit\n");

		printf("Please Enter Your Choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:CreateLinkedList(&first);
			break;
		case 2:DisplayLinkedList(first);
			break;
		case 3:InsertAtFirst(&first);
			break;
		case 4:InsertAtLast(&first);
			break;
		case 5:InsertAtPositon(&first);
			break;
		case 6:
			Count = Count_node(first);
			printf("Their are %d Nodes in Linked-List.\n",Count);
			break;
		case 7:DeleteAtFirst(&first);
			break;
		case 8:DeleteAtLast(&first);
			break;
		case 9:DeleteAtPosition(&first);
			break;
		case 10:DeleteAllNodes(&first);
			break;
		case 0:printf("Thank You\n");
			exit;
		}	//end switch

	}while(choice!=0);	//end do-while

	getch();
}	//end main