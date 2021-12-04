#include<stdio.h>
#include<conio.h>

//Search-Function
void Search(int A[] , int Check , int Low , int High)
{
	int Flag=0;

	while(Low<=High)
	{
		if(Check==A[Low])
		{
			printf("Element Found\n");
			Flag=1;
			break;
		}	//end if
		else if(Check==A[High])
		{
			printf("Element Found\n");
			Flag=1;
			break;
		}	//end else-if
		else
		{
			Low++;
			High--;
		}	//end else
	}	//end while
	
	if(Flag==0)
	{
		printf("Element Not Found\n");
	}	//end if

}	//End Search-Function


//main-Function
void main()
{
	int A[100] , n , i , Check;

	printf("Enter Array Size: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter Element At Index %d: ",i);
		scanf("%d",&A[i]);
	}	//end for

	printf("Enter Element To Be Searched: ");
	scanf("%d",&Check);

	Search(A,Check,0,n-1);

	getch();
}	//end main