#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define N 100008
#define N2 N/2

/*problem id-12043
 *
 *language-C++
 *
 */

using namespace std;

int d[N];
int s[N];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	long long int g;
	long long int h;
	for(i=1;i<N;i++) d[i]=s[i]=1;
      for(i=2;i<N;i++)
      {
            for(j=i;j<N;j+=i)
            {
                  d[j]++;
                  s[j]+=i;
            }
      }
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d %d %d",&m,&n,&l);
      	g=h=0;
      	for(i=m;i<=n;i++)
      	{
      		if(i%l==0)
      		{
      		      g+=d[i];
      		      h+=s[i];
      		}
      	}
      	printf("%lld %lld\n",g,h);
      }
	return 0;
}
