#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int BubbleSort(int *ptr,int NumberOfElement);
void Swap(int *Number1,int *Number2);

int main()
{
	int j,i,NumberOfElement,a[5],LengthOfTrain[50],NumberOfSwapping;
	while(scanf("%d",&NumberOfElement)==1)
	{
        for(j=0;j<NumberOfElement;j++)
        {
            scanf("%d",&LengthOfTrain[j]);
        }
        NumberOfSwapping=BubbleSort(LengthOfTrain,NumberOfElement);
        printf("Minimum exchange operations : %d\n",NumberOfSwapping);
	}
	exit(0);
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
