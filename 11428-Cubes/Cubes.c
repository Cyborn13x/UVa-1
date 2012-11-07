#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11428
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
      while(scanf("%d",&n) && n)
      {
      	m=sqrt(n);k=1;
      	for(i=2;i<=m && k;i++) for(j=1;j<i && k;j++) if(n==(i*i*i)-(j*j*j)){printf("%d %d\n",i,j);k=0;}
      	if(k)printf("No solution\n");
      }
	return 0;
}
