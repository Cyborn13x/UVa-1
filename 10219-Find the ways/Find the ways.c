#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20000005

/*problem id-10219
 *
 *language-ANSI C
 *
 */

double lg[SIZE],ans;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0;
	for(i=2,lg[1]=0;i<SIZE;i++) lg[i]=lg[i-1]+log10(i);
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		ans=lg[n]-lg[m]-lg[n-m];
		x=ans; x++;
		printf("%d\n",x);
	}
	return 0;
}
