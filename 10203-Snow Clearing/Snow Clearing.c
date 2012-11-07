#include <stdio.h>
#include <math.h>

/*problem id-10203
 *
 *language-ANSI C
 *
 */

int main()
{
	int a,b,c,d,n,t,blank=0;
	double s,v=(2000.0/6.0);
	char line[200];
	scanf("%d",&n);
	while(n--)
	{
	      if(blank) printf("\n");
	      blank=1;
		s=0.0;
		scanf("%d %d\n",&a,&b);
		while(gets(line) && sscanf(line,"%d %d %d %d",&a,&b,&c,&d)==4)
		{
		      s+=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		}
		t=floor((2*s/v)+.5);
		printf("%d:%0.2d\n",t/60,t%60);
	}
	return 0;
}
