#include<stdio.h>

long long int CycleLength(long long int number);

int main()
{
	long long int CycleLengthOfNumber,MaximumCycleLength,StartNumber,EndNumber,j,m;
	while(scanf("%lld %lld",&StartNumber,&EndNumber)==2 && StartNumber && EndNumber)
	{
	    if(StartNumber==1 && (EndNumber==1 || EndNumber==2))
	    {
	        printf("Between 1 and %lld, 1 generates the longest sequence of 3 values.\n",EndNumber);
	        continue;
	    }
	      MaximumCycleLength=0;
	      if(StartNumber<=EndNumber)
	      {
                  for(j=StartNumber;j<=EndNumber;j++)
                  {
                        CycleLengthOfNumber=CycleLength(j);
                        if(CycleLengthOfNumber>MaximumCycleLength)
                        {
                              MaximumCycleLength=CycleLengthOfNumber;
                              m=j;
                        }
                  }
                  printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",StartNumber,EndNumber,m,MaximumCycleLength-1);
	      }
	      else if(StartNumber>EndNumber)
	      {
                  for(j=EndNumber;j<=StartNumber;j++)
                  {
                        CycleLengthOfNumber=CycleLength(j);
                        if(CycleLengthOfNumber>MaximumCycleLength)
                        {
                              MaximumCycleLength=CycleLengthOfNumber;
                              m=j;
                        }
                  }
                  printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",EndNumber,StartNumber,m,MaximumCycleLength-1);
         }

	}
	return 0;

}

long long int CycleLength(long long int Number)
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
                  if(Number==1)
                  {
                        return i;
                  }
            }
	}
}
