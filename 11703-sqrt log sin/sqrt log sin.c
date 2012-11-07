#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 1000005

/*problemid-11703
 *
 *language-ANSI C
 *
 */

int data[N];

int main()
{
	int i,j,k,l,m,n,t,y,blank;
	double x;
	data[0]=1;
	for(i=1;i<=N;i++)
	{
	      x=sin(i);
		data[i]=(data[(int)(floor(i-sqrt(i)))]+data[(int)(floor(log(i)))]+data[(int)(floor(i*x*x))])%1000000;
	}
	while(scanf("%d",&n) && n!=-1) printf("%d\n",data[n]);
	return 0;
}
