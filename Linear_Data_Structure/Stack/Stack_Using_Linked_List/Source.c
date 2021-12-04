#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct STACK
{
	int Data;
	struct STACK *Next;
};


//CreateNode-Function
struct STACK *CreateNode()
{
	int Value;
	struct STACK *NewNode = NULL;

	NewNode = (struct STACK*)malloc(sizeof(struct STACK));

	if(NewNode==NULL)
	{
		printf("Stack OverFlow\n");
	}	//end if
	else
	{
		printf("Enter Value: ");
		scanf("%d",&Value);

		NewNode->Data = Value;
		NewNode->Next = NULL;
	}	//end else

	return NewNode;
}	//CreateNode-Function


//PUSH-Function
void PUSH(struct STACK **Top)
{
	struct STACK *NewNode = NULL;

	NewNode = CreateNode();

	if( *Top==NULL )
	{
		*Top = NewNode;
	}	//end if
	else
	{
		NewNode->Next = *Top;
		*Top = NewNode;
	}	//end else

}	//end PUSH-Function


//IsEmpty-Function
int IsEmpty(struct STACK *Top)
{
	if(Top==NULL)
	{
		return 1;
	}	//end if
	else
	{
		return 0;
	}	//end else
}	//end IsEmpty-Function


//POP-Function
void POP(struct STACK **Top)
{
	struct STACK *TempNode = NULL;

	if(IsEmpty(*Top))
	{
		printf("Stack UnderFlow\n");
	}	//end if
	else
	{
		printf("POP Element Are: %d\n",(*Top)->Data);
		TempNode = *Top;
		*Top = (*Top)->Next;

		free(TempNode);
	}	//end else
}	//end POP-Function


//main-Function
void main()
{
	struct STACK *Top = NULL;
	int Choice;

	do
	{
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("0. Exit\n");
		
		printf("Enter Your Choice: ");
		scanf("%d",&Choice);
		
		switch(Choice)
		{
		case 1:
			PUSH(&Top);
			break;

		case 2:
			POP(&Top);
			break;

		case 0:printf("Thank You\n");
			break;			
		
		}	//end switch
	}while(Choice!=0);	//end do-while

	getch();
}	//end main