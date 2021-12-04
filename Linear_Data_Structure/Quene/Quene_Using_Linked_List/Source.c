#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct QUENE
{
	int Data;
	struct QUENE* Next;
};


//CreateNode-Function
struct QUENE* CreateNode()
{
	int Value;
	struct QUENE* NewNode = NULL;

	NewNode = (struct QUENE*)malloc(sizeof(struct QUENE));

	if(NewNode==NULL)
	{
		printf("Quene Is Full\n");
	}	//end if
	else
	{
		printf("Enter Value: ");
		scanf("%d",&Value);

		NewNode->Data = Value;
		NewNode->Next=NULL;
	}	//end else

	return NewNode;
}	//end CreateNode-Function


//Insert_In_Quene-Function
void Insert_In_Quene(struct QUENE** Front,struct QUENE** Rear)
{
	struct QUENE* NewNode = CreateNode();

	if(*Rear==NULL)
	{
		*Front = NewNode;
		*Rear = NewNode;
	}	//end if
	else
	{
		(*Rear)->Next = NewNode;
		*Rear = NewNode;
	}	//end else

}	//end Insert_In_Quene-Function


//Delete_In_Quene-Function
void Delete_In_Quene(struct QUENE** Front)
{
	int Value;
	struct QUENE* TempNode = NULL;

	TempNode = *Front;
	Value = (*Front)->Data;
	*Front = (*Front)->Next;
	free(TempNode);

	printf("DeQuene Element Is=> %d\n",Value);
}	//end Delete_In_Quene-Function


//main-Function
void main()
{
	int Choice;
	struct QUENE* Front = NULL;
	struct QUENE* Rear = NULL;

	do
	{
		printf("1. Insert In Quene\n");
		printf("2. Delete In Quene\n");
		printf("0. Exit\n");

		printf("Enter Choice: ");
		scanf("%d",&Choice);

		switch(Choice)
		{
		case 1:Insert_In_Quene(&Front,&Rear);
			break;

		case 2:
			if(Front==NULL)
			{
				printf("Quene Is Empty\n");
				Rear = NULL;
			}	//end if
			else
			{
				Delete_In_Quene(&Front);
			}	//end else
			break;

		case 0:
			printf("Thank You...!!\n");
			break;
		}	//end switch
	}while(Choice!=0);	//end do-While

	getch();
}	//end main-Function