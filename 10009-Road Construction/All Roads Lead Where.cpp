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

/*problem id-10009
 *
 *language-C++
 *
 */

using namespace std;

int path[30][30];
char name[30];

void PrintPath(int i,int j)
{
      if(path[i][j]==-1) printf("%c",name[i]);
      else { PrintPath(i,path[i][j]); PrintPath(path[i][j],j); }
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
	int index;
	int AdjMatrix[30][30];
	bool blank=false;
	char a[30];
	char b[30];
      map<string,int> ind;
      scanf("%d",&t);
      while(t--)
      {
      	if(blank) printf("\n");
      	blank=true;ind.clear();index=1;
      	for(i=1;i<30;i++) for(j=1;j<30;j++) AdjMatrix[i][j]=1<<20;
      	for(i=0;i<27;i++) for(j=0;j<27;j++) path[i][j]=-1;
      	scanf("%d %d\n",&m,&n);
      	while(m--)
      	{
      		scanf("%s %s",a,b);
      		if(!ind[a]) { ind[a]=index; name[index++]=a[0]; }
      		if(!ind[b]) { ind[b]=index; name[index++]=b[0]; }
      		AdjMatrix[ind[a]][ind[b]]=AdjMatrix[ind[b]][ind[a]]=1;
      	}
      	for(k=1;k<index;k++)
      	{
      		for(i=1;i<index;i++)
      		{
      			for(j=1;j<index;j++)
      			{
      				if(AdjMatrix[i][k]+AdjMatrix[k][j]<AdjMatrix[i][j])
      				{
      				      path[i][j]=k;
      				      AdjMatrix[i][j]=AdjMatrix[i][k]+AdjMatrix[k][j];
      				}
      			}
      		}
      	}
      	for(i=0;i<n;i++)
      	{
      		scanf("%s %s",a,b);
      		PrintPath(ind[a],ind[b]);
      		printf("%c\n",name[ind[b]]);
      	}
      }
	return 0;
}
