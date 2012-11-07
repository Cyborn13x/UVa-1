#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10452
 *
 *language-ANSI C
 *
 */

const char code[]="IEHOVA#";
char grid[10][10];
int space;
int n;
int m;

void Search(int x,int y,int top)
{
      if(top==7) return;
      if(space) putchar(' ');
      if(grid[x+1][y]==code[top] && x<n-1) { printf("forth"); space++; Search(x+1,y,top+1); }
      else if(grid[x][y+1]==code[top] && y<m-1) { printf("right"); space++;  Search(x,y+1,top+1); }
      else if(grid[x][y-1]==code[top] && y>0) { printf("left"); space++; Search(x,y-1,top+1); }
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int t;
	int x;
	int y;
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d %d",&n,&m);
      	for(i=n-1;i>=0;i--) scanf("%s",grid[i]);
      	for(i=space=0;i<m;i++) if(grid[0][i]=='@') Search(0,i,0);
      	putchar('\n');
      }
	return 0;
}
