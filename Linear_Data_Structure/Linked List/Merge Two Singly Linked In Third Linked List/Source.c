//Q6: Write a C-Program to Merge Two Different Linked-List in Third Linked-List.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};


// Createnode-Function
struct node* CreateNode()
{
	int value;
	struct node* newode = NULL ;

	newode = (struct node*)malloc(sizeof(struct node));

	if(newode==NULL)
	{
		printf("Memory Not Allocated\n");
	}	//end if
	else
	{
		printf("Enter a Value: ");
		scanf("%d",&value);

		newode->data=value;
		newode->next=NULL;
	}	//end else
	return newode;
}	//end Createnode-Function


// CreateLinkedList-Function
void CreateLinkedList(struct node** Head)
{
	struct node* newnode = CreateNode();
	struct node* TempNode = NULL;

	if((*Head)==NULL)
	{
		*Head=newnode;
	}	//end if
	else
	{
		TempNode = *Head;

		while(TempNode->next!=NULL)
		{
			TempNode=TempNode->next;
		}	//end while
		TempNode->next=newnode;
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
		printf("The Element in given Linked-List are: [ ");
		while(Head!=NULL)
		{
			printf("%d ",Head->data);
			Head=Head->next;
		}	//end while
		printf("]\n");
	}	//end else
}	//end DisplayLinkedList-Function


//Merge_2_Linked_List-Function
void Merge_2_Linked_List(struct node* Head1 , struct node* Head2 , struct node**Head3)
{
	struct node* TempNode = NULL;
	struct node* TempNode1 = NULL;
	struct node* NewNode = NULL;
	struct node* NewNode1 = NULL;
	int i = 0 ;
	
		// logic for first linked-list
		while(Head1!=NULL)
		{
			NewNode = (struct node*)malloc(sizeof(struct node));

			NewNode->data=Head1->data;
			NewNode->next=NULL;

			i++;
			// first element of first linked-list
			if(i==1)
			{
				*Head3=NewNode;
			}	//end if
			else
			{
				TempNode=*Head3;
				while(TempNode->next!=NULL)
				{
					TempNode=TempNode->next;
				}	//end while
				TempNode->next=NewNode;
			}	//end else
			Head1=Head1->next;
		}	//end while & Logic for first Linked-list
		
		i = 0 ;
		// logic for second linked-list
		while(Head2!=NULL)
		{
			NewNode1 = (struct node*)malloc(sizeof(struct node));

			NewNode1->data=Head2->data;
			NewNode1->next=NULL;

			i++;
			// first element of second linked-list
			if(i==1)
			{
				// first linked-list is present
				if(NewNode!=NULL)
				{
					NewNode->next=NewNode1;
					TempNode1=TempNode;
				}	//end if

				// first linked-list is not-present
				else
				{
					*Head3=NewNode1;
					TempNode1=*Head3;
				}	//end else
			}	//end if
			
			else
			{
				while(TempNode1->next!=NULL)
				{
					TempNode1=TempNode1->next;
				}	//end while
				TempNode1->next=NewNode1;
			}	//end else
			Head2=Head2->next;
		}	//end while & Logic for first Linked-list

}	//end Merge_2_Linked_List-Function


//main-Function
void main()
{
	int choice ;
	struct node* first = NULL ;
	struct node* second = NULL ;
	struct node* third = NULL ;

	do
	{
		printf("1. Create First Linked List\n");
		printf("2 Create Second Linked List\n");
		printf("3. Display First Linked List\n");
		printf("4. Display Second Linked List\n");
		printf("5. Merge 2 Linked List\n");
		printf("6. Display Merge Linked List\n");
		printf("0. Exit\n");

		printf("Enter Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:CreateLinkedList(&first);
			break;
		case 2:CreateLinkedList(&second);
			break;
		case 3:DisplayLinkedList(first);
			break;
		case 4:DisplayLinkedList(second);
			break;
		case 5:Merge_2_Linked_List(first , second , &third);
			break;
		case 6: DisplayLinkedList(third);
			break;
		case 0:
			printf("Thank You\n");
			exit;
		}	//end switch

	}while(choice!=0);	//end do-while

	getch();
}	//end main-Function
