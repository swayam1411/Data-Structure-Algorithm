#include<stdio.h>
#include<conio.h>

//Selection_Sort-Function
void Selection_Sort(int A[],int n)
{
	int i , j , Temp;

	// Logic for Sorting
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if( A[i] > A[j] )
			{
				Temp = A[i];
				A[i] = A[j];
				A[j] = Temp;
			}	//end if
		}	//end for
	}	//end for
}	//end Selection_Sort-Function


//main-Function
void main()
{
	int A[100]; 
	int n , i ;

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

	
	Selection_Sort(A,n);

	
	printf("Array After Sorting is:[ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}	//end for
	printf("]\n");

	getch();
}	//end main-Function