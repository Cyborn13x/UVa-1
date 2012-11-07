#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-11958
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j;
	int BusNo;
	int CurrentHrs;
	int CurrentMin;
	int CurrentTime;
	int ArriveHrs;
	int ArriveMin;
	int ArriveTime;
	int TravelTime;
	int Difference;
	int MinTime;
	int TestCase;
	scanf("%d",&TestCase);
	for(i=0;i<TestCase;i++)
	{
	      MinTime=99999;
		scanf("%d %d:%d",&BusNo,&CurrentHrs,&CurrentMin);
		CurrentTime=60*CurrentHrs+CurrentMin;
		for(j=0;j<BusNo;j++)
		{
			scanf("%d:%d %d",&ArriveHrs,&ArriveMin,&TravelTime);
			ArriveTime=60*ArriveHrs+ArriveMin;
			if(ArriveTime<CurrentTime) Difference=1440-CurrentTime+ArriveTime+TravelTime;
			else Difference=ArriveTime-CurrentTime+TravelTime;
			if(MinTime>Difference) MinTime=Difference;
		}
		printf("Case %d: %d\n",i+1,MinTime);
	}
	return 0;
}
