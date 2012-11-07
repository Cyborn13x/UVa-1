#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*Here 'NumberOfElement' means total number of
 *variable in the array .
 *Not the Array Index
 *NumberOfElement=ArrayIndex+1
 *
 *'TheNumber' is the number to be inserted in the Array .
 *
 */

void InsertionSort(int *a,int NumberOfElement,int TheNumber)
{
    for(int j=0;j<NumberOfElement;j++)
    {
    	if(TheNumber>a[j])
    	{
    	    continue;
    	}
    	else
    	{
    	    for(int m=NumberOfElement-1;m>=j;m--)
    	    {
    	    	a[m+1]=a[m];
    	    }
    	    a[j]=TheNumber;
    	    return;
    	}
    }
}

int Median(int *a,int i)//Here 'i' is the array index
{
    if(i%2==0)
    {
        return a[i/2];
    }
    return ((a[i/2]+a[i/2+1])/2);
}

int main()
{
	int n,i=0,a[10000];
	for(i=0;i<10000;i++)
	{
		a[i]=2147483647;
	}
	i=0;
	while(scanf("%d",&n)==1)
	{
	    a[i]=n;
	    InsertionSort(a,i+1,n);
	    printf("%d\n",Median(a,i));
	    i++;
	}
	return 0;
}
