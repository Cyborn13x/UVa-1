#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 8

/*problem id-11553
 *
 *language-ANSI C
 *
 */

int grid[SZ][SZ],p[SZ],max,n;

void BackTrack(int mask,int idx)
{
      int i,sum=0;
      if(idx==n)
      {
            for(i=0;i<n;i++) sum+=grid[i][p[i]];
            if(sum<max) max=sum;
            return;
      }
      for(i=0;i<n;i++)
      {
      	if(mask & (1<<i)) continue;
      	p[idx]=i;
      	BackTrack(mask | (1<<i),idx+1);
      }
      return;
}

int main()
{
	int i,j,k,l,m,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0,max=INF;i<n;i++) for(j=0;j<n;j++) scanf("%d",&grid[i][j]);
		BackTrack(0,0);
		printf("%d\n",max);
	}
	return 0;
}
