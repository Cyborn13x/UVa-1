

/*
 *SHAKIL AHMED
 *Bangladesh University of Engineering & Technology (BUET)
 *shakilbuet63@gmail.com
 *
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <bitset>
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
#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define repl(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FOR(x,m,n) for(__typeof(n) x=(m);x<=(n);x++)
#define foreach(x,n) for(__typeof(n.begin()) x=n.begin();x!=n.end();x++)

#define sddd(x,y,z) scanf("%lf %lf %lf",&x,&y,&z)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define slll(x,y,z) scanf("%s %s %s",x,y,z)
#define sdd(x,y) scanf("%lf %lf",&x,&y)
#define sii(x,y) scanf("%d %d",&x,&y)
#define sll(x,y) scanf("%s %s",x,y)
#define ciii(x,y,z) cin>>x>>y>>z
#define sd(x) scanf("%lf",&x)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%s",x)
#define cii(x,y) cin>>x>>y
#define ci(x) cin >> x
#define gs(a) gets(a)
#define gt getchar

#define min(x,y) ((x<y)?(x):(y))
#define max(x,y) ((x>y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define eps (1e-9)
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define pi 3.14159265358979323846
#define isEq(a,b) (fabs((a)-(b))<eps)
#define Dist(x1,y1,x2,y2) (sqrt(sqr((x1)-(x2))+sqr((y1)-(y2))))
#define spDist(lat1,long1,lat2,long2,r) ((r)*acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos((long1)-(long2))))

#define LLU unsigned long long int
#define LL long long int
#define DD double
#define BL bool
#define strm istringstream
#define pq priority_queue
#define STR string
#define pb push_back
#define mp make_pair
#define cl clear
#define sz size
#define ff first
#define ss second

#define pii pair<int,int>
#define psi pair<STR,int>
#define mib map<int,bool>
#define mii map<int,int>
#define msi map<STR,int>
#define vi vector<int>
#define qi queue<int>

#define INF (1<<29)
#define SZ 100

using namespace std;

int N,ign;
BL vis[SZ],nvis[SZ],res[SZ][SZ];
vi adj[SZ];


void DFS(int u,bool state)
{
      if(u==ign) return;
      if(state==true && vis[u]) return;
      if(!state && nvis[u]) return;

      if(state) vis[u]=true;
      else nvis[u]=true;

      rep(i,adj[u].sz()) DFS(adj[u][i],state);

      return;
}


int main()
{
	//READ;


	int T,x,ts=0;

	si(T);

	while(T--)
	{

		CLR(vis);
		CLR(res);

		si(N);

		rep(i,N) adj[i].cl();

		rep(i,N)
		{
		      rep(j,N)
		      {
		            si(x);

		            if(x) adj[i].pb(j);
		      }
		}

		ign=-1;

		DFS(0,true);

		rep(i,N) if(vis[i]) res[i][i]=res[0][i]=true;

		repl(i,N-1)
		{

		      ign=i;
		      CLR(nvis);

		      DFS(0,false);

		      repl(j,N-1) if(vis[j] && !nvis[j]) res[ign][j]=true;

		}

            printf("Case %d:\n",++ts);

		rep(i,N)
		{
		      printf("+");
		      rep(j,2*N-1) printf("-");
		      printf("+\n");

		      rep(j,N) printf("|%c",res[i][j]==true?'Y':'N');
		      printf("|\n");
		}

		printf("+");
            rep(j,2*N-1) printf("-");
            printf("+\n");

	}


	return 0;
}
