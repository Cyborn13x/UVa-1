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

/*problem id-10369
 *
 *language-C++
 *
 */

using namespace std;

int parent[502];

typedef struct
{
      int u;
      int v;
      double w;
}edge;

struct compare
{
    bool operator()(const edge& l, const edge& r)
    {
        return l.w > r.w;
    }
};

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
	int s;
	int p;
	int A;
	int B;
	int x[500];
	int y[500];
	edge tmp;
	priority_queue<edge,vector<edge>,compare> pq;
	scanf("%d",&t);
	while(t--)
	{
	      while(!pq.empty()) pq.pop();
		scanf("%d %d",&s,&p);k=0;l=p-s;
		for(i=0;i<p;i++) {scanf("%d %d",&x[i],&y[i]);parent[i]=i;}
		for(i=0;i<p;i++)
		{
		      tmp.u=i;
			for(j=1;j<p;j++)
			{
			      if(j!=i)
				{
				      tmp.v=j;
                              tmp.w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                              pq.push(tmp);
				}
			}
		}
		while(1)
		{
			tmp=pq.top();pq.pop();
			A=FindParent(tmp.u);
			B=FindParent(tmp.v);
			if(A!=B)
			{
			      A<=B ? parent[B]=A : parent[A]=B;
			      k++;if(k==l) break;
			}
		}
		printf("%.2lf\n",sqrt(tmp.w));
	}
	return 0;
}
