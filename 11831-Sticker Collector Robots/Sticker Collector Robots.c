#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define INF 1<<30
#define SZ 50006
#define N 152

/*problem id-11831
 *
 *language-C++
 *
 */

char grid[N][N], cmd[2*SZ], map[128], *p;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
      int i,j,k,l,n,m,s,nx,ny,dir,res,x,y;
      map['N'] = 0; map['L'] = 1; map['S'] = 2; map['O'] = 3;
      while(scanf("%d %d %d",&n,&m,&s) && n)
      {
            res=0;
            for(i=0;i<n;i++)
            {
                  scanf("%s",grid[i]);
                  p = grid[i];
                  for(j=0;j<m;j++,p++) if(isupper(*p)) dir=map[*p], x=i, y=j;
            }
            scanf("%s",cmd);
            p=cmd;
            for(i=0;i<s;i++,p++)
            {
                  if(*p=='F')
                  {
                        nx=x+dx[dir],ny=y+dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]=='#') continue;
                        if(grid[x=nx][y=ny]=='*') res++, grid[x][y]='.';
                  }
                  else if(*p=='D') dir=(dir+1)%4;
                  else if(*p=='E') dir=(dir+3)%4;
            }
            printf("%d\n",res);
    }
    return 0;
}
