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

using namespace std;

/*problem id-10034
 *
 *language-C++
 *
 */

typedef struct
{
    int num;
    double d;
}point;

struct compare
{
    bool operator()(const point& l, const point& r)
    {
        return l.d > r.d;
    }
};

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
	double ans;
	double x[102];
	double y[102];
	double dis[102];
	double data[102][102];
	bool vis[102];
	bool blank=false;
	point p[102];
	point tmp;
      priority_queue<point,vector<point>,compare> pq;
      scanf("%d",&t);
      while(t--)
      {
      	if(blank) printf("\n");
      	blank=true;ans=0;
      	memset(vis,false,sizeof(vis));
      	memset(data,0,sizeof(data));
      	scanf("%d",&n);
      	for(i=0;i<n;i++) scanf("%lf %lf",&x[i],&y[i]);
            for(i=0;i<n;i++) for(j=i+1;j<n;j++) data[i][j]=data[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            while(!pq.empty()) pq.pop();
            for(i=0;i<n;i++) {p[i].num=i;p[i].d=100000.00;}
            p[0].d=0;pq.push(p[0]);
            for(i=0;i<n;i++)
            {
            	tmp=pq.top();pq.pop();
            	if(vis[tmp.num]) {i--;continue;}
            	ans+=tmp.d;
            	for(j=0;j<n;j++) if(!vis[j] && data[tmp.num][j]<p[j].d && tmp.num!=j) {p[j].d=data[tmp.num][j];pq.push(p[j]);}
            	vis[tmp.num]=true;
            }
            printf("%.2lf\n",ans);
      }
	return 0;
}
