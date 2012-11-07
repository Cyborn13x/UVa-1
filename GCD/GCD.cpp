#include<stdio.h>
//------------------------------------------------
int gcd(int a,int b);
//------------------------------------------------
int main()
{
	int N,i,j,sum;
	for(;;)
	{
	      sum=0;
	      scanf("%d",&N);
	      if(N==0)
	      {
	            break;
	      }
	      for(i=1;i<=N;i++)
	      {
	            for(j=i+1;j<=N;j++)
	            {
	            	sum+=gcd(i,j);
	            }
	      }
	      printf("%d\n",sum);
	}
	return 0;
}
//------------------------------------------------
int gcd(int a,int b)
{
      int t=100;
      while(t!=0)
      {
            t=a%b;
            a=b;
            b=t;
      }
      return a;
}
