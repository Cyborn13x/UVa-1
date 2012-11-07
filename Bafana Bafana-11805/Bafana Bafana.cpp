#include<stdio.h>

int main()
{
	int t,TestCase,TotalPass,PlayerNumber,TotalPlayer;
	scanf("%d",&TestCase);
	for(int i=1;i<=TestCase;i++)
	{
		scanf("%d %d %d",&TotalPlayer,&PlayerNumber,&TotalPass);
		t=TotalPass+PlayerNumber;
		if(t>TotalPlayer)
		{
		      if(t%TotalPlayer)
		      {
		            printf("Case %d: %d\n",i,t%TotalPlayer);
		      }
		      else
		      {
		            printf("Case %d: %d\n",i,TotalPlayer);
		      }
		}
		else
		{
		      printf("Case %d: %d\n",i,TotalPass+PlayerNumber);
		}
	}
	return 0;
}
