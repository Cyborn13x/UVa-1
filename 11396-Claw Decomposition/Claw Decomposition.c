#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11396
 *
 *language-ANSI C
 *
 */

int AdjList[302][3];
int clr[302];
int n;

int Bicolor(int x,int color)
{
      if(clr[x]!=-1) return clr[x]==color;
      clr[x]=color;
      color=!color;
      return (Bicolor(AdjList[x][0],color)&&Bicolor(AdjList[x][1],color)&&Bicolor(AdjList[x][2],color));
}

int check()
{
      int i;
      for(i=1;i<=n;i++) if(clr[i]==-1) if(!Bicolor(i,1)) return 0;
      return 1;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	int x;
	int y;
	int len[302];
	while(scanf("%d",&n) && n)
	{
	      memset(len,0,sizeof(len));
	      for(i=1;i<=n;i++) clr[i]=-1;
		while(scanf("%d %d",&x,&y))
		{
			if(!x && !y) break;
			AdjList[x][len[x]++]=y;
			AdjList[y][len[y]++]=x;
		}
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
