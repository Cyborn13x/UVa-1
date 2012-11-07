#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 55

/*problem id-10054
 *
 *language-ANSI C
 *
 */

int AdjMat[SZ][SZ],color[SZ],N;

int max(int a,int b) { return a>b ? a : b; }

void EulerTour(int n)
{
      int i;
      for(i=1;i<=N;i++)
      {
      	if(AdjMat[n][i])
      	{
      	      AdjMat[n][i]--, AdjMat[i][n]--;
      	      EulerTour(i);
      	      printf("%d %d\n",i,n);
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,flag;
	scanf("%d",&t);
	while(t--)
	{
	      if(blank) printf("\n");
	      blank=1;
	      memset(AdjMat,0,SZ*SZ*sizeof(int));
	      memset(color,0,SZ*sizeof(int));
		scanf("%d",&n); N=0;
		while(n--)
		{
			scanf("%d %d",&x,&y);
			AdjMat[x][y]++, AdjMat[y][x]++;
			color[x]++, color[y]++;
			N=max(N,max(x,y));
		}
		printf("Case #%d\n",++test);
		for(i=flag=1;i<=N;i++)
		{
			if(color[i]%2)
			{
			      printf("some beads may be lost\n");
			      flag=0;
			      break;
			}
		}
		if(flag) EulerTour(N);
	}
	return 0;
}
