#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void Swap(long int *Number1,long int *Number2)
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
void BubbleSort(long int *ptr,int NumberOfElement)
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
	long int TestCase,i,a,b,c,side[3];
	scanf("%ld",&TestCase);
	for(i=0;i<TestCase;i++)
	{
		scanf("%ld %ld %ld",&side[0],&side[1],&side[2]);
		BubbleSort(side,3);
		c=side[0];
		b=side[1];
		a=side[2];
		if(a==0 || b==0 || c==0)
		{
		    printf("Case %ld: Invalid\n",i+1);
		}
		else if(a<0 || b<0 || c<0)
		{
		    printf("Case %ld: Invalid\n",i+1);
		}
		else if((b+c)>a)
		{
		    if(a==b && b==c)
            {
                printf("Case %ld: Equilateral\n",i+1);
            }
            else if((a==b && c!=a) || (c==b && c!=a) || (a==c && b!=a))
            {
                printf("Case %ld: Isosceles\n",i+1);
            }
            else if(a!=b && b!=c && c!=a)
            {
                printf("Case %ld: Scalene\n",i+1);
            }
        }
        else
        {
            printf("Case %ld: Invalid\n",i+1);
        }
    }
	return 0;
}
