#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000

/*problem id-11586
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,f,t,x,y,blank=0,test=0;
	char a[1000],*p;
	scanf("%d\n",&t);
	while(t--)
	{
		gets(a); x=m=f=0;
		p=strtok(a," ");
		while(p!=NULL)
		{
			x++;
			p[0]=='M' ? m++ : f++;
			p[1]=='M' ? m++ : f++;
			p=strtok(NULL," ");
		}
		if(x>1 && m==f) printf("LOOP\n");
		else printf("NO LOOP\n");
	}
	return 0;
}
