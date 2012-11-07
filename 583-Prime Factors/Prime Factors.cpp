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

/*problem id-583
 *
 *language-C++
 *
 */

using namespace std;

bool p[1000000];
int prime[100000];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	bool flag;
	k=1;
	prime[0]=2;
	for(i=4;i<500002;i+=2) p[i]=1;
	for(i=3;i<500002;i+=2) if(!p[i]) {prime[k++]=i;for(j=2*i;j<1000000;j+=i) p[j]=1;}
	m=k-1;
	while(scanf("%d",&n)==1 && n)
	{
	      flag=0;
	      printf("%d =",n);
		if(n<0) {n*=-1;printf(" -1 x");flag=1;}
		for(i=0;prime[i]<n && i<m;i++)
		{
			if(n%prime[i]==0)
			{
			      while(n%prime[i]==0)
			      {
			            n/=prime[i];
			            if(n>1) printf(" %d x",prime[i]);
			            else {printf(" %d",prime[i]);flag=1;}
                        }
			}
		}
		if(n>1) printf(" %d",n);
		printf("\n");
	}
	return 0;
}
