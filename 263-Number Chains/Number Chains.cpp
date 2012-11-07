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

/*problem id-263
 *
 *language-C++
 *
 */

using namespace std;

int a[20];
int lim;

void split(int n)
{
      lim=0;
      while(n)
      {
      	a[lim++]=n%10;
      	n/=10;
      }
      sort(a,a+lim);
      return;
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
	int x;
	int y;
	bool flag;
	map<int,bool> mp;
	while(scanf("%d",&n) && n)
	{
		printf("Original number was %d\n",n);
		mp.clear();l=0;
		flag=true;
		while(flag)
		{
			split(n);
			x=y=0;
			for(i=0,j=lim-1;i<lim;i++,j--) {x=10*x+a[i];y=10*y+a[j];}
			n=y-x;l++;
			if(mp[n]) flag=false;
			mp[n]=true;
			printf("%d - %d = %d\n",y,x,n);
		}
		printf("Chain length %d\n\n",l);
	}
	return 0;
}
