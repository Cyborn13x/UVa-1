#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define UP 1
#define LEFT 2
#define CORNER 3

/*problem id-531
 *
 *language-ANSI C
 *
 */

int len;
int space;
int lcs[102][102];
int path[102][102];
char a[102][35];
char b[102][35];

void PrintPath(int i,int j)
{
      if(!i || !j) return;
      else if(path[i][j]==CORNER)
      {
            PrintPath(i-1,j-1);
            space--;printf("%s",a[i-1]);
            if(space) printf(" ");
      }
      else if(path[i][j]==LEFT) PrintPath(i,j-1);
      else PrintPath(i-1,j);
}

void FindLCS(int n,int m)
{
      int i;
      int j;
      memset(lcs,0,sizeof(lcs));
      for(i=1;i<=n;i++)
      {
      	for(j=1;j<=m;j++)
      	{
      		if(!strcmp(a[i-1],b[j-1]))
      		{
      		      lcs[i][j]=lcs[i-1][j-1]+1;
      		      path[i][j]=CORNER;
      		}
      		else if(lcs[i-1][j]>lcs[i][j-1])
      		{
      		      lcs[i][j]=lcs[i-1][j];
      		      path[i][j]=UP;
      		}
      		else
      		{
      		      lcs[i][j]=lcs[i][j-1];
      		      path[i][j]=LEFT;
      		}
      	}
      }space=lcs[n][m];
      PrintPath(n,m);
      printf("\n");
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	char tmp[40];
      while(scanf("%s",a[0])!=EOF)
      {
            n=0;m=0;
            while(a[n][0]!='#') scanf("%s",a[++n]);
            while(scanf("%s",b[m]) && b[m][0]!='#') m++;
            FindLCS(n,m);
      }
	return 0;
}
