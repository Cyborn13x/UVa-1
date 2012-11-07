#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10195
 *
 *language-ANSI C
 *
 *
 */
int main()
{
      double a;
      double b;
      double c;
      double R;
	while(scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
	      if (b+c<=a || c+a<=b || a+b<=c )
	      {
                  printf ("The radius of the round table is: 0.000\n");
                  continue;
            }
		R=0.5*sqrt(((a+b-c)*(b+c-a)*(c+a-b))/(a+b+c));
		printf("The radius of the round table is: %.3lf\n",R);
	}
	return 0;
}
