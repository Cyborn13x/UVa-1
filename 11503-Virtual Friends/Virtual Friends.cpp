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

/*problem id- 11503
 *
 *language-C++
 *
 */

using namespace std;

int parent[100000];
int size[100000];

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

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
	int serial;
	int A;
	int B;
	char a[25];
	char b[25];
	map<string,int> index;
	scanf("%d",&t);
	while(t--)
	{
	      index.clear();serial=0;
	      memset(parent,0,sizeof(parent));
	      memset(size,0,sizeof(size));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s %s",a,b);
			if(!index[a])
			{
			      index[a]=++serial;
			      parent[index[a]]=index[a];
			      size[index[a]]=1;
			}
			if(!index[b])
			{
			      index[b]=++serial;
			      parent[index[b]]=index[b];
			      size[index[b]]=1;
			}
			A=FindParent(index[a]);
			B=FindParent(index[b]);
			if(A==B) printf("%d\n",size[A]);
			else
			{
			      if(A<=B)
			      {
			            parent[B]=A;
			            size[A]+=size[B];
			            printf("%d\n",size[A]);
			      }
			      else
			      {
			            parent[A]=B;
			            size[B]+=size[A];
			            printf("%d\n",size[B]);
			      }
			}
		}
	}
	return 0;
}
