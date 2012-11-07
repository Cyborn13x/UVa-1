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

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<28
#define SZ 102

/*problem id-11280
 *
 *language-C++
 *
 */

using namespace std;

int AdjMat[SZ][SZ],d[SZ];

int BellmanFord(int n,int len)
{
      int i,j,k,l,w,ret=INF;
      For(i,n) d[i]=INF;
      d[0]=0;
      For(k,len+1)
      {
      	for(i=n-1;i>=0;i--)
      	{
      		for(j=i+1;j<n;j++)
      		{
      			if(AdjMat[i][j]==INF) continue;
      			w=d[i]+AdjMat[i][j];
      			if(w<d[j]) d[j]=w;
      		}
      	}
      	if(d[n-1]<ret) ret=d[n-1];
      }
      return ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,cnt,blank=0,test=0;
	char a[25],b[25];
	map<string,int> idx;
	scanf("%d",&t);
	while(t--)
	{
	      if(blank) putchar('\n');
	      idx.clear(); cnt=1, blank=1;
		scanf("%d",&n);
		For(i,n) for(j=i+1,AdjMat[i][i]=0;j<n;j++) AdjMat[i][j]=AdjMat[j][i]=INF;
		For(i,n)
		{
			scanf("%s",a);
			idx[a]=cnt++;
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s %s %d",a,b,&k);
			x=idx[a]-1, y=idx[b]-1;
			AdjMat[x][y]=min(AdjMat[x][y],k);
		}
		printf("Scenario #%d\n",++test);
		scanf("%d",&l);
		while(l--)
		{
		      scanf("%d",&k);
		      x=BellmanFord(n,k);
		      if(x==INF) printf("No satisfactory flights\n");
		      else printf("Total cost of flight(s) is $%d\n",x);
		}
	}
	return 0;
}
