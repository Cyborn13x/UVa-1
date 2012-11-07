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
#define MEM(x,v) memset(x,v,sizeof(x))
#define CPY(d,s) memcpy(d,s,sizeof(s))
#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define repl(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FOR(x,m,n) for(__typeof(n) x=(m);x<=(n);x++)
#define pi 3.14159265358979323846
#define stream istringstream
#define mss map<string,string>
#define msi map<string,int>
#define mii map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define pq priority_queue
#define pss pair<string,string>
#define psi pair<string,int>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
#define eps (1e-9)
#define INF (1<<29)
#define SZ 105

/*problem id-10806
 *
 *language-C++
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

struct e
{
      int v,w;
};

e makeEdge(int x,int y)
{
      e tmp;
      tmp.v=x, tmp.w=y;
      return tmp;
}

bool operator<(e l,e r) { return l.w>r.w; }

int adj[SZ][SZ],d[SZ],p[SZ],N,ANS;
vector<e> wgt[SZ];

bool Dijkstra(int S,int T)
{
      int i,j,k,l,u,v,w,w1;
      e tmp;
      pq<e> q;
      repl(i,N) d[i]=INF;
      d[1]=0;
      q.push(makeEdge(1,d[1]));
      while(!q.empty())
      {
      	tmp=q.top(); q.pop();
      	u=tmp.v, w=tmp.w;
      	if(u==N)
      	{
      	      ANS+=d[N];
      	      return true;
            }
            l=wgt[u].size();
      	rep(i,l)
      	{
      	      v=wgt[u][i].v, w1=wgt[u][i].w;
      	      if(!adj[u][v] && w+w1<d[v])
      	      {
      	            d[v]=w+w1;
      	            p[v]=u;
      	            q.push(makeEdge(v,d[v]));
      	      }
      	}
      }
      return false;
}

void AugmentPath(int s,int t)
{
      if(t==s) return;
      AugmentPath(s,p[t]);
      adj[p[t]][t]=1;
      int l=wgt[t].size();
      rep(i,l)
      {
            int v=wgt[t][i].v;
            if(p[t]==v)
            {
                  wgt[t][i].w*=-1;
                  break;
            }
      }
      return;
}

void MaxFlow()
{
      int i,j,k,l=0;
      while(l<=1 && Dijkstra(1,N))
      {
            l++;
            AugmentPath(1,N);
      }
      if(l<2) ANS=-1;
      return;
}

int main()
{
      //READ;
	int x,y,z,m;
      while(scanf("%d",&N) && N)
      {
            CLR(adj);
            ANS=0;
            repl(i,N) wgt[i].clear();
      	scanf("%d",&m);
      	while(m--)
      	{
      		scanf("%d %d %d",&x,&y,&z);
      		wgt[x].pb(makeEdge(y,z));
      		wgt[y].pb(makeEdge(x,z));
      	}
      	MaxFlow();
      	if(ANS==-1) printf("Back to jail\n");
      	else printf("%d\n",ANS);
      }
	return 0;
}

