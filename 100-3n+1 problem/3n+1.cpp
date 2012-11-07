#include<stdio.h>

unsigned long int CycleLength(unsigned long int number);

int main()
{
	unsigned long int CycleLengthOfNumber,MaximumCycleLength,StartNumber,EndNumber,j;
	while(scanf("%lu %lu",&StartNumber,&EndNumber)==2)
	{
	      MaximumCycleLength=0;
	      if(StartNumber<=EndNumber)
	      {
                  for(j=StartNumber;j<=EndNumber;j++)
                  {
                        CycleLengthOfNumber=CycleLength(j);
                        if(CycleLengthOfNumber>MaximumCycleLength)
                        {
                              MaximumCycleLength=CycleLengthOfNumber;
                        }
                  }
	      }
	      else if(StartNumber>EndNumber)
	      {
                  for(j=EndNumber;j<=StartNumber;j++)
                  {
                        CycleLengthOfNumber=CycleLength(j);
                        if(CycleLengthOfNumber>MaximumCycleLength)
                        {
                              MaximumCycleLength=CycleLengthOfNumber;
                        }
                  }
         }
         printf("%lu %lu %lu\n",StartNumber,EndNumber,MaximumCycleLength);
	}
	return 0;

}

unsigned long int CycleLength(unsigned long int Number)
{
	int i=1;
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
