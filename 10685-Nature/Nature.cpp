#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
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
#include <algorithm>

/*problem id-10685
 *
 *language-C++
 *
 */

using namespace std;

int parent[5000];
int size[5000];

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

int main()
{
      freopen("in.txt","r",stdin);
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int serial;
	int A;
	int B;
	char a[35];
	char b[35];
	map<string,int> index;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		index.clear();serial=0;x=n;y=0;
		memset(size,0,sizeof(size));
		while(n--)
		{
			scanf("%s",a);
			index[a]=serial++;
			parent[index[a]]=index[a];
			size[index[a]]=1;
		}
		while(m--)
		{
			scanf("%s %s",a,b);
			A=FindParent(index[a]);
			B=FindParent(index[b]);
			if(A!=B)
			{
			      if(A<=B)
			      {
			            parent[B]=A;
			            size[A]+=size[B];
			      }
			      else
			      {
			            parent[A]=B;
			            size[B]+=size[A];
			      }
			}
		}
		for(i=0;i<x;i++) y = size[i]>y ? size[i] : y;
		printf("%d\n",y);
	}
	return 0;
}
