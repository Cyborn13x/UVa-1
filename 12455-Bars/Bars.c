#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 25

/*problem id-12455
 *
 *language-ANSI C
 *
 */

int SUM,p,a[SZ],flag,vis[SZ];

void BackTrack(int idx,int sum)
{
      int i;
      if(sum>SUM)  return;
      if(sum==SUM) { flag=1; return; }
      for(i=idx;i<p && !flag;i++)
      {
      	if(!vis[i])
      	{
      	      vis[i]=1;
      	      sum+=a[i];
      	      BackTrack(i+1,sum);
      	      sum-=a[i];
      	      vis[i]=0;
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&SUM,&p);
		for(i=flag=0;i<p;i++) scanf("%d",&a[i]);
		BackTrack(0,0);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
