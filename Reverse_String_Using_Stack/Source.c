#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct STACK
{
	char Ch;
	struct STACK* Next;
};


//CreateNode-Function
struct STACK* CreateNode(char c)
{
	struct STACK* NewNode = NULL;

	NewNode = (struct STACK*)malloc(sizeof(struct STACK));

	if(NewNode==NULL)
	{
		printf("Stack Is Full....!!\n");
	}	//end if
	else
	{
		NewNode->Ch = c;
		NewNode->Next = NULL;
	}	//end else

	return NewNode;
}	//end CreateNode-Function


//PUSH-Function
void PUSH(struct STACK** stack , char c)
{
	struct STACK* NewNode = CreateNode(c);

	if(*stack==NULL)
	{
		*stack = NewNode;
	}	//end if
	else
	{
		NewNode->Next = *stack;
		*stack = NewNode;
	}	//end else

}	//end PUSH-Function


//POP-Function
void POP(struct STACK** stack)
{
	char c;
	struct STACK* TempNode = NULL;

	c = (*stack)->Ch;
	TempNode = *stack;

	*stack = (*stack)->Next;
	free(TempNode);

	printf("%c",c);
}	//end POP-Function


//main-Function
void main()
{
	char Str[100];
	int i;
	struct STACK* stack = NULL;

	printf("Enter String => ");
	fgets(Str,100,stdin);

	i = 0 ;
	while(Str[i] != '\n')
	{
		PUSH(&stack ,Str[i]);
		i++;
	}	//end while


	printf("String In Reverse Order Is=> ");
	while(i!=0)
	{
		POP(&stack);
		i--;
	}	//end while

	getch();
}	//end main-Function