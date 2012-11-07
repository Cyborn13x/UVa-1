#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void initial(int *a)
{
    int n1=0,n2=1,sum;
    for(int i=0;i<50;i++)
    {
    	sum=n1+n2;
    	a[i]=sum;
    	n1=n2;
    	n2=sum;
    }
    return;
}
int main()
{
	int a[50],Pattern;
	initial(a);
	while(1)
	{
	    scanf("%d",&Pattern);
	    if(!Pattern)
	    {
	        break;
	    }
	    printf("%d\n",a[Pattern-1]);
	}
	return 0;
}
