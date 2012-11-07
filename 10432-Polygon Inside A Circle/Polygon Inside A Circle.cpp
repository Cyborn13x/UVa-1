#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	double Radius,area,pi=3.141592653589793;
	while(scanf("%lf %d",&Radius,&n)!=EOF)
	{
		area=(n*Radius*Radius/2)*sin(2*pi/n);
		printf("%.3lf\n",area);
	}
	return 0;
}
