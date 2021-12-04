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
void Create_BST(struct BST** Root)
{
	struct BST* NewNode = CreateNode();
	struct BST* TempNode = NULL;

	if(*Root==NULL)
	{
		*Root = NewNode;
	}	//end if
	else
	{
		TempNode = *Root;

		while(1)
		{
			if(NewNode->Data < TempNode->Data)
			{
				if(TempNode->Left == NULL)
				{
					TempNode->Left = NewNode;
					break;
				}	//end if
				else
				{
					TempNode = TempNode->Left;
				}	//end else
			}	//end if
			else
			{
				if(TempNode->Right == NULL)
				{
					TempNode->Right = NewNode;
					break;
				}	//end if
				else
				{
					TempNode = TempNode->Right;
				}	//end else
			}	//end else
		}	//end while
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


//Search-Function
void Search(struct BST* Root)
{
	int Element , Flag;

	printf("Enter Element To Be Searched => ");
	scanf("%d",&Element);

	Flag = 0;
	while(Root!=NULL)
	{
		if(Root->Data == Element)
		{
			printf("Element Found\n");
			Flag = 1;
			break;
		}	//end if
		else
		{
			if(Element < Root->Data)
			{
				Root = Root->Left;
			}	//end if
			else
			{
				Root = Root->Right;
			}	//end else
		}	//end else
	}	//end while

	if(Flag==0)
	{
		printf("Element Not Found\n");
	}	//end if
}	//end Search-Function


//CountNode-Function
int CountNode(struct BST* Root , int Count)
{
	if(Root!=NULL)
	{
		Count++;

		Count = CountNode(Root->Left,Count);
		Count = CountNode(Root->Right,Count);

	}	//end if
		
	return Count;
}	//end CountNode-Function


//PrintLeafNode-Function
void PrintLeafNode(struct BST* Root)
{
	if(Root!=NULL)
	{
		if(Root->Left==NULL && Root->Right==NULL)
		{
			printf("%d ",Root->Data);
		}	//end if
		PrintLeafNode(Root->Left);
		PrintLeafNode(Root->Right);
	}	//end if
}	//end PrintLeafNodeOrder-Function


//CountLeafNode-Function
int CountLeafNode(struct BST* Root , int Count)
{
	if(Root!=NULL)
	{
		if(Root->Left==NULL && Root->Right==NULL)
		{
			Count++;
		}	//end if
		Count = CountLeafNode(Root->Left,Count);
		Count = CountLeafNode(Root->Right,Count);
	}	//end if
	return Count;
}	//end CountLeafNodeOrder-Function



//DeleteInBST-Function
void DeleteInBST(struct BST** Root)
{
	struct BST* TempNode = NULL;
	struct BST* Temp1 = NULL;
	struct BST* DeleteNode = NULL;
	int Element , Flag ;

	printf("Enter Element To Be Delete => ");
	scanf("%d",&Element);

	TempNode = *Root;
	Flag = 0;
	while(TempNode!=NULL)
	{
		if(TempNode->Data == Element)
		{
			
			DeleteNode = TempNode;

			if(TempNode->Left!=NULL)
			{
				TempNode = TempNode->Left;
				while(TempNode!=NULL)
				{
					TempNode = TempNode->Right;
				}	//end while
				TempNode = DeleteNode->Right;
				if(TempNode==*Root)
				{
					*Root = DeleteNode->Left;
				}	//end if
				else
				{
					Temp1->Left = DeleteNode->Left;
				}	//end else
			}	//end if
			else
			{
				if(TempNode==*Root)
				{
					*Root = DeleteNode->Right;
				}	//end if
				else
				{
					Temp1->Right = DeleteNode->Right;
				}	//end else
			}	//end else
			
			if(DeleteNode==*Root)
			{
				*Root = NULL;
			}	//end if
			free(DeleteNode);

			Flag = 1;
			break;
		}	//end if
		else
		{
			if(Element < TempNode->Data)
			{
				Temp1 = TempNode;
				TempNode = TempNode->Left;
			}	//end if
			else
			{
				Temp1 = TempNode;
				TempNode = TempNode->Right;
			}	//end else
		}	//end else
	}	//end while


	if(Flag==0)
	{
		printf("%d is not present in given BST\n",Element);
	}	//end if

}	//DeleteInBST-Function



//main-Function
void main()
{
	struct BST* Root = NULL;
	int Choice , Count ;

	do
	{
		printf("\n");
		printf("1. Create BST\n");
		printf("2. PreOrder\n");
		printf("3. InOrder\n");
		printf("4. PostOrder\n");
		printf("5. Search Element In BST\n");
		printf("6. Count Node In BST\n");
		printf("7. Printf Leaf Nodes\n");
		printf("8. Count Leaf Node In BST\n");
		printf("9. Delete Node In BST\n");
		printf("0. Exit\n");

		printf("Enter Choice: ");
		scanf("%d",&Choice);

		switch(Choice)
		{
		case 1:Create_BST(&Root);
			break;
		case 2:PreOrder(Root);
			break;
		case 3:InOrder(Root);
			break;
		case 4:PostOrder(Root);
			break;
		case 5:Search(Root);
			break;
		case 6:
			Count = 0;
			Count = CountNode(Root , Count);
			printf("No Of Nodes In Given BST Are => %d\n",Count);
			break;
		case 7:
			printf("The Leaf Nodes Of Given BST Are => [ ");
			PrintLeafNode(Root);
			printf("]\n");
			break;
		case 8:
			Count = 0;
			Count = CountLeafNode(Root,Count);
			printf("No Of Nodes In Given BST Are => %d\n",Count);
			break;
		case 9:
			DeleteInBST(&Root);
			break;
		case 0:
			printf("Thank You...!!\n");
			break;
		}	//end switch
	}while(Choice!=0);	//end do-while
	getch();
}	//end main-Function