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

/*problem id-11988
 *
 *language-ANSI C
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[SZ],b[SZ];
	vector<int> idx;
	while(gets(a)!=NULL)
	{
		idx.clear();
		l=strlen(a), x=0;
		FOR(i,l) if(a[i]=='[') idx.push_back(i);
		for(i=idx.size()-1;i>=0;i--)
		{
			for(j=idx[i]+1;j<l && a[j]!='[' && a[j]!=']';j++)
			{
				b[x++]=a[j];
				a[j]='[';
			}
		}
		FOR(i,l) if(a[i]!='[' && a[i]!=']') b[x++]=a[i];
		b[x]=0;
		puts(b);
	}
	return 0;
}
