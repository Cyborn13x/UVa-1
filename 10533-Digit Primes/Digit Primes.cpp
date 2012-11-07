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
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define N 1000000
#define N1 sqrt(N)

/*problem id-10533
 *
 *language-C++
 *
 */

using namespace std;

bool p[N+5];
int data[N+5];

int sum(int n)
{
    int s=0;
    while(n)
    {
    	s+=n%10;
    	n/=10;
    }
    return s;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	p[0]=p[1]=true;l=0;
	for(i=4;i<=N;i+=2) p[i]=true;
	for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<=N;j+=2*i) p[j]=true;
	for(i=1;i<=N;i++)
	{
		if(!p[i] && !p[sum(i)]) l++;
		data[i]=l;
	}
	scanf("%d",&t);
    while(t--)
    {
    	scanf("%d %d",&m,&n);
    	l=data[n]-data[m];
    	if(data[m]==data[m-1]+1) l++;
    	printf("%d\n",l);
    }
	return 0;
}
