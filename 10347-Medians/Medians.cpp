#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	double u,v,w,area;
	while(scanf("%lf %lf %lf",&u,&v,&w)!=EOF)
	{
		area=(2.0*(u*u*v*v+v*v*w*w+u*u*w*w)-(u*u*u*u+v*v*v*v+w*w*w*w));
		if(u<=0 || v<=0 || w<=0 || area<=0)
		{
		    printf("-1.000\n");
		}
		else
		{
		    area=sqrt(area)/3.0;
		    printf("%.3lf\n",area);
		}
	}
	return 0;
}
