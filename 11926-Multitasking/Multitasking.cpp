#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
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

#define INF 1<<30
#define SZ 1000001
#define ll long long int

/*problem id-11926
 *
 *language-ANSI C
 *
 */

using namespace std;

bool a[SZ];
int b[100][2],c[100][3];

bool Solve(int n,int m)
{
      int i,j,k,dif;
      memset(a,false,sizeof(a));
      for(i=0;i<n;i++)
      {
      	for(j=b[i][0];j<b[i][1] && j<SZ;j++)
      	{
      		if(a[j]) return 0;
      		else a[j]=true;
      	}
      }
      for(i=0;i<m;i++)
      {
      	while(c[i][0]<SZ)
      	{
      		for(j=c[i][0];j<c[i][1] && j<SZ;j++)
      		{
      			if(a[j]) return 0;
      			else a[j]=true;
      		}
      		c[i][0]+=c[i][2], c[i][1]+=c[i][2];
      	}
      }
      return 1;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		for(i=0;i<n;i++) scanf("%d %d",&b[i][0],&b[i][1]);
		for(i=0;i<m;i++) scanf("%d %d %d",&c[i],&c[i][1],&c[i][2]);
		if(Solve(n,m)) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");
	}
	return 0;
}
