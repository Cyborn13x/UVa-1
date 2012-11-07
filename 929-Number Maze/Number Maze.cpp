#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define INFINITY 10000000
#define UNPROCESSED 0
#define WAITING 1
#define PROCESSED 2

/*problem id-929
 *
 *language-C++
 *
 */

typedef struct
{
      int distance;
      int r;
      int c;
      int state;
      int value;
}node;

node board[1005][1005];
node temp;
int row;
int col;

int IsValid(int a,int b)
{
    if(a>=0 && a<row && b>=0 && b<col) return 1;
    return 0;
}

int main()
{
	int i;
	int j;
	int k;
	int z;
	int SourceX;
	int SourceY;
	int TargetX;
	int TargetY;
	int m;
      int n;
	int x;
	int y;
	int t;
	int TestCase;
	int Length;
	int a[]={0,0,1,-1};
	int b[]={1,-1,0,0};
	queue<node> q[10];

	scanf("%d",&TestCase);

	for(z=0;z<TestCase;z++)
	{
	    for(i=0;i<10;i++) while(!q[i].empty()) q[i].pop();

        scanf("%d",&row);
        scanf("%d",&col);

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				board[i][j].r=i;
				board[i][j].c=j;
				board[i][j].distance=INFINITY;
				board[i][j].state=UNPROCESSED;
			}
		}

		for(i=0;i<row;i++) for(j=0;j<col;j++) scanf("%d",&board[i][j].value);

		SourceX=0;
		SourceY=0;
		TargetX=row-1;
		TargetY=col-1;

		board[SourceX][SourceY].state=WAITING;
		q[(board[0][0].value)%10].push(board[0][0]);
		board[0][0].distance=board[0][0].value;
		k=(board[0][0].value)%10;

		while(board[TargetX][TargetY].state!=PROCESSED)
		{
		    while(q[k].empty()) k=(k+1)%10;

		    temp=q[k].front();
		    q[k].pop();
            for(i=0;i<4;i++)
            {
                x=temp.r+a[i];
                y=temp.c+b[i];
                if(IsValid(x,y) && board[x][y].state!=PROCESSED)
                {
                    if(board[temp.r][temp.c].distance+board[x][y].value<board[x][y].distance)
                    {
                        board[x][y].distance=board[temp.r][temp.c].distance+board[x][y].value;
                    }
                    if(board[x][y].state==UNPROCESSED)
                    {
                        q[(board[x][y].distance)%10].push(board[x][y]);
                        board[x][y].state=WAITING;
                    }
                }
            }
            board[temp.r][temp.c].state=PROCESSED;
		}
		printf("%d\n",board[TargetX][TargetY].distance);
	}
	return 0;
}
