#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define N 1002
#define INF 10000000

/*problem id-11624
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
      int x,y;
}point;

const int a[]={1,-1,0,0};
const int b[]={0,0,1,-1};
int disfire[N][N],disjoe[N][N];
char grid[N][N];
queue<point> Fireque,Joeque;

int main()
{
	int i,j,k,l,m,n,t,x,y,row,col,blank,EscapeTime;
	bool flag;
	point tmp,tmp1;
	scanf("%d",&t);
	while(t--)
	{
	      scanf("%d %d",&row,&col); getchar();
		for(i=0,EscapeTime=-1,flag=true;i<row;i++)
		{
		      for(j=0;j<col;j++)
		      {
		            disfire[i][j]=disjoe[i][j]=INF;
		      	scanf("%c",&grid[i][j]);
		      	if(grid[i][j]=='F')
		      	{
		      	      tmp.x=i, tmp.y=j;
		      	      Fireque.push(tmp);
		      	      disfire[i][j]=0;
		      	}
		      	else if(grid[i][j]=='J')
		      	{
		      	      tmp.x=i, tmp.y=j;
		      	      Joeque.push(tmp);
		      	      disjoe[i][j]=0;
		      	}
		      }getchar();
		}
		while(!Fireque.empty())
		{
			tmp=Fireque.front(); Fireque.pop();
			for(i=0;i<4;i++)
			{
				x=tmp.x+a[i], y=tmp.y+b[i];
				if(x>=0 && y>=0 && x<row && y<col && disfire[x][y]==INF && grid[x][y]!='#')
				{
                              disfire[x][y]=disfire[tmp.x][tmp.y]+1;
                              tmp1.x=x, tmp1.y=y;
                              Fireque.push(tmp1);
				}
			}
		}
		tmp=Joeque.front(); x=tmp.x, y=tmp.y;
		if( !x || x==row-1 || !y || y==col-1)
            {
                  EscapeTime=1;
                  flag=false;
            }
		while(!Joeque.empty() && flag)
		{
			tmp=Joeque.front(); Joeque.pop(); x=tmp.x, y=tmp.y;
			for(i=0;i<4 && flag;i++)
			{
				x=tmp.x+a[i], y=tmp.y+b[i];
				if(x>=0&&y>=0&&x<row&&y<col&&disjoe[x][y]==INF&&grid[x][y]!='#'&&grid[x][y]!='F')
				{
                              disjoe[x][y]=disjoe[tmp.x][tmp.y]+1;
                              tmp1.x=x, tmp1.y=y;
                              Joeque.push(tmp1);
                              if(( !x || x==row-1 || !y || y==col-1) && disjoe[x][y]<disfire[x][y])
                              {
                                    EscapeTime=disjoe[x][y]+1;
                                    flag=false;
                              }
				}
			}
		}
		while(!Joeque.empty()) Joeque.pop();
		if(EscapeTime==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",EscapeTime);
	}
	return 0;
}
