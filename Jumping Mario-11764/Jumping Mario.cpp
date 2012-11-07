#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
	int TestCase,i,j,NumberOfPiller,Piller[50],HighJump,LowJump;
	scanf("%d",&TestCase);
	for(i=1;i<=TestCase;i++)
	{
	      HighJump=0;
	      LowJump=0;
		scanf("%d",&NumberOfPiller);
		for(j=0;j<NumberOfPiller;j++)
		{
			scanf("%d",&Piller[j]);
		}
		for(j=0;j<NumberOfPiller-1;j++)
		{
			if(Piller[j]<Piller[j+1])HighJump++;
			else if(Piller[j]>Piller[j+1])LowJump++;
			else continue;
		}
		printf("Case %d: %d %d\n",i,HighJump,LowJump);
	}
	return 0;
}


