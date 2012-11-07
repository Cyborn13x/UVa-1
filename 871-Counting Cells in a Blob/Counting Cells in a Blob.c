#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-871
 *
 *language-ANSI C
 *
 */

int ans;
int max;
int row;
int col;
int vis[30][30];
int a[]={0,0,1,-1,1,1,-1,-1};
int b[]={1,-1,0,0,1,-1,1,-1};
char grid[30][30];
char s[300];

void DFS(int r,int c)
{
    if(r<0 || c<0 || r>=row || c>=col || grid[r][c]=='0' || vis[r][c]) return;
    int i;
    ans++;
    vis[r][c] = 1;
    grid[r][c] = '0';
    for(i=0;i<8;i++) DFS(r+a[i],c+b[i]);
    return;
}

void solve()
{
    int i;
    int j;
    max=0;
    memset(vis,0,sizeof(vis));
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		if(grid[i][j]=='1')
    		{
    		    ans=0;
    		    DFS(i,j);
    		    max = ans>max ? ans : max;
    		}
    	}
    }
    printf("%d\n",max);
    return;
}

void build()
{
    int l=strlen(s);
    int i;
    for(i=0;i<l;i++) grid[row][i]=s[i];
    col=l;
    row++;
    return;
}

int main()
{
	int i;
	int j;
	int t;
	int max;
	int flag=0;
	scanf("%d",&t);
	getchar();
	getchar();
	while(t--)
	{
	    row=0;
	    while(gets(s) && s[0]) build();
	    if(flag) printf("\n");
	    flag=1;
	    solve();
	}
	return 0;
}
