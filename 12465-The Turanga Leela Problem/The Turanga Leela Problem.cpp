
/*
 *SHAKIL AHMED
 *Bangladesh University of Engineering & Technology (BUET)
 *
 */

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
#include <cmath>
#include <ctime>
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
#define abs(x) ((x)<0 ? -(x) : (x))
#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define repl(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FOR(x,m,n) for(__typeof(n) x=(m);x<=(n);x++)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sdd(x,y) scanf("%lf %lf",&x,&y)
#define sii(x,y) scanf("%d %d",&x,&y)
#define sll(x,y) scanf("%s %s",x,y)
#define sd(x) scanf("%lf",&x)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%s",x)
#define sqr(x) (x*x)
#define pi 3.14159265358979323846
#define stream istringstream
#define mss map<string,string>
#define msi map<string,int>
#define mii map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define pqi priority_queue<int>
#define pss pair<string,string>
#define psi pair<string,int>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
#define eps (1e-9)
#define INF (1<<29)
#define SZ 100000

using namespace std;

typedef unsigned long long int llu;
typedef long long int ll;
typedef long double ld;
typedef double dd;

template<class T>inline T gcd(T a,T b) { return !b?a:gcd(b,a%b); }
template<class T>inline T lcm(T a,T b) { return a*(b/gcd(a,b)); }
template<class T>inline T power(T n,T p) { return !p ? 1:n*power(n,p-1); }
template<class T>inline T dis(T a,T b,T c,T d) { return sqrt(sqr(a-c)+sqr(b-d)); }

int on(int n,int pos) { return n=n|(1<<pos); }
int off(int n,int pos) { return n=n&~(1<<pos); }
int check(int n,int pos) { return n&(1<<pos); }
int toggle(int n,int pos) { return check(n,pos)?off(n,pos):on(n,pos); }
int isupper(char c) { return (c>='A'&&c<='Z'); }
int isvowel(char c) { return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'); }

#define N 32000
#define N1 sqrt(N)
#define lim N/4

/*problem id-12465
 *
 *language-C++
 *
 */

int p[N],prime[lim],last;

void Sieve()
{
      int i,j;

      prime[last++]=2;

      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;

      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;


      return;
}

int Divisor(int n)
{
      int i,p,ret=1;


      for(i=0;i<last && sqr(prime[i])<=n;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      p=0;
      	      while(n%prime[i]==0)
      	      {
      	      	p++;
      	      	n/=prime[i];
      	      }

      	      ret*=(p+1);
      	}
      }

      if(n>1) ret=ret<<1;


      return ret;
}

int main()
{
	//READ;
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0;
	Sieve();
	while(scanf("%d %d",&n,&m) && (n||m))
	{
		if(n>m) swap(n,m);
		printf("%d\n",Divisor(m-n));
	}
	return 0;
}

