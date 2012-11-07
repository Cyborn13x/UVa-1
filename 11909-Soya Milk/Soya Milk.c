#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979323846

/*problem id-11909
 *
 *language-ANSI C
 *
 */

int main()
{
	double tan,l,w,h,O,PI=pi/180;
      while(scanf("%lf %lf %lf %lf",&l,&w,&h,&O)!=EOF)
      {
      	tan=l*sin(O*PI)/cos(O*PI);
      	if(tan<=h) printf("%.3lf mL\n",l*h*w-(tan*l*w)/2);
            else printf("%.3lf mL\n",(h*h*sin((90-O)*PI)/cos((90-O)*PI)*w)/2);
      }
	return 0;
}
