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
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("ot.txt","w",stdout)
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
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
#define pss pair<string,string>
#define psi pair<string,int>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
#define eps (1e-9)
#define INF (1<<29)
#define SZ 300

/*problem id-259
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

bool adj[12][SZ],vis[SZ];
int match[SZ],tot;
char ans[15];
map<int,char> id;

bool DFS(int u)
{
      FOR(v,11,tot)
      {
      	if(adj[u][v] && !vis[v])
      	{
      	      vis[v]=true;
      	      if(match[v]==-1 || DFS(match[v]))
      	      {
      	            match[v]=u, match[u]=v;
      	            return true;
      	      }
      	}
      }
      return false;
}

void Matching()
{
      int MaxMatch=0;
      SET(match);
      rep(i,10)
      {
            if(match[i]!=-1) continue;
            CLR(vis);
            if(DFS(i)) MaxMatch++;
      }
      if(MaxMatch+10!=tot) strcpy(ans,"!");
      else
      {
            rep(i,10) ans[i]='_';
            FOR(i,11,tot) ans[match[i]]=id[i];
            ans[10]=0;
      }
      return;
}

int main()
{
      //READ;
	int i,j,x,task;
      char line[100],p[20];
      while(gets(line)!=NULL)
      {
            id.clear();
            CLR(adj);
            tot=10;
            if(!line[0]) { puts("!"); continue; }
      	do
      	{
      	      sscanf(line,"%c%1d %s",&task,&x,p);
      		for(i=tot+1;i<=tot+x;i++)
      		{
      		      id[i]=task;
      			for(j=0;p[j]!=';';j++) adj[p[j]-'0'][i]=1;
      		}tot+=x;
      	}while(gets(line)!=NULL && line[0]);
      	Matching();
      	puts(ans);
      }
	return 0;
}

