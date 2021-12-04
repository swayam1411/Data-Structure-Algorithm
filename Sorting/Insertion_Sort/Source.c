#include<stdio.h>
#include<conio.h>

//Insertion_Sort-Function
void Insertion_Sort(int A[],int n)
{
	int i , Empty , Temp;

	for(i=1;i<n;i++)
	{
		Temp = A[i];
		Empty = i;

		while(Empty>0 && A[Empty-1]>Temp)
		{
			A[Empty] = A[Empty-1];
			Empty--;
		}	//end while
		A[Empty] = Temp;
	}	//end for
}	//end Insertion_Sort-Function


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


	Insertion_Sort(A,n);

	
	printf("Array After Sorting is:[ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}	//end for
	printf("]\n");

	getch();
}	//end main-Function
