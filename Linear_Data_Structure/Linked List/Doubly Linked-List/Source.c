#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node* Pre;
	int data;
	struct node* next;
};


//CreateNode-Function
struct node* CreateNode()
{
	struct node* NewNode = NULL;
	int value;
	NewNode = (struct node*)malloc(sizeof(struct node));

	if(NewNode==NULL)
	{
		printf("Memory Not Allocated\n");
	}	//end if
	else
	{
		NewNode->Pre = NULL;

		printf("Enter Value: ");
		scanf("%d",&value);

		NewNode->data = value;

		NewNode->next = NULL;
	}	//end else
	return NewNode;
}	//end CreateNode-Function


//CreateLinkedList-Function
void CreateLinkedList(struct node** Head , struct node** Tail)
{
	struct node* NewNode = NULL;
	NewNode = CreateNode();

	if((*Head)==NULL)
	{
		*Head=NewNode;
		*Tail=NewNode;
	}	//end if
	else
	{
		(*Tail)->next=NewNode;
		NewNode->Pre=(*Tail);
		*Tail=NewNode;
	}	//end else
}	//end CreateLinkedList-Function


//DisplayLinkedList-Function
void DisplayLinkedList(struct node* Head)
{
	if(Head==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else
	{
		printf("The Linked-List Is: [ ");
		while(Head!=NULL)
		{
			printf("%d ",Head->data);
			Head=Head->next;
		}	//end while
		printf("]\n");
	}	//end else
}	//end DisplayLinkedList-Function


//DisplayReverseLinkedList-Function
void DisplayReverseLinkedList(struct node* Tail)
{
	if(Tail==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else
	{
		printf("The Linked-List in Reverse Order Is: [ ");
		while(Tail!=NULL)
		{
			printf("%d ",Tail->data);
			Tail=Tail->Pre;
		}	//end while
		printf("]\n");
	}	//end else
}	//end DisplayReverseLinkedList-Function


//InsertAtFirst-Function
void InsertAtFirst(struct node** Head , struct node** Tail)
{
	struct node* NewNode = NULL;
	NewNode=CreateNode();

	if((*Head)==NULL)
	{
		*Head=NewNode;
		*Tail=NewNode;
	}	//end if
	else
	{
		NewNode->next=*Head;
		(*Head)->Pre=NewNode;
		*Head=NewNode;
	}	//end else
}	//end InsertAtFirst-Function


//InsertAtLast-Function
void InsertAtLast(struct node** Head, struct node** Tail)
{
	CreateLinkedList(Head,Tail);
}	//end InsertAtLast-Function


//CountNode-Function
int CountNode(struct node* Head)
{
	int Count = 0;
	
	while(Head!=NULL)
	{
		Count++;
		Head=Head->next;
	}	//end while

	return Count;
}	//end CountNode-Function


//InsertAtPosition-Function
void InsertAtPosition(struct node** Head, struct node** Tail)
{
	int Position , Count , i ;
	struct node* NewNode = NULL;
	struct node* TempNode = NULL;

	Count = CountNode(*Head);
	
	printf("Enter Position: ");
	scanf("%d",&Position);

	if(Position==1)
	{
		InsertAtFirst(Head,Tail);
	}	//end if
	else if(Position==Count+1)
	{
		InsertAtLast(Head,Tail);
	}	//end else-if
	else if(Position<1 || Position>Count+1)
	{
		printf("Invalid Choice\n");
		InsertAtPosition(Head,Tail);
	}	//end else-if
	else
	{
		NewNode=CreateNode();
		TempNode=*Head;

		for(i=1;i<Position-1;i++)
		{
			TempNode=TempNode->next;
		}	//end for
		
		NewNode->Pre=TempNode;
		NewNode->next=TempNode->next;
		TempNode->next=NewNode;
		NewNode->next->Pre=NewNode;
	}	//end else
}	//end InsertAtPosition-Function


//DeleteAtFirst-Function
void DeleteAtFirst(struct node** Head, struct node** Tail)
{
	struct node* DeleteNode = *Head;
	if( (*Head)==NULL )
	{
		printf("Linked-List is Empty\n\n");
	}	//end if
	else
	{
		if((*Head)->next==NULL)
		{
			*Head=NULL;
			*Tail=NULL;
		}	//end if
		else
		{
			*Head = DeleteNode->next;
			(*Head)->Pre=NULL;
		}	//end else
		free(DeleteNode);
	}	//end else
}	//end DeleteAtFirst-Function


//DeleteAtLast-Function
void DeleteAtLast(struct node** Head , struct node** Tail)
{
	struct node* DeleteNode = NULL;

	if((*Head)==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else
	{
		if((*Head)->next==NULL)
		{
			DeleteAtFirst(Head,Tail);
		}	//end if
		else
		{
			(*Tail)->Pre->next=NULL;
			DeleteNode=*Tail;
			*Tail=(*Tail)->Pre;
			free(DeleteNode);
		}	//end else
	}	//end else
}	//end DeleteAtLast-Function


//DeleteAtPosition-Function
void DeleteAtPosition(struct node** Head , struct node** Tail)
{
	int Position , Count , i ;
	struct node* TempNode = NULL;
	struct node* DeleteNode = NULL;

	Count = CountNode(*Head);
	
	if((*Head)==NULL)
	{
		printf("Linked-List Is Empty\n");
	}	//end if
	else
	{		
		printf("Enter Position: ");
		scanf("%d",&Position);
	
		if(Position==1)
		{
			DeleteAtFirst(Head,Tail);
		}	//end if
		else if(Position==Count)
		{
			DeleteAtLast(Head,Tail);
		}	//end else-if
		else if(Position<1 || Position>Count)
		{
			printf("Invalid Choice\n");
			DeleteAtPosition(Head,Tail);
		}	//end else-if
		else
		{
			TempNode=*Head;
			for(i=1;i<Position-1;i++)
			{
				TempNode=TempNode->next;
			}	//end for
			
			DeleteNode = TempNode->next;
			TempNode->next=TempNode->next->next;
			TempNode->next->Pre=TempNode;
			free(DeleteNode);

		}	//end else
	
	}	//end else
}	//end DeleteAtPosition-Function


//Reverse-Function
void Reverse(struct node** Head , struct node** Tail)
{
	struct node *TempNode1 = NULL; 
    struct node *TempNode2 = NULL;
      
	TempNode2 = *Head;
    while(TempNode2 !=  NULL)
    {
      TempNode1 = TempNode2->Pre;
      TempNode2->Pre = TempNode2->next;
      TempNode2->next = TempNode1;             
      TempNode2 = TempNode2->Pre;
    }     //end while
      

	*Tail=*Head;
	*Head = TempNode1->Pre;

}	//end Reverse-Function



//main-Function
void main()
{
	int choice;
	struct node* first = NULL;
	struct node* last = NULL;

	do
	{
		printf("1. Create Linked-List\n");
		printf("2. Display Linked-List\n");
		printf("3. Display Reverse Linked-List\n");
		printf("4. Insert At First\n");
		printf("5. Insert At Last\n");
		printf("6. Insert At Position\n");
		printf("7. Delete At First\n");
		printf("8. Delete At Last\n");
		printf("9. Delete At Position\n");
		printf("10. Reverse D-LL\n");
		printf("0. Exit\n");

		printf("Enter Your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:CreateLinkedList(&first,&last);
			break;
		case 2:DisplayLinkedList(first);
			break;
		case 3:DisplayReverseLinkedList(last);
			break;
		case 4:InsertAtFirst(&first,&last);
			break;
		case 5:InsertAtLast(&first,&last);
			break;
		case 6:InsertAtPosition(&first,&last);
			break;
		case 7:DeleteAtFirst(&first,&last);
			break;
		case 8:DeleteAtLast(&first,&last);
			break;
		case 9:DeleteAtPosition(&first,&last);
			break;
		case 10:Reverse(&first,&last);
			break;
		case 0:printf("Thank You\n");
			exit(0);
		default:
			printf("Invalid Choice\n");
		}	//end switch-case

	}while(choice!=0);	//end do-while
	
}	//end main