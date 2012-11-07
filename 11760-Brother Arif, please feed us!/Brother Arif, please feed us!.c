#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 10002

int main()
{
	int i,j,k,l,m,n,t,x,y,r,c,blank=0,test=0,esc,row[SZ],col[SZ];
	while(scanf("%d %d %d",&r,&c,&n) && (r||c||n))
	{
		Clear(row,0);
		Clear(col,0);
		For(i,n)
		{
			scanf("%d %d",&x,&y);
			row[x]=col[y]=1;
		}
		scanf("%d %d",&x,&y);
		esc=0;
		if(x-1>=0 && !(row[x-1]||col[y])) esc=1;
		else if(x+1<r && !(row[x+1]||col[y])) esc=1;
		else if(y-1>=0 && !(row[x]||col[y-1])) esc=1;
		else if(y+1<c && !(row[x]||col[y+1])) esc=1;
		else if(!(row[x]||col[y])) esc=1;
		if(esc) printf("Case %d: Escaped again! More 2D grid problems!\n",++test);
		else printf("Case %d: Party time! Let's find a restaurant!\n",++test);
	}
	return 0;
}
