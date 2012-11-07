#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void Swap(unsigned long int *Number1,unsigned long int *Number2)
{
      unsigned long int temp;
      temp=(*Number1);
      *Number1=*Number2;
      *Number2=temp;
      return;
}
/*Here NumberOfElement means total number of
 *variable in the array .
 *Not the Array Index
 *NumberOfElement=ArrayIndex+1
 */
void BubbleSort(unsigned long int *ptr,unsigned long int NumberOfElement)
{
    int i,j;
    for(i=0;i<NumberOfElement;i++)
	{
		for(j=0;j<(NumberOfElement-1);j++)
		{
			if(ptr[j]>ptr[j+1])
			{
			      Swap(&ptr[j],&ptr[j+1]);
			}
		}
	}
	return;
}

int main()
{
	unsigned long int a[4],TestCase;
	scanf("%lu",&TestCase);
	for(int i=0;i<TestCase;i++)
	{
		scanf("%lu %lu %lu %lu",&a[0],&a[1],&a[2],&a[3]);
		BubbleSort(a,4);
		if(a[0]==0 || a[1]==0 || a[2]==0 || a[3]==0)
		{
		    printf("quadrangle\n");
		}
		else if(a[3]<=a[0]+a[1]+a[2])
		{
		    if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
		    {
		        printf("square\n");
		    }
		    else if(a[0]==a[1] && a[2]==a[3])
            {
                printf("rectangle\n");
            }
            else
            {
                printf("quadrangle\n");
            }
		}
		else
		{
		    printf("banana\n");
		}
	}
	return 0;
}
