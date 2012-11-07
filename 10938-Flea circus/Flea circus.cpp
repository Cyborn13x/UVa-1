#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <bitset>
#include <memory>
#include <ctime>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("ot.txt","w",stdout)
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define CPY(d,s) memcpy(d,s,sizeof(s))
#define rep(x,n) for(x=0;x<(n);x++)
#define repl(x,n) for(x=1;x<=(n);x++)
#define FOR(x,m,n) for(x=(m);x<=(n);x++)
#define pi 3.14159265358979323846
#define stream istringstream
#define mss map<string,string>
#define msi map<string,int>
#define mii map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define pss pair<string,string>
#define psi pair<string,int>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
#define eps (1e-9)
#define INF (1<<29)
#define SZ 5002

/*problem id-10938
 *
 *Algorithm-Run two BFS and find the middle point
 *
 */

using namespace std;

typedef unsigned long long int ui64;
typedef long long int i64;
typedef long double ld;
typedef double dd;

template<class T>inline T abs(T a,T b) { return (a<0) ? -a : a; }
template<class T>inline T gcd(T a,T b) { return !b?a:gcd(b,a%b); }
template<class T>inline T lcm(T a,T b) { return a*(b/gcd(a,b)); }
template<class T>inline T power(T n,T p) { return !p ? 1:n*power(n,p-1); }
template<class T>inline T sqr(T a) { return a*a; }
template<class T>inline T dis(T a,T b,T c,T d) { return sqrt(sqr(a-c)+sqr(b-d)); }

int on(int n,int pos) { return n=n|(1<<pos); }
int off(int n,int pos) { return n=n&~(1<<pos); }
int check(int n,int pos) { return n&(1<<pos); }
int toggle(int n,int pos) { return check(n,pos)?off(n,pos):on(n,pos); }
int isupper(char c) { return (c>='A'&&c<='Z'); }
int isvowel(char c) { return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'); }

int main()
{
      //READ;
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0,p1[SZ],p2[SZ],d1[SZ],d2[SZ],u,v;
	vi adj[SZ];
	qi q;
	while(scanf("%d",&n) && n)
	{
		repl(i,n) adj[i].clear();
		z=n-1;
		while(z--)
		{
			scanf("%d %d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d %d",&x,&y);
			CLR(d1); SET(p1);
                  while(!q.empty()) q.pop();
                  q.push(x); p1[x]=x, d1[x]=0;
                  while(!q.empty())
                  {
                  	u=q.front(); q.pop();
                  	if(u==y) break;
                  	l=adj[u].size();
                  	rep(i,l)
                  	{
                  	      v=adj[u][i];
                  	      if(d1[v]) continue;
                  	      d1[v]=d1[u]+1, p1[v]=u;
                  	      q.push(v);
                  	}
                  }
                  while(!q.empty()) q.pop();
                  CLR(d2); SET(p2);
                  q.push(y); p2[y]=y, d2[y]=0;
                  while(!q.empty())
                  {
                  	u=q.front(); q.pop();
                  	if(u==x) break;
                  	l=adj[u].size();
                  	rep(i,l)
                  	{
                  	      v=adj[u][i];
                  	      if(d2[v]) continue;
                  	      d2[v]=d2[u]+1, p2[v]=u;
                  	      q.push(v);
                  	}
                  }
                  u=x, l=d2[u]>>1;
                  if(d2[u]&1)
                  {
                        l++;
                        while(d2[u]!=l) u=p2[u];
                        v=p2[u];
                        if(u>v) swap(u,v);
                        printf("The fleas jump forever between %d and %d.\n",u,v);
                        continue;
                  }
                  while(d2[u]!=l) u=p2[u];
                  printf("The fleas meet at %d.\n",u);
		}
	}
	return 0;
}

