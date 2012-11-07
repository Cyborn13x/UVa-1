#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INFINITY 10000
#define UNPROCESSED 0
#define WAITING 1
#define PROCESSED 2

/*problem id-11352
 *
 *language ANSI C
 *
 *
 */

typedef struct
{
      int d;
      int r;
      int c;
      int s;
      char p;
}node;

node board[100][100];
node Queue[10000];
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
	int TargetX;
	int TargetY;
	int m;
      int n;
	int x;
	int y;
	int z;
	int tx;
	int ty;
	int t;
	int Front;
	int Iterator;
	int lev;
	int a[]={1,-1,1,-1,2,2,-2,-2};
	int b[]={2,2,-2,-2,1,-1,1,-1};
	int aa[]={0,0,1,-1,1,1,-1,-1};
	int bb[]={1,-1,0,0,1,-1,1,-1};
	char c;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
	      scanf("%d %d",&row,&col);
	      getchar();
	      for(i=0;i<row;i++)
            {
                  for(j=0;j<col;j++)
                  {
                        board[i][j].r=i;
                        board[i][j].c=j;
                        board[i][j].p='n';
                        board[i][j].d=INFINITY;
                        board[i][j].s=UNPROCESSED;
                  }
            }
		Front=0;
		Iterator=0;
            for(i=0;i<row;i++)
            {
                  for(j=0;j<col;j++)
                  {
                        scanf("%c",&c);
                        if(c=='.' || c=='B')
                        {
                              board[i][j].d=INFINITY;
                              board[i][j].s=UNPROCESSED;
                              if(c=='B')
                              {
                                    TargetX=i;
                                    TargetY=j;
                              }
                        }
                        else if(c=='A')
                        {
                              board[i][j].d=0;
                              board[i][j].s=UNPROCESSED;
                              SourceX=i;
                              SourceY=j;
                        }
                        else if(c=='Z')
                        {
                              board[i][j].s=PROCESSED;
                              board[i][j].p='k';
                        }
                  }
                  getchar();
            }
            for(i=0;i<row;i++)
            {
            	for(j=0;j<col;j++)
            	{
            		if(board[i][j].p=='k')
            		{
            		      for(k=0;k<8;k++)
                              {
                              	tx=i+a[k];
                              	ty=j+b[k];
                              	if(IsValid(tx,ty))
                              	{
                              	      board[tx][ty].s=PROCESSED;
                              	}
                              }
            		}
            	}
            }
            board[TargetX][TargetY].s=UNPROCESSED;
		board[SourceX][SourceY].d=0;
		board[SourceX][SourceY].s=WAITING;
		Queue[Front]=board[SourceX][SourceY];
		Iterator++;
		while(Front!=Iterator)
		{
		      temp=Queue[Front];
                  for(i=0;i<8;i++)
                  {
                  	x=temp.r+aa[i];
                  	y=temp.c+bb[i];
                  	if(IsValid(x,y) && board[x][y].s==UNPROCESSED)
                  	{
                  	      Queue[Iterator]=board[x][y];
                  	      board[x][y].s=WAITING;
                  	      Iterator++;
                  	      board[x][y].d=board[temp.r][temp.c].d+1;
                  	}
                  }
                  board[temp.r][temp.c].s=PROCESSED;
                  Front++;
		}
		if(board[TargetX][TargetY].d==INFINITY)
		{
		      printf("King Peter, you can't go now!\n");
		}
		else
		{
		      printf("Minimal possible length of a trip is %d\n",board[TargetX][TargetY].d);
		}
	}
	return 0;
}
