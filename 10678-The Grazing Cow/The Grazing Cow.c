#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define PI 3.141592653589793238462643383279502884197

/*problem id-10678
 *
 *language-C++
 *
 */

/*Theory--
 *The area is an ellips
 *Area of an ellips is pi*a*b
 *
 */
int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	double L,D,ans,e,ae,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf",&D,&L);
		a=L/2;// উপবৃত্তের উপর আবস্থিত কোন বিন্দুর উপকেন্দ্র দুটি থেকে দুরত্তের যোগফল বৃহৎ অক্ষের সমান । বৃহৎ অক্ষ = 2*a.
		ae=D/2;
		e=ae/a;// উপবৃত্তের দুটি উপকেন্দ্রের দুরত্ত = 2*a*e. e = sqrt(1-(b*b)/(a*a)).
		b=sqrt((1-e*e)*(a*a));
		ans=PI*a*b;
		printf("%.3lf\n",ans);
	}
	return 0;
}
