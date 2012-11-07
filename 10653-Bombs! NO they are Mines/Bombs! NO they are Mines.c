#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#define INFINITY 10000
#define UNPROCESSED 0
#define WAITING 1
#define PROCESSED 2

typedef struct
{
      int d;
      int r;
      int c;
      int s;
}node;

node board[1000][1000];
node Queue[1000000];
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
	int t;
	int Front;
	int Iterator;
	int a[]={0,0,1,-1};
	int b[]={1,-1,0,0};
	while(scanf("%d %d",&row,&col)==2 && (row || col))
	{
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				board[i][j].r=i;
				board[i][j].c=j;
				board[i][j].d=INFINITY;
				board[i][j].s=UNPROCESSED;
			}
		}
		Front=0;
		Iterator=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&t);
				board[x][t].s=PROCESSED;
			}
		}

		scanf("%d %d %d %d",&SourceX,&SourceY,&TargetX,&TargetY);
		board[SourceX][SourceY].d=0;
		board[SourceX][SourceY].s=WAITING;
		Queue[Front]=board[SourceX][SourceY];
		Iterator++;
		while(board[TargetX][TargetY].s!=PROCESSED)
		{
		      temp=Queue[Front];
                  for(i=0;i<4;i++)
                  {
                  	x=temp.r+a[i];
                  	y=temp.c+b[i];
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
		printf("%d\n",board[TargetX][TargetY].d);

	}
	return 0;
}
