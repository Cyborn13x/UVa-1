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

/*problem id-914
 *
 *language-C++
 *
 */

using namespace std;

bool p[1000005];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int u;
	int t;
	int max;
	int last;
	int ans;
	int dif[150];
	p[0]=p[1]=1;
	for(i=4;i<1000005;i+=2) p[i]=true;
	for(i=3;i<500003;i+=2) if(!p[i]) for(j=2*i;j<1000005;j+=i) p[j]=true;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&u);
		memset(dif,0,sizeof(dif));
		for(i=l;p[i];i++);
		last=i;
		for(i=i+1;i<=u;i++)
		{
			if(!p[i])
			{
			      dif[i-last]++;
			      last=i;
			}
		}
		max=0;
		n=0;
		ans=0;
		for(i=1;i<150;i++)
		{
		      if(dif[i]>max)
		      {
		            max=dif[i];
		            ans=i;
		            n=1;
                  }
                  else if(max==dif[i]) n++;
		}
		if(n==1) printf("The jumping champion is %d\n",ans);
		else printf("No jumping champion\n");
	}
	return 0;
}
