#include<stdio.h>
#include<conio.h>


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
	
	k=0;
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


//Binary_Search-Function
void Binary_Search(int A[] , int Check , int Low , int High)
{
	int Mid , Flag;
	
	Flag=0;
	while(Low<=High)
	{
		Mid = (Low+High)/2;
		
		if(A[Mid]==Check)
		{
			printf("Element Found\n");
			Flag=1;
			break;
		}	//end if
		else if(Check<A[Mid])
		{
			High=Mid-1;
		}	//end else-if
		else
		{
			Low=Mid+1;
		}	//end else	
	}	//end while

	if(Flag==0)
	{
		printf("Element Not Found\n");
	}	//end if

}	//End Binary_Search-Function


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

	MergeSort(A,0,n-1);

	Binary_Search(A,Check,0,n-1);

	getch();
}	//end main