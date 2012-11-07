#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <iostream>

/*problem id-10377
 *
 *language-C++
 *
 */

using namespace std;

#define RESTRICTED 0
#define PERMITTED 1
#define EAST 'E'
#define WEST 'W'
#define NORTH 'N'
#define SOUTH 'S'

int main()
{
	int i;
	int j;
	int k;
	int flag=0;
	int TestCase;
    int maze[60][60];
    int x;
    int y;
    int row;
    int column;
    char a[70];
    char Direction;
    char c;
    cin >> TestCase;
    for(i=0;i<TestCase;i++)
    {
        flag=1;
        Direction=NORTH;
        cin >> row >> column;
        getchar();
      	for(j=0;j<row;j++)
      	{
            gets(a);
            for(k=0;k<column;k++)
            {
                if(a[k]=='*') maze[j][k]=RESTRICTED;
                else maze[j][k]=PERMITTED;
            }
      	}
      	cin >> x >> y;
      	x--;
      	y--;
      	while(cin >> c)
      	{
            if(c=='R')
            {
                if(Direction==NORTH) Direction=EAST;
                else if(Direction==EAST) Direction=SOUTH;
                else if(Direction==SOUTH) Direction=WEST;
                else Direction=NORTH;
            }
            else if(c=='L')
            {
                if(Direction==NORTH) Direction=WEST;
                else if(Direction==WEST) Direction=SOUTH;
                else if(Direction==SOUTH) Direction=EAST;
                else Direction=NORTH;
            }
            else if(c=='F')
            {
                if(Direction==NORTH && maze[x-1][y]) x--;
                else if(Direction==EAST && maze[x][y+1]) y++;
                else if(Direction==SOUTH && maze[x+1][y]) x++;
                else if(Direction==WEST && maze[x][y-1]) y--;
            }
            else if(c=='Q') break;
            else break;
      	}
      	printf("%d %d %c\n",x+1,y+1,Direction);
      	if(i<TestCase-1) printf("\n");
      }
      return 0;
}
