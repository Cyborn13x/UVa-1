#include <iostream>
#include <sstream>
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

/*problem id-1056
 *
 *language-C++
 *
 */

using namespace std;

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
	int test=0;
	int floyd[51][51];
	char a[1000],b[1000];
	map<string,int> idx;
	while(scanf("%d %d",&n,&m) && n && m)
	{
		for(i=1,idx.clear();i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				floyd[i][j]=100000;
			}floyd[i][i]=0;
		}
		for(i=0,t=1;i<m;i++)
		{
			scanf("%s %s",a,b);
			if(!idx[a]) idx[a]=t++;
			if(!idx[b]) idx[b]=t++;
			floyd[idx[a]][idx[b]]=floyd[idx[b]][idx[a]]=1;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(floyd[i][k]+floyd[k][j]<floyd[i][j])
					{
					      floyd[i][j]=floyd[i][k]+floyd[k][j];
					}
				}
			}
		}
		for(i=1,x=0;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(floyd[i][j]>x) x=floyd[i][j];
			}
		}
		printf("Network %d: ",++test);
		if(x<100000) printf("%d\n\n",x);
		else printf("DISCONNECTED\n\n");
	}
	return 0;
}
