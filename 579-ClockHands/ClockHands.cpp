#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*579
 *
 *
 *
 */
int main()
{
	int h,m;
	float ang,hang,mang;
	while(scanf("%d:%d",&h,&m)==2)
	{
	      if(!h && !m) break;
	      ang=0;
	      hang=30*h;
	      mang=m*1.0/60.0*360;
	      hang+=mang/360.0*30.0;
	      ang=fabs(hang-mang);
            if(ang>180) ang=360-ang;
            printf("%.3f\n",ang);
	}
	return 0;
}
