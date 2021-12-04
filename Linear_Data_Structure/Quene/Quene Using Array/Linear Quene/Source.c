#include<stdio.h>
#include<conio.h>
#define Max 5

struct QUENE
{
	int A[Max] ;
	int Front ;
	int Rear ;
};


//IsFull-Function
int IsFull(struct QUENE* QuenePtr)
{
	if(QuenePtr->Rear==Max-1)
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
	if(QuenePtr->Rear==QuenePtr->Front)
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

	QuenePtr->Rear = QuenePtr->Rear + 1;

	printf("Enter Value: ");
	scanf("%d",&Value);

	QuenePtr->A[QuenePtr->Rear] = Value;

}	//end enquene-Function


//dequene-Function
void dequene(struct QUENE* QuenePtr)
{
	int Data;
	
	QuenePtr->Front = QuenePtr->Front + 1;

	Data = QuenePtr->A[QuenePtr->Front];

	printf("DeQuene Element is => %d\n",Data);
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
			if(IsFull(&Quene))
			{
				printf("Quene Overflow\n");
			}	//end if
			else
			{
				enquene(&Quene);
			}	//end else
			break;

		case 2:
			if(IsEmpty(&Quene))
			{
				printf("Quene UnderFlow\n");
			}	//end if
			else
			{
				dequene(&Quene);
			}	//end else
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