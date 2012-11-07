#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*problem id-852
 *
 *language-ANSI C
 *
 */

const int a[]={1,-1,0,0}, b[]={0,0,1,-1};
int vis[10][10],top,cnt;
char grid[10][10],side[100];

void DFS(int x,int y)
{
      int i,bl=0,wh=0,r,c;
      if(x<0 || y<0 || x>8 || y>8 || vis[x][y]) return;
      if(grid[x][y]!='.') { side[top++]=grid[x][y]; return; }
      vis[x][y]=1, cnt++;;
      for(i=0;i<4;i++) DFS(x+a[i],y+b[i]);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,r,c,x,y,blank,test=0,black,white,paisi;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		memset(vis,0,100*sizeof(int));
		for(i=black=white=0;i<9;i++) scanf("%s",grid[i]);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(grid[i][j]=='O') white++;
				else if(grid[i][j]=='X') black++;
			}
		}
		for(i=0;i<9;i++)
		{
		      for(j=0;j<9;j++)
		      {
		            if(grid[i][j]=='.')
                        {
                              top=cnt=0;
                              DFS(i,j);
                              for(k=paisi=0;k<top;k++) if(side[k]=='X') { paisi=1; break; }
                              if(!paisi) white+=cnt;
                              for(k=paisi=0;k<top;k++) if(side[k]=='O') { paisi=1; break; }
                              if(!paisi) black+=cnt;
                        }
		      }
		}
		printf("Black %d White %d\n",black,white);
	}
	return 0;
}
