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


//Merge-Function
void Merge(int A[] , int Low , int Mid , int High)
{
	int B[100] , i , j , k;

	i = Low;
	j = Mid+1;
	k = 0;

	while(i<=Mid && j<=High)
	{
		if(A[i] < A[j])
		{
			B[k] = A[i];
			k++;
			i++;
		}	//end if
		else
		{
			B[k] = A[j];
			k++;
			j++;
		}	//end else
	}	//end while

	while(i<=Mid)
	{
		B[k] = A[i];
		k++;
		i++;
	}	//end while
	
	while(j<=High)
	{
		B[k] = A[j];
		k++;
		j++;
	}	//end while

	k = 0;
	for(i=Low;i<=High;i++)
	{
		A[i] = B[k];
		k++;
	}	//end for
}	//end Merge-Function


//MergeSort-Function
void MergeSort(int A[] , int Low , int High)
{
	int Mid;

	if(Low < High)
	{
		Mid = (Low+High)/2;
		MergeSort(A,Low,Mid);
		MergeSort(A,Mid+1,High);

		Merge(A,Low,Mid,High);
	}	//end if

}	//end MergeSort-Function


void main()
{
	int A[100] , n , i ;

	printf("Enter Array Size: ");
	scanf("%d",&n);

	//For-loop for Accepting Array Elements
	for(i=0;i<n;i++)
	{
		printf("Enter Element At Index %d: ",i);
		scanf("%d",&A[i]);
	}	//end for

	
	printf("Array Before Sorting is\n");
	printArray(A,n);

	MergeSort(A,0,n-1);

	printf("Array After Sorting is\n");
	printArray(A,n);

	getch();
}	//end main