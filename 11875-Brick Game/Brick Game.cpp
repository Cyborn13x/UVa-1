#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int TestCase,NumberOfPlayers,p[11];
	scanf("%d",&TestCase);
	for(int i=0;i<TestCase;i++)
	{
		scanf("%d",&NumberOfPlayers);
		for(int j=0;j<NumberOfPlayers;j++)
		{
			scanf("%d",&p[j]);
		}
		printf("Case %d: %d\n",i+1,p[NumberOfPlayers/2]);
	}
	return 0;
}
