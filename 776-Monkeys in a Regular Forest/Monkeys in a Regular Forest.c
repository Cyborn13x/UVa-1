#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-776
 *
 *language-ANSI C
 *
 */

char forest[100][1000];
int grid[100][1000];
int vis[100][1000];
int width[1000];
int row=0;
int col=0;
int value;
int a[]={0,0,1,-1,1,1,-1,-1};
int b[]={1,-1,0,0,1,-1,1,-1};

int Length(int n)
{
    int i=0;
    while(n) {n/=10;i++;}
    return i;
}

void DFS(int r,int c,char ch)
{
    int i;
    if(!(r>=0 && r<row && c>=0 && c<col && forest[r][c]==ch && !vis[r][c])) return;
    grid[r][c]=value;
    vis[r][c]=1;
    for(i=0;i<8;i++) if(forest[r+a[i]][c+b[i]]==ch) DFS(r+a[i],c+b[i],ch);
    return;
}

int max(int i,int j)
{
    return i>j ? i : j;
}

void PrintGrid()
{
    int i;
    int j;
    memset(width,0,sizeof(width));
    for(i=0;i<row;i++) for(j=0;j<col;j++) width[j] = max(width[j],Length(grid[i][j]));
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    	    if(j!=0) printf(" ");
    		printf("%*d",width[j],grid[i][j]);
    	}
    	printf("\n");
    }
    printf("%%\n");
    return;
}

void build(char *s)
{
    int i;
    int j=0;
    for(i=0;s[i]!=0;i++) if(s[i]!=' ') forest[row][j++] = s[i];
    col=j;
    row++;
    return;
}

void solve()
{
    int i;
    int j;
    value=0;
    memset(vis,0,sizeof(vis));
    for(i=0;i<row;i++) for(j=0;j<col;j++) if(!vis[i][j]) {value++;DFS(i,j,forest[i][j]);}
    PrintGrid();
    row=col=0;
    return;
}

int main()
{
    /*FILE *fi = fopen("in.txt","r");*/
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int flag1;
	int flag2;
	char s[1005];
	char c;
    while(scanf("%[^\n]",s)!=EOF)
    {
        getchar();
        /*fscanf(fi,"%c",&c);*/
        if(!strcmp("%",s)) solve();
        else build(s);
    }
    solve();
	return 0;
}
