#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/*problem id-10943
 *
 *language-ANSI C
 *
 */

unsigned long long Field[102][102];

void Build()
{
    int i;
    int j;
    for(i=0;i<102;i++) Field[1][i]=Field[i][0]=1;
    for(i=2;i<102;i++) for(j=1;j<102;j++) Field[i][j] = (Field[i-1][j]+Field[i][j-1])%1000000;
    return;
}

int main()
{
	int m;
	int n;
    Build();
	while(scanf("%d %d",&n,&m)==2 && n && m) printf("%llu\n",Field[m][n]);
	return 0;
}
