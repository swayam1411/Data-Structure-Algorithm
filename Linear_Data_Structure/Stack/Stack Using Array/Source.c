#include<stdio.h>
#include<conio.h>
#define Max 10

struct STACK
{
	int Top;
	int A[Max];
};


//Inti_Stack-Function
void Inti_Stack(struct STACK *Stackptr)
{
	Stackptr->Top=-1;
}	//end Inti_Stack-Function


//IsFull-Function
int IsFull(struct STACK *Stackptr)
{
	if( Stackptr->Top == Max-1)
	{
		return 1;
	}	//end if
	else
	{
		return 0;
	}	//end else

}	//end IsFull-Function


//IsEmpty-Function
int IsEmpty(struct STACK *Stackptr)
{

	if( Stackptr->Top == -1)
	{
		return 1;
	}	//end if
	else
	{
		return 0;
	}	//end else

}	//end IsEmpty-Function


//PUSH-Function
void PUSH(struct STACK *Stackptr)
{
	int data;

	Stackptr->Top++;
	
	printf("Enter Value: ");
	scanf("%d",&data);

	Stackptr->A[Stackptr->Top] = data;
}	//end PUSH-Function


//POP-Function
void POP(struct STACK *Stackptr)
{
	int data;
	data = Stackptr->A[Stackptr->Top];
	Stackptr->Top--;

	printf("POP Element Are: %d\n",data);
}	//end POP-Function

//main-Function
void main()
{
	struct STACK Stack;
	int Choice;

	Inti_Stack(&Stack);

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
			if(IsFull(&Stack))
			{
				printf("Stack OverFlow\n");
			}	//end if
			else
			{
				PUSH(&Stack);
			}	//end else
			break;

		case 2:
			if(IsEmpty(&Stack))
			{
				printf("Stack UnderFlow\n");
			}	//end if
			else
			{
				POP(&Stack);
			}	//end else
			break;
	

		case 0:printf("Thank You\n");
			break;			
		
		}	//end switch
	}while(Choice!=0);	//end do-while

	getch();
}	//end main