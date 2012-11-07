#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define INF 100000
#define UNVISITED 0
#define WAITING 1
#define VISITED 2

/*problem id-567
 *
 *language-C++
 *
 */

using namespace std;

int MIN(int a,int b) {return (a<b)?a:b;}

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
	int start;
	int end;
	int BFS[22][22];
	k=1;
	while(scanf("%d",&m)!=EOF)
	{
		for(i=1;i<22;i++) for(j=1;j<22;j++) BFS[i][j]=50;
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			BFS[1][x]=BFS[x][1]=1;
		}
		for(i=2;i<=19;i++)
		{
		      scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				BFS[i][x]=BFS[x][i]=1;
			}
		}
		for(l=1;l<21;l++)
		{
			for(i=1;i<21;i++)
			{
				for(j=1;j<21;j++)
				{
					BFS[i][j]=MIN(BFS[i][j],BFS[i][l]+BFS[l][j]);
				}
			}
		}
		scanf("%d",&n);
		printf("Test Set #%d\n",k++);
		for(j=0;j<n;j++)
		{
			scanf("%d %d",&start,&end);
			printf("%2d to %2d: %d\n",start,end,BFS[start][end]);
		}
		printf("\n");
	}
	return 0;
}
