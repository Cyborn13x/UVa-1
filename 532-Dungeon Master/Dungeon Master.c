#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INFINITY 10000
#define UNPROCESSED 0
#define WAITING 1
#define PROCESSED 2

/*problem id-532
 *
 *language-ANSI C
 *
 *
 */


typedef struct
{
      int d;
      int r;
      int c;
      int l;
      int s;
}node;

node board[30][30][30];
node Queue[30000];
node temp;
int row;
int col;

int IsValid(int a,int b)
{
    if((a>=0 && a<row) && (b>=0 && b<col))
    {
        return 1;
    }
    return 0;
}

int main()
{
	int i;
	int j;
	int k;
	int SourceX;
	int SourceY;
	int SourceZ;
	int TargetX;
	int TargetY;
	int TargetZ;
	int m;
      int n;
	int x;
	int y;
	int z;
	int t;
	int Front;
	int Iterator;
	int lev;
	int a[]={0,0,1,-1};
	int b[]={1,-1,0,0};
	char c;
	while(scanf("%d %d %d",&lev,&row,&col)==3 && (row || col || lev))
	{
	      getchar();
	      for(k=0;k<lev;k++)
	      {
	      	for(i=0;i<row;i++)
                  {
                        for(j=0;j<col;j++)
                        {
                              board[k][i][j].r=i;
                              board[k][i][j].c=j;
                              board[k][i][j].l=k;
                              board[k][i][j].d=INFINITY;
                              board[k][i][j].s=UNPROCESSED;
                        }
                  }
	      }
		Front=0;
		Iterator=0;
		for(k=0;k<lev;k++)
	      {
	      	for(i=0;i<row;i++)
                  {
                        for(j=0;j<col;j++)
                        {
                              scanf("%c",&c);
                              if(c=='.' || c=='E')
                              {
                                    board[k][i][j].d=INFINITY;
                                    board[k][i][j].s=UNPROCESSED;
                                    if(c=='E')
                                    {
                                          TargetX=i;
                                          TargetY=j;
                                          TargetZ=k;
                                    }
                              }
                              else if(c=='S')
                              {
                                    board[k][i][j].d=0;
                                    board[k][i][j].s=UNPROCESSED;
                                    SourceX=i;
                                    SourceY=j;
                                    SourceZ=k;
                              }
                              else if(c=='#')
                              {
                                    board[k][i][j].s=PROCESSED;
                              }
                        }
                        getchar();
                  }
                  getchar();
	      }
		board[SourceZ][SourceX][SourceY].d=0;
		board[SourceZ][SourceX][SourceY].s=WAITING;
		Queue[Front]=board[SourceZ][SourceX][SourceY];
		Iterator++;
		while(Front!=Iterator)
		{
		      temp=Queue[Front];
		      if(temp.l-1>=0 && temp.l-1<lev && board[temp.l-1][temp.r][temp.c].s==UNPROCESSED)
                  {
                        Queue[Iterator]=board[temp.l-1][temp.r][temp.c];
                        board[temp.l-1][temp.r][temp.c].s=WAITING;
                        Iterator++;
                        board[temp.l-1][temp.r][temp.c].d=board[temp.l][temp.r][temp.c].d+1;
                  }
                  for(i=0;i<4;i++)
                  {
                  	x=temp.r+a[i];
                  	y=temp.c+b[i];
                  	if(IsValid(x,y) && board[temp.l][x][y].s==UNPROCESSED)
                  	{
                  	      Queue[Iterator]=board[temp.l][x][y];
                  	      board[temp.l][x][y].s=WAITING;
                  	      Iterator++;
                  	      board[temp.l][x][y].d=board[temp.l][temp.r][temp.c].d+1;
                  	}
                  }
                  if(temp.l+1>=0 && temp.l+1<lev && board[temp.l+1][temp.r][temp.c].s==UNPROCESSED)
                  {
                        Queue[Iterator]=board[temp.l+1][temp.r][temp.c];
                        board[temp.l+1][temp.r][temp.c].s=WAITING;
                        Iterator++;
                        board[temp.l+1][temp.r][temp.c].d=board[temp.l][temp.r][temp.c].d+1;
                  }
                  board[temp.l][temp.r][temp.c].s=PROCESSED;
                  Front++;
		}
		if(board[TargetZ][TargetX][TargetY].d==INFINITY)
		{
		      printf("Trapped!\n");
		}
		else
		{
		      printf("Escaped in %d minute(s).\n",board[TargetZ][TargetX][TargetY].d);
		}
	}
	return 0;
}
