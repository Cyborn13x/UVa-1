#include <stdio.h>

/*problem id-539
 *
 *language-ANSI C
 *
 */

int AdjMatrix[25][25],vis[25][25],N,mx;

int max(int a,int b) { return a>b ? a : b; }

int DFS(int n)
{
      int i,len=0;
      for(i=0;i<N;i++)
      {
            if(AdjMatrix[n][i] && !vis[n][i])
            {
                  vis[n][i]=vis[i][n]=1;
                  len = max(len,1+DFS(i));
                  vis[n][i]=vis[i][n]=0;
            }
      }
      return len;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&N,&m) && (N || m))
	{
	      memset(vis,0,25*25*sizeof(int));
		memset(AdjMatrix,0,25*25*sizeof(int));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			AdjMatrix[x][y]=AdjMatrix[y][x]=1;
		}
		for(i=mx=0;i<N;i++) mx = max(mx,DFS(i));
		printf("%d\n",mx);
	}
	return 0;
}
