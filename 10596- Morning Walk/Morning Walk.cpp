#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int i,j,IntersectionPoints[200],NumberOfIntersection,NumberOfRoads,a,b,flag;
	while(scanf("%d %d",&NumberOfIntersection,&NumberOfRoads)==2)
	{
	    flag=1;
	    if(NumberOfIntersection==0 || NumberOfRoads==0)
	    {
	        printf("Not Possible\n");
	        continue;
	    }
		for(i=0;i<NumberOfIntersection;i++)
		{
			IntersectionPoints[i]=0;
		}
		for(i=0;i<NumberOfRoads;i++)
		{
			scanf("%d %d",&a,&b);
			IntersectionPoints[a]++;
			IntersectionPoints[b]++;
		}
		for(i=0;i<NumberOfIntersection;i++)
		{
			if(IntersectionPoints[i]==0)
			{
			    printf("Not Possible\n");
			    flag=0;
			    break;
			}
		}
		if(!flag)
		{
		    continue;
		}
		for(i=0;i<NumberOfIntersection;i++)
		{
			if(IntersectionPoints[i]%2==1)
			{
			    printf("Not Possible\n");
			    flag=0;
			    break;
			}
		}
		if(!flag)
		{
		    continue;
		}
		printf("Possible\n");
	}
	return 0;
}
