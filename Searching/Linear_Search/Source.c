#include<stdio.h>
#include<conio.h>

//Linear_Search-Function
void Linear_Search (int A[] ,int n)
{
	int i , Search , Flag;

	printf("Enter Element To Be Searched: ");
	scanf("%d",&Search);

	Flag=0;
	for(i=0;i<n;i++)
	{
		if(Search==A[i])
		{
			printf("Element Found\n");
			Flag=1;
			break;
		}	//end if
	}	//end for

	if(Flag==0)
	{
		printf("Element Not Found\n");
	}	//end if

}	//End Linear_Search-Function


//main-Function
void main()
{
	int A[100] , n , i;

	printf("Enter Array Size: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter Element At Index %d: ",i);
		scanf("%d",&A[i]);
	}	//end for


	Linear_Search (A,n);

	getch();
}	//end main
