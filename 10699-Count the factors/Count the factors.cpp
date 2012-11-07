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

#define N 1000005
#define N1 N/2

/*problem id-10699
 *
 *language-C++
 *
 */

using namespace std;

int p[N];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	for(i=2;i<N1;i++) if(!p[i]) for(j=2*i;j<N;j+=i) p[j]++;
	while(scanf("%d",&n)==1 && n)
	{
	      printf("%d : ",n);
		if(!p[n]) printf("1");
		else printf("%d",p[n]);
		printf("\n");
	}
	return 0;
}
