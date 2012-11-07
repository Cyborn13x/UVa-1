#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-499
 *
 *language-ANSI C
 *
 *
 */


int main()
{
	int i;
	int j;
	int n;
	int l;
	int m;
	int a[200];
	char s[10000];
	char c;
	while(1)
	{
	      n=scanf("%[^\n]",s);
	      if(n==EOF) break;
	      scanf("%c",&c);
	      m=0;
	      memset(a,0,sizeof(int)*200);
		l=strlen(s);
		for(i=0;i<l;i++) if(isalpha(s[i])) a[s[i]]++;
		for(i=0;i<200;i++) m=a[i]>m ? a[i]:m;
		for(i=0;i<200;i++) if(m==a[i]) printf("%c",i);
		printf(" %d\n",m);
	}
	return 0;
}
