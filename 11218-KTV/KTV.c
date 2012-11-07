#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000

/*problem id-11218
 *
 *language-ANSI C
 *
 */

int data[100][4],vis[10],res,n,val;

void BackTrack(int lev)
{
      int i;
      if(lev==3)
      {
            if(val>res) res=val;
            return;
      }
      for(i=0;i<n;i++)
      {
      	if(!(vis[data[i][0]]+vis[data[i][1]]+vis[data[i][2]]))
      	{
      	      vis[data[i][0]]=vis[data[i][1]]=vis[data[i][2]]=1;
      	      val+=data[i][3];
      	      BackTrack(lev+1);
      	      val-=data[i][3];
      	      vis[data[i][0]]=vis[data[i][1]]=vis[data[i][2]]=0;
      	}
      }
}

int main()
{
	int i,j,k,l,m,t,x,y,blank=0,test=0;
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++) scanf("%d %d %d %d",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
		res=-1;
		BackTrack(0);
		printf("Case %d: %d\n",++test,res);
	}
	return 0;
}
