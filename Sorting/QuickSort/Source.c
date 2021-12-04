#include<stdio.h>
#include<conio.h>


//PrintArray-Function
void printArray(int A[] , int n)
{
	int i;
	printf("Array Elements Are:[ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}	//end for
	printf("]\n");
}	//end printArray-Function


//QuickSort-Function
void QuickSort(int A[] , int L , int H)
{
	int Low , High , Pivot , Temp;

	Pivot = A[L];
	Low = L+1;
	High = H;

	while(Low <= High)
	{
		while(A[Low] <= Pivot)
		{
			Low++;
		}	//end while

		while(A[High] > Pivot)
		{
			High--;
		}	//end while

		if(Low <= High)
		{
			Temp = A[Low];
			A[Low] = A[High];
			A[High] = Temp;

			Low++;
			High--;
		}	//end if

	}	//end while

	Temp = A[L];
	A[L] = A[High];
	A[High] = Temp;

	if(L<High-1)
	{
		QuickSort(A,L,High-1);
	}	//end if

	if(Low<H)
	{
		QuickSort(A,Low,H);
	}	//end if

}	//end QuickSort-Function


//main-Function
void main()
{
	int A[100] , n , i;

	//Taking Array Size
	printf("How Many Numbers: ");
	scanf("%d",&n);

	//Taking Array Elements
	for(i=0;i<n;i++)
	{
		printf("Enter Element At Index %d: ",i);
		scanf("%d",&A[i]);
	}	//end for

	printf("Array Before Sorting is\n");
	printArray(A,n);	//For Printing Original Array
	
	QuickSort(A,0,n-1);		//For Sort Array Using QuickSort-Function
	
	printf("Array After Sorting is\n");
	printArray(A,n);	//For Printing Sorted Array

	getch();

}	//end main-Function