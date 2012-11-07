#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,counter,n,cpy;
	for(i=1;;i++)
	{
	      cpy=1;
	      counter=0;
	      scanf("%d",&n);
	      if(n<=0)
	      {
	            break;
	      }
	      if(n==1)
	      {
	            printf("Case %d: %d\n",i,counter);
	            continue;
	      }
	      while(1)
	      {
	            cpy*=2;
	            counter++;
	            if(cpy>=n)
	            {
	                  break;
	            }
	      }
	      printf("Case %d: %d\n",i,counter);
	}
      return 0;
}
