#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*
 *Problem id-694
 *Language-C++
 *
 */

int CycleLength(unsigned long int Number,int UpperLimit)
{
	long long int i=1;
	if(Number==1)
	{
	      return i;
	}
	else
	{
	      while(1)
            {
                  if(Number%2==0)
                  {
                        Number=Number/2;
                  }
                  else
                  {
                        Number=3*Number+1;
                  }
                  i++;
                  if(Number==1)return i;
                  else if(Number>UpperLimit)return i-1;
            }
	}
}

int main()
{
	int f,l,i,j;
	for(i=1;;i++)
	{
	      scanf("%d %d",&f,&l);
		if(f<0 && l<0)break;
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",i,f,l,CycleLength(f,l));
	}
	return 0;
}
