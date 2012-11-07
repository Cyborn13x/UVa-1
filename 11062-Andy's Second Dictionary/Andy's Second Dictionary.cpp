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
#define SZ 5000

/*problem id-11062
 *
 *language-C++
 *
 */

using namespace std;

void Low(char *a)
{
      int i,l=strlen(a);
      FOR(i,l) if(isalpha(a[i])) a[i]=tolower(a[i]);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0;
	char line[SZ],a[SZ];
	map<string,bool> idx;
	map<string,bool>::iterator it;
	idx.clear();
	while(gets(line)!=NULL)
	{
	      if(!blank) x=0;
		for(i=0,l=strlen(line);i<l;i++)
		{
			while(isalpha(line[i]) || (line[i]=='-' && i<l-1 && isalpha(line[i+1]))) a[x++]=line[i++];
			if(line[i]=='-' && i+1==l) {blank=1; continue;}
			a[x]=0, x=0 ,blank=0;
			Low(a);
			if(a[0]) idx[a]=1;
		}
	}
	for(it=idx.begin();it!=idx.end();it++) cout << it->first <<endl;
	return 0;
}
