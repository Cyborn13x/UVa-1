#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define NOTOK(x,y) (x<0 || y<0 || x>=3 || y>=3)
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 3

/*problem id-11581
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0,flag,cnt,grid[SZ][SZ],tmp[SZ][SZ];
	const int a[]={1,-1,0,0}, b[]={0,0,1,-1};
	scanf("%d",&t);
	while(t--)
	{
		cnt=-1;
		FOR(i,3) FOR(j,3) scanf("%1d",&grid[i][j]);
		while(1)
		{
			flag=0;
			FOR(i,3) FOR(j,3) flag|=grid[i][j];
			if(!flag) break;
			CLEAR(tmp);
			cnt++;
			FOR(i,3) FOR(j,3) FOR(k,4)
			{

                        x=i+a[k], y=j+b[k];
                        if(NOTOK(x,y)) continue;
                        tmp[i][j]=tmp[i][j] ^ grid[x][y];
			}
			FOR(i,3) FOR(j,3) grid[i][j]=tmp[i][j];
		}
		printf("%d\n",cnt);
	}
	return 0;
}
