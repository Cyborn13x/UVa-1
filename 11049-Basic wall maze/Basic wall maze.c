#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INFINITY 10000
#define UNPROCESSED 0
#define WAITING 1
#define PROCESSED 2

/*problem id-11049
 *
 *language-ANSI C
 *
 *
 */

struct fgh
{
      int d;
      int r;
      int c;
      int s;
      int a[4];
      struct fgh *prev;
};

typedef struct fgh node;
node board[6][6];
node Queue[36];
node temp;
node p;
int row=6;
int col=6;

int IsValid(int a,int b)
{
    if((a>=0 && a<row) && (b>=0 && b<col)) return 1;
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
	int FinalDistance;
	int x1;
	int y1;
	int x2;
	int y2;
	int m;
      int n;
	int x;
	int y;
	int t;
	int Front;
	int Iterator;
	int a[]={0,0,-1,1};
	int b[]={1,-1,0,0};
	while(1)
	{
	      scanf("%d %d",&SourceY,&SourceX);
	      if(!SourceX && !SourceY) break;
	      scanf("%d %d",&TargetY,&TargetX);
	      SourceX--;
	      SourceY--;
	      TargetX--;
	      TargetY--;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				board[i][j].r=i;
				board[i][j].c=j;
				board[i][j].d=INFINITY;
				board[i][j].s=UNPROCESSED;
				board[i][j].prev=NULL;
				for(k=0;k<4;k++)
				{
					board[i][j].a[k]=1;
				}
			}
		}

		for(i=0;i<3;i++)
		{
			scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
			if(x1==x2)
			{
			      for(j=0;j<y2-y1;j++)
			      {
			      	if(IsValid(x1-1,y1+j)) board[x1-1][y1+j].a[3]=0;
			      	if(IsValid(x1,y1+j)) board[x1][y1+j].a[2]=0;
			      }
			}
			else
			{
			      for(j=0;j<x2-x1;j++)
			      {
			      	if(IsValid(x1+j,y1-1)) board[x1+j][y1-1].a[0]=0;
			      	if(IsValid(x1+j,y1)) board[x1+j][y1].a[1]=0;
			      }
			}
		}
		Front=0;
		Iterator=0;
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
                  	if(IsValid(x,y) && board[temp.r][temp.c].a[i]==1 && board[x][y].s==UNPROCESSED)
                  	{
                  	      Queue[Iterator]=board[x][y];
                  	      Iterator++;
                  	      board[x][y].s=WAITING;
                  	      board[x][y].d=board[temp.r][temp.c].d+1;
                  	      board[x][y].prev=&board[temp.r][temp.c];
                  	}
                  }
                  board[temp.r][temp.c].s=PROCESSED;
                  Front++;
		}
		FinalDistance=board[TargetX][TargetY].d;
		p=board[TargetX][TargetY];
		for(i=FinalDistance-1;i>=0;i--)
		{
			Queue[i]=p;
			p=*(p.prev);
		}
		p=board[SourceX][SourceY];
		for(i=0;i<FinalDistance;i++)
		{
			if(Queue[i].r==(p.r)-1) printf("N");
			else if(Queue[i].r==(p.r)+1) printf("S");
			else if(Queue[i].c==(p.c)-1) printf("W");
			else if(Queue[i].c==(p.c)+1) printf("E");
			p=Queue[i];
		}
		printf("\n");
	}
	return 0;
}
