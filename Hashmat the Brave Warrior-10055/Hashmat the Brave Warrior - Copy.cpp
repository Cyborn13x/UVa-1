#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
	unsigned long int i,n1,n2;
	while(scanf("%lu %lu",&n1,&n2)==2)
	{
	      if(n1>n2)
	      {
	            printf("%lu\n",n1-n2);
	      }
	      else
	      {
	            printf("%lu\n",n2-n1);
	      }
	}
	return 0;
}
