#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 1002

/*problem id-10739
 *
 *language-ANSI C
 *
 */

int data[SZ][SZ];
char a[SZ];

int mini(int a,int b) { return a<b ? a : b; }

int min(int a,int b,int c) { return mini(a,mini(b,c)); }

int DP(int x,int y)
{
      if(data[x][y]) return data[x][y];
      if(y-x<1) return 0;
      if(a[x-1]==a[y-1]) return data[x][y]=DP(x+1,y-1);
      return data[x][y]=1+min(DP(x+1,y),DP(x,y-1),DP(x+1,y-1));
}

int main()
{
	int n,test=0;
	scanf("%d",&n);
	while(n--)
	{
	      memset(data,0,SZ*SZ*sizeof(int));
		scanf("%s",a);
		printf("Case %d: %d\n",++test,DP(1,strlen(a)));
	}
	return 0;
}
