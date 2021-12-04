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
void CreateLinkedList(struct node** Tail)
{
	struct node* NewNode = NULL;
	NewNode = CreateNode();

	if((*Tail)==NULL)
	{
		*Tail = NewNode;
		(*Tail)->next=NewNode;
		(*Tail)->Pre=NewNode;
	}	//end if
	else
	{
		NewNode->Pre = *Tail;
		NewNode->next = (*Tail)->next;
		(*Tail)->next = NewNode;
		*Tail=NewNode;
		(*Tail)->next->Pre = NewNode;
	}	//end else
}	//end CreateLinkedList-Function


//DisplayLinkedList-Function
void DisplayLinkedList(struct node* Tail)
{
	struct node* TempNode = NULL;
	if(Tail==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else
	{
		TempNode = Tail->next;
		printf("The Linked-List Is: [ ");
		do
		{
			printf("%d ",TempNode->data);
			TempNode = TempNode->next;
		}while(Tail->next!=TempNode);	//end do-while
		printf("]\n");
	}	//end else
}	//end DisplayLinkedList-Function


//DisplayReverseLinkedList-Function
void DisplayReverseLinkedList(struct node* Tail)
{
	struct node* TempNode = NULL;
	if(Tail==NULL)
	{
		printf("Linked-List is Empty\n");
	}	//end if
	else
	{
		TempNode = Tail;
		printf("The Linked-List Is: [ ");
		do
		{
			printf("%d ",TempNode->data);
			TempNode = TempNode->Pre;
		}while(Tail!=TempNode);	//end do-while
		printf("]\n");
	}	//end else
}	//end DisplayReverseLinkedList-Function


//InsertAtFirst-Function
void InsertAtFirst(struct node** Tail)
{
	struct node* NewNode = NULL;
	NewNode=CreateNode();

	if((*Tail)==NULL)
	{
		*Tail = NewNode;
		(*Tail)->next=NewNode;
		(*Tail)->Pre=NewNode;
	}	//end if
	else
	{
		NewNode->Pre = *Tail;
		NewNode->next = (*Tail)->next;
		(*Tail)->next = NewNode;
		NewNode->next->Pre = NewNode;
	}	//end else
}	//end InsertAtFirst-Function



//InsertAtLast-Function
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
		NewNode = CreateNode();

		NewNode->Pre = (*Tail)->Pre;
		NewNode->next = *Tail;
		NewNode->Pre->next = NewNode;
		(*Tail)->Pre = NewNode;
	}	//end else-if
	else
	{
		TempNode = (*Tail)->next;
		Flag = 0;
	
		do
		{
			if(Search == TempNode->data)
			{
				NewNode = CreateNode();
	
				NewNode->next =TempNode;
				NewNode->Pre=TempNode->Pre;
				NewNode->Pre->next=NewNode;
				TempNode->Pre=NewNode;
				Flag = 1;
				break;
			}	//end if
			TempNode = TempNode->next;
		}while((*Tail)->next!=TempNode);	//end do-while

		if(Flag==0)
		{
			printf("Invalid Element\n");
			InsertOnElement(Tail);
		}	//end if
	}	//end else
	
}	//end InsertOnElement-Function


//main-Function
void main()
{
	int choice;
	struct node* last = NULL;

	do
	{
		printf("1. Create Linked-List\n");
		printf("2. Display Linked-List\n");
		printf("3. Display Reverse Linked-List\n");
		printf("4. Insert At First\n");
		printf("5. Insert At Last\n");
		printf("6. Insert On Element\n");
		printf("0. Exit\n");

		printf("Enter Your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:CreateLinkedList(&last);
			break;
		case 2:DisplayLinkedList(last);
			break;
		case 3:DisplayReverseLinkedList(last);
			break;
		case 4:InsertAtFirst(&last);
			break;
		case 5:InsertAtLast(&last);
			break;
		case 6:InsertOnElement(&last);
			break;
		case 0:printf("Thank You\n");
			exit(0);
		default:
			printf("Invalid Choice\n");
		}	//end switch-case

	}while(choice!=0);	//end do-while
	
}	//end main