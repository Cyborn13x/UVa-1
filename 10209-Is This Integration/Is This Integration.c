#include <stdio.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define pi 3.14159265358979323846

/*problem id-10209
 *
 *language-ANSI C
 *
 *Integration problem. অত্যন্ত মজার ইন্টিগ্রেশন ।
 */

double a,rem,strip,dot,sqrt3=sqrt(3);

double Area()
{
      double A=a*a;
      rem=(8*(A/2-(pi*A)/12-(sqrt3*A)/8));
      strip=(2*((pi*A)/2-A)-(A-rem));
      dot=A-rem-strip;
      return;
}

int main()
{
	while(scanf("%lf",&a)!=EOF)
	{
		Area();
		printf("%.3lf %.3lf %.3lf\n",strip,dot,rem);
	}
	return 0;
}
