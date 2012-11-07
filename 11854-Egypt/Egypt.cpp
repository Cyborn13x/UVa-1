#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void Swap(int *Number1,int *Number2)
{
      int temp;
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
void BubbleSort(int *ptr,int NumberOfElement)
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
	int a[3],n1,n2;
	while(1)
	{
	    scanf("%d %d %d",&a[0],&a[1],&a[2]);
	    if(a[0]==0 && a[1]==0 && a[2]==0)
	    {
	        break;
	    }
	    BubbleSort(a,3);
	    n1=a[2]*a[2];;
	    n2=a[1]*a[1]+a[0]*a[0];
	    if(n1==n2)
	    {
	        printf("right\n");
	    }
	    else
	    {
	        printf("wrong\n");
	    }
	}
	return 0;
}
