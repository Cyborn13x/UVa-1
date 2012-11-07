#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int NumberOfInvalidOutput,i,j,m;
	double ha,hb,hc,h,area;
	scanf("%d",&NumberOfInvalidOutput);
	for(i=0;i<NumberOfInvalidOutput;)
	{
		scanf("%lf %lf %lf",&ha,&hb,&hc);
		if(ha<=0||hb<=0||hc<=0)
		{
		    printf("These are invalid inputs!\n");
		    i++;
		    continue;
        }
		h=((1.0/ha)+(1.0/hb)+(1.0/hc))/2.0;
		area=h*(h-(1.0/ha))*(h-(1.0/hb))*(h-(1.0/hc));
		if(area<=0)
		{
		    printf("These are invalid inputs!\n");
		    i++;
		    continue;
		}
		area=(1.0/(4*sqrt(area)));
		printf("%.3lf\n",area);
	}
	return 0;
}
