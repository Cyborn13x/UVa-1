#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 102

/*problem id-11835
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0,cnt,lim,race,pilot,rule,MaxScore,rank[SZ][SZ],score[SZ],point[SZ];
	while(scanf("%d %d",&race,&pilot) && (race || pilot))
	{
		FOR(i,race) FOR(j,pilot) { scanf("%d",&x); rank[i][x-1]=j; }
		scanf("%d",&rule);
		while(rule--)
		{
		      CLEAR(score); MaxScore=-INF, k=0;
			scanf("%d",&lim);
			FOR(i,lim) scanf("%d",&point[i]);
			FOR(i,race) FOR(j,lim) score[rank[i][j]]+=point[j];
			FOR(i,pilot) MaxScore=max(MaxScore,score[i]);
			FOR(i,pilot)
			{
			      if(score[i]!=MaxScore) continue;
                        if(k) putchar(' ');
                        printf("%d",i+1); k=1;
			}printf("\n");
		}
	}
	return 0;
}
