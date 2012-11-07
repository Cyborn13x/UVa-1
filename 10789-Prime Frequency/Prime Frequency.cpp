#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define N 2001

/*problem id-10789
 *
 *language-C++
 *
 */

bool prime[N];

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
	int a[150];
	char s[2005];
	bool flag;
	prime[0]=prime[1]=true;
	for(i=4;i<N;i+=2) prime[i]=true;
	for(i=3;i<N/2;i+=2) for(j=2*i;j<N;j+=i) prime[j]=true;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
	    flag=false;
	    memset(a,0,sizeof(a));
		scanf("%s",s);
		printf("");
		for(j=0;s[j];j++) a[s[j]]++;
		printf("Case %d: ",i+1);
		for(j='0';j<='z';j++) if(!prime[a[j]]) {printf("%c",j);flag=true;}
		if(!flag) printf("empty");
		printf("\n");
	}
	return 0;
}
