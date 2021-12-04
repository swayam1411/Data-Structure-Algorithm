#include<stdio.h>
#include<conio.h>
#define Max 3

struct QUENE
{
	int A[Max] ;
	int Front ;
	int Rear ;
};


//IsFull-Function
int IsFull(struct QUENE* QuenePtr)
{
	if((QuenePtr->Rear+1)%Max==QuenePtr->Front)
	{
		return 1;
	}	//end if
	else
	{
		return 0;
	}	//end else
}	//end IsFull-Function


//IsEmpty-Function
int IsEmpty(struct QUENE* QuenePtr)
{
	if(QuenePtr->Front==-1)
	{
		return 1;
	}	//end if
	else
	{
		return 0;
	}	//end else
}	//end IsEmpty-Function


//enquene-Function
void enquene(struct QUENE* QuenePtr)
{
	int Value;

	if(IsFull(QuenePtr))
	{
		printf("Quene Is Full\n");
	}	//end if
	else
	{
		printf("Enter Value: ");
		scanf("%d",&Value);

		if(QuenePtr->Front==-1)
		{
			QuenePtr->Front = 0;
			QuenePtr->Rear = 0;
		}	//end if
		else
		{
			QuenePtr->Rear = (QuenePtr->Rear+1)%Max;
		}	//end else
		QuenePtr->A[QuenePtr->Rear] = Value;
	}	//end else

}	//end enquene-Function


//dequene-Function
void dequene(struct QUENE* QuenePtr)
{
	int Value;

	if(IsEmpty(QuenePtr))
	{
		printf("Quene Is Empty\n");
	}	//end if
	else
	{
		Value = QuenePtr->A[QuenePtr->Front];

		if(QuenePtr->Front==QuenePtr->Rear)
		{
			QuenePtr->Front = -1;
			QuenePtr->Rear = -1;
		}	//end if
		else
		{
			QuenePtr->Front = (QuenePtr->Front+1)%Max;
		}	//end else
		printf("DeQuene Element Is => %d\n",Value);
	}	//end else

}	//end dequene-Function


//Inti_Quene-Function
void Inti_Quene(struct QUENE* QuenePtr)
{
	QuenePtr->Front = -1;
	QuenePtr->Rear = -1;
}	//end Inti_Quene-Function


void main()
{
	struct QUENE Quene;
	int choice;

	Inti_Quene(&Quene);

	do
	{
		printf("1. EnQuene\n");
		printf("2. DeQuene\n");
		printf("0. Exit\n");

		printf("Enter Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{

		case 1:
			enquene(&Quene);
			break;

		case 2:
			dequene(&Quene);
			break;

		case 0:
			printf("Thank You\n");
			break;

		default:
			printf("Invalid Choice\n");
		
		}	//end switch

	}while(choice!=0);		//end do-while


	getch();
}	//end main