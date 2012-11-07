#include<stdio.h>
#include<stdlib.h>

unsigned long int Reverse(unsigned long int n1);

int main()
{
	int n,i,j;
	unsigned long int number;
	scanf("%lu",&n);
	for(i=1;i<=n;i++)
	{
	      scanf("%lu",&number);
	      j=0;
		while(number!=Reverse(number))
		{
		      number+=Reverse(number);
		      j++;
		}
            printf("%d %lu\n",j,number);
	}
	exit(0);
}

unsigned long int Reverse(unsigned long int n1)
{
      unsigned long int n=0,m;
      while(1)
      {
            n=(n*10)+(n1%10);
            n1/=10;
            if(n1==0)break;
      }
      return n;
}
