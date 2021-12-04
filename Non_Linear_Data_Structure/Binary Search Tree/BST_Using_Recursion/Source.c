#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct BST
{
	struct BST* Left;
	int Data;
	struct BST* Right;
};


//CreateNode-Function
struct BST* CreateNode()
{
	int Value;
	struct BST* NewNode = NULL;

	NewNode = (struct BST*)malloc(sizeof(struct BST));
	if(NewNode==NULL)
	{
		printf("Memory Not Allocated\n");
	}	//end if
	else
	{
		printf("Enter Value: ");
		scanf("%d",&Value);

		NewNode->Left = NULL;
		NewNode->Data = Value;
		NewNode->Right = NULL;
	}	//end else
	return NewNode;
}	//end CreateNode-Function


//Create_BST-Function
void Create_BST(struct BST** Root , struct BST** NewNode)
{
	struct BST* TempNode = NULL;

	if(*Root==NULL)
	{
		*Root = *NewNode;
	}	//end if
	else
	{
		TempNode = *Root;

		if((*NewNode)->Data < TempNode->Data)
		{
			if(TempNode->Left == NULL)
			{
				TempNode->Left = *NewNode;
			}	//end if
			else
			{
				Create_BST(&(TempNode->Left),NewNode);
			}	//end else
		}	//end if
		else
		{
			if(TempNode->Right == NULL)
			{
				TempNode->Right = *NewNode;
			}	//end if
			else
			{
				Create_BST(&(TempNode->Right),NewNode);
			}	//end else
		}	//end else

	}	//end else
}	//end Create_BST

//PreOrder-Funtion
void PreOrder(struct BST* Root)
{
	if(Root!=NULL)
	{
		printf("%d => ",Root->Data);
		PreOrder(Root->Left);
		PreOrder(Root->Right);
	}	//end if
}	//end PreOrder


//InOrder-Funtion
void InOrder(struct BST* Root)
{
	if(Root!=NULL)
	{
		InOrder(Root->Left);
		printf("%d => ",Root->Data);
		InOrder(Root->Right);
	}	//end if
}	//end InOrder


//PreOrder-Funtion
void PostOrder(struct BST* Root)
{
	if(Root!=NULL)
	{
		PostOrder(Root->Left);
		PostOrder(Root->Right);
		printf("%d => ",Root->Data);
	}	//end if
}	//end PostOrder


//main-Function
void main()
{
	struct BST* Root = NULL;
	struct BST* NewNode = NULL;
	int Choice;

	do
	{
		printf("\n");
		printf("1. Create BST\n");
		printf("2. PreOrder\n");
		printf("3. InOrder\n");
		printf("4. PostOrder\n");
		printf("0. Exit\n");

		printf("Enter Choice: ");
		scanf("%d",&Choice);

		switch(Choice)
		{
		case 1:
			NewNode = CreateNode();
			Create_BST(&Root,&NewNode);
			break;
		case 2:PreOrder(Root);
			break;
		case 3:InOrder(Root);
			break;
		case 4:PostOrder(Root);
			break;
		case 0:
			printf("Thank You...!!\n");
			break;
		}	//end switch
	}while(Choice!=0);	//end do-while
	getch();
}	//end main-Function
