

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
#define WRITE freopen("ot1.txt","w",stdout)
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define CPY(d,s) memcpy(d,s,sizeof(s))
#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define repl(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FOR(x,m,n) for(__typeof(n) x=(m);x<=(n);x++)
#define foreach(x,n) for(__typeof(n.begin()) x=n.begin();x!=n.end();x++)

#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sdd(x,y) scanf("%lf %lf",&x,&y)
#define sii(x,y) scanf("%d %d",&x,&y)
#define sll(x,y) scanf("%s %s",x,y)
#define sd(x) scanf("%lf",&x)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%s",x)
#define cii(x,y) cin>>x>>y
#define ci(x) cin >> x
#define gt getchar()

#define min(x,y) ((x<y)?(x):(y))
#define max(x,y) ((x>y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define pi 3.14159265358979323846
#define eps (1e-9)
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define isEq(a,b) (fabs((a)-(b))<eps)
#define Dist(x1,y1,x2,y2) (sqrt(sqr((x1)-(x2))+sqr((y1)-(y2))))
#define spDist(lat1,long1,lat2,long2,r) ((r)*acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos((long1)-(long2))))

#define LLU unsigned long long int
#define LL long long int
#define DD double
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
#define SZ 2001


/*problem id-11331
 *
 *UVA
 *
 */


using namespace std;

int a,b,c,k,W,B;
int clr[SZ],data[SZ][2],dp[SZ][SZ];
bool flag;
vi adj[SZ];


void DFSColor(int u,int cr)
{
      if(clr[u]!=-1)
      {
            if(clr[u]!=cr) flag=true;
            return;
      }

      clr[u]=cr;
      if(!cr) W++;
      else B++;

      rep(i,adj[u].sz()) DFSColor(adj[u][i],(cr+1)%2);

      return;
}


int DP(int n,int s)
{
      if(n<0 || s<0) return 0;
      if(dp[n][s]!=-1) return dp[n][s];

      return dp[n][s]=DP(n-1,s-data[n][0]) || DP(n-1,s-data[n][1]);
}


int main()
{
	//READ;


	int t,x,y;


	si(t);

	while(t--)
	{

	      k=0;
	      flag=false;

	      SET(clr);

		siii(b,c,a);

		repl(i,b+c) adj[i].cl();

		while(a--)
		{
			sii(x,y);

			adj[x].pb(y);
			adj[y].pb(x);
		}



		repl(i,b+c)
		{
		      if(clr[i]==-1)
		      {
		            W=0, B=0;

		            DFSColor(i,0);

		            if(flag) break;

		            data[++k][0]=W, data[k][1]=B;
		      }
		}

		if(flag)
		{
		      printf("no\n");
		      continue;
		}

		SET(dp);

		dp[0][0]=1;


		printf("%s\n",DP(k,b) ? "yes" : "no");


	}

	return 0;
}
