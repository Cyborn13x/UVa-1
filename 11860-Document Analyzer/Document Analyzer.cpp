#include <algorithm>
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

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 100005

/*problem id-11860
 *
 *language-C++
 *
 */

using namespace std;

int ar[SZ],interval[SZ],lastseen[SZ];

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,cnt,sz,test=0,p,q,str,end,in,len;
	char a[200],b[200];
	map<string,int> idx;
	multiset<int> pq;
	scanf("%d%*c",&t);
	while(t--)
	{
	      cnt=1, y=0, len=INF;
	      SET(interval);
	      SET(lastseen);
	      idx.clear(); pq.clear();
		while(gets(a) && strcmp(a,"END"))
		{
			for(i=0,l=strlen(a);i<l;i++)
			{
                        x=0;
				while(isalpha(a[i])) b[x++]=a[i++];
				b[x]=0;
				if(!b[0]) continue;
				if(!idx[b]) idx[b]=cnt++;
				ar[y++]=idx[b];
			}
		}cnt--;
		for(i=y-1;i>=0;i--)
		{
			if(lastseen[ar[i]]!=-1) pq.erase(pq.find(lastseen[ar[i]]));
			lastseen[ar[i]]=i;
			pq.insert(i);
			if(pq.size()==cnt)
			{
			      sz=(*pq.rbegin())-i+1;
			      if(sz<=len) len=sz, in=i;
			}
		}
		printf("Document %d: %d %d\n",++test,in+1,in+len);
	}
	return 0;
}
