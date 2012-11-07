#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11461
 *
 *language-ANSI C
 *
 *
 */

int s[100001];

int main()
{
	int i;
	unsigned long long int j;
	int n;
	int m;
	int p;
	s[1]=1;
	for(i=2;i<318;i++) if(!s[i]) for(j=(i*i);j<100001;j*=(i*i)) s[j]=1;
	while(scanf("%d %d",&n,&m)==2 && (n || m))
	{
	      p=0;
		for(i=n;i<=m;i++) if(s[i]) p++;
		printf("%d\n",p);
	}
	return 0;
}
