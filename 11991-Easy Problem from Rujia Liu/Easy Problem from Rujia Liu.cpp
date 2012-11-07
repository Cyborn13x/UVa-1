#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define N 1000005

/*problem id-11991
 *
 *language-C++
 *
 */

using namespace std;

vector<int> vctr[N];
int Numbers[N];

int main()
{
	int i,j,n,m,k,v;

	while(scanf("%d %d",&n,&m)!=EOF)
	{
            for(i=0;i<n;i++) scanf("%d",&Numbers[i]);
            for(i=0;i<n;i++) vctr[i].clear();
            for(i=0;i<n;i++) vctr[Numbers[i]].push_back(i+1);
            for(i=0;i<m;i++)
            {
            	scanf("%d %d",&k,&v);
            	if(k>vctr[v].size()) printf("0\n");
            	else printf("%d\n",vctr[v][k-1]);
            }
	}
	return 0;
}
