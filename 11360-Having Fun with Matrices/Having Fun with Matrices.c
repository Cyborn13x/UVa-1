#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 12

/*problem id-11360
 *
 *language-ANSI C
 *
 */

int n;
char mat[SZ][SZ],tmp[SZ][SZ];

void Inc()
{
      int i,j;
      FOR(i,n) FOR(j,n) mat[i][j]=((mat[i][j]-'0'+1)%10)+'0';
      return;
}

void Dec()
{
      int i,j;
      FOR(i,n) FOR(j,n) mat[i][j]=(((mat[i][j]-'0'-1)+10)%10)+'0';
      return;
}

void Row(int x,int y)
{
      int i,t;
      FOR(i,n) { t=mat[x][i], mat[x][i]=mat[y][i], mat[y][i]=t; }
      return;
}

void Col(int x,int y)
{
      int i,t;
      FOR(i,n) { t=mat[i][x], mat[i][x]=mat[i][y], mat[i][y]=t; }
      return;
}

void Trans()
{
      int i,j;
      FOR(i,n) strcpy(tmp[i],mat[i]);
      FOR(i,n) FOR(j,n) mat[j][i]=tmp[i][j];
      return;
}

int main()
{
	int i,j,k,l,m,t,x,y,blank=0,test=0;
	char cmd[15];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		FOR(i,n) scanf("%s",mat[i]);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",cmd);
			if(!strcmp(cmd,"transpose")) Trans();
			else if(!strcmp(cmd,"inc")) Inc();
			else if(!strcmp(cmd,"dec")) Dec();
			else if(!strcmp(cmd,"row"))
			{
			      scanf("%d %d",&x,&y);
			      Row(x-1,y-1);
			}
			else if(!strcmp(cmd,"col"))
			{
			      scanf("%d %d",&x,&y);
			      Col(x-1,y-1);
			}
		}printf("Case #%d\n",++test);
		FOR(i,n) puts(mat[i]);
		printf("\n");
	}
	return 0;
}
