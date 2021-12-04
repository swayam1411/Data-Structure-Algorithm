#include<stdio.h>
#include<conio.h>

//Bubble_Sort-Function
void Bubble_Sort(int A[],int n)
{
	int i , j , Temp;
	// Logic for Sorting
	for(i=1;i<n;i++)
	{
		for(j=0;j<(n-i);j++)
		{
			if( A[j] > A[j+1] )
			{
				Temp = A[j];
				A[j] = A[j+1];
				A[j+1] = Temp;
			}	//end if
		}	//end for
	}	//end for
}	//end Bubble_Sort-Function
//main-Function
void main()
{
	int A[100]; 
	int n , i , j , Temp ;

	printf("Enter Array Size: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter Value at Index %d : ",i);
		scanf("%d",&A[i]);
	}	//end for


	printf("Array Before Sorting is:[ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}	//end for
	printf("]\n");


	Bubble_Sort(A,n);

	
	printf("Array After Sorting is:[ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}	//end for
	printf("]\n");

	getch();
}	//end main-Function