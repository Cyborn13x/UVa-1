#include<stdio.h>

int BubbleSort(int *ptr,int NumberOfElement);
void Swap(int *Number1,int *Number2);

int main()
{
	int TestCase,j,i,NumberOfElement,LengthOfTrain[50],NumberOfSwapping;
	scanf("%d",&TestCase);
	for(i=1;i<=TestCase;i++)
	{
            scanf("%d",&NumberOfElement);
            for(j=0;j<NumberOfElement;j++)
            {
            	scanf("%d",&LengthOfTrain[j]);
            }
            NumberOfSwapping=BubbleSort(LengthOfTrain,NumberOfElement);
            printf("Optimal train swapping takes %d swaps.\n",NumberOfSwapping);
	}
	return 0;
}

int BubbleSort(int *ptr,int NumberOfElement)
{
      int i,j,NumberOfSwapping=0;
      for(i=0;i<NumberOfElement;i++)
	{
		for(j=0;j<(NumberOfElement-1);j++)
		{
			if(ptr[j]>ptr[j+1])
			{
			      Swap(&ptr[j],&ptr[j+1]);
			      NumberOfSwapping++;
			}
		}
	}
	return NumberOfSwapping;
}
void Swap(int *Number1,int *Number2)
{
      int temp;
      temp=(*Number1);
      *Number1=*Number2;
      *Number2=temp;
      return;
}
