#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11556
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,b,test,blank;
	unsigned long long s,N;
	while(scanf("%llu %d",&N,&b)!=EOF)
	{
		s=pow(2,b+1)-1;
		if(N<=s) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
