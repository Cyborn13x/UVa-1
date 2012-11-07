#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-11824
 *
 *language-ANSI C
 *
 *
 */


void BubbleSort(long long int *ptr,long long int N)
{
      long long int i,j,temp;
      for(i=0;i<N;i++)
	{
		for(j=0;j<(N-i-1);j++)
		{
			if(ptr[j]<ptr[j+1])
			{
			      temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
			}
		}
	}
	return;
}

int main()
{
	long long int i;
	long long int j;
	long long int n;
	long long int t;
	long long int sum;
	long long int a[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
            j=0;
		while(1)
		{
                  scanf("%lld",&a[j]);
                  if(!a[j]) break;
                  j++;
		}
		sum=0;
		BubbleSort(a,j);
		for(n=0;n<j;n++)
		{
			sum+=2*pow(a[n],n+1);
		}
		if(sum<=5000000) printf("%lld\n",sum);
		else printf("Too expensive\n");
	}
	return 0;
}
