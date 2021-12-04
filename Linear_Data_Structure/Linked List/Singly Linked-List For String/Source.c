#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{
	char* data;
	struct node* next;
};


// CreateNode-Function
struct node* CreateNode()
{
	char* str = NULL;
	char ch;
	int count , i ;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));

	if(newnode==NULL)
	{
		printf("Memory Not Allocated\n");
	}	//end if
	else
	{
		
		str = (char*)malloc(sizeof(char));
		*(str) = '\0';
		printf("Enter a string: ");
		i = 0 ;
		count = 1 ;
		scanf(" ");
		do
		{
			scanf("%c",&ch);
			if( ch!='\n' )
			{
				count++;
				str = (char *)realloc(str , count*sizeof(char));
				*(str+i) = ch;
				*(str+(i+1)) = '\0' ;
			}	//end if
			i++;
		}while( ch!='\n' );

		newnode->data = str;
		newnode->next = NULL;

		return newnode;
	}	//end else

}	//end CreateNode


//CreateLinkedList-Function
void CreateLinkedList(struct node** head)
{
	struct node* TempNode = NULL;
	struct node* newnode = CreateNode();

	if(*(head)==NULL)
	{
		*head = newnode;
	}	//end if
	else
	{
		TempNode = *head;

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
	int i;
	if(Head==NULL)
	{
		printf("Linked-List is Empty\n\n");
	}	//end if
	else
	{
		printf("The Elements in Linked List are[ ");
		while(Head!=NULL)
		{
			i = 0 ;
			while( *(Head->data+i) != '\0' )
			{
				printf("%c",*(Head->data+i));
				i++;
			}	//end while
			printf(" ");
			Head = Head->next;
		}	//end while
		printf("]\n");
	}	//end else
}	//end DisplayLinkedList



//main-Function
void main()
{
	int choice , Count ;
	struct node* first = NULL;

	do
	{
		printf("1. Create Linked List\n");
		printf("2. Display Linked List\n");
		printf("0. Exit\n");

		printf("Please Enter Your Choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:CreateLinkedList(&first);
			break;
		case 2:DisplayLinkedList(first);
			break;
		case 0:printf("Thank You\n");
			exit;
		}	//end switch

	}while(choice!=0);	//end do-while
	getch();
}	//end main