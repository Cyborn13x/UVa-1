#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define N 1005
#define N1 sqrt(N)

/*problem id-884
 *
 *language-C++
 *
 */

using namespace std;

bool p[N];
int prime[180];
int ans[1000002];
int last;

int factor(int n)
{
      int k=0;
      int i;
      for(i=0;prime[i]*prime[i]<=n && i<last;i++)
      {
            if(n%prime[i]==0)
            {
                  while(n%prime[i]==0)
                  {
                        k++;
                        n/=prime[i];
                  }
            }
      }
      if(n>1) k++;
      return k;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	k=0;
	for(i=4;i<N;i+=2) p[i]=true;
	for(i=3;i<N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=true;
	for(i=2;i<N;i++) if(!p[i]) prime[k++]=i;
	last=k;ans[2]=1;
	for(i=3;i<=1000000;i++) ans[i]=ans[i-1]+factor(i);
	while(scanf("%d",&n)!=EOF) printf("%d\n",ans[n]);
	return 0;
}
