

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
#define SZ 52


/*problem id-10937
 *
 *APSP+TSP(Bitmask DP)
 *
 */


using namespace std;

const int dx[]={1,-1,0,0,1,1,-1,-1};
const int dy[]={0,0,1,-1,1,-1,1,-1};

int h,w,cnt,dp[11][2048];
int id[SZ][SZ],ds[SZ][SZ],adj[11][11];
bool flag;
char g[SZ][SZ];


void BFS(int x,int y)
{
      int u=id[x][y], c=1;
      qi qx,qy;

      rep(i,h) rep(j,w) ds[i][j]=INF;

      qx.push(x);
      qy.push(y);
      ds[x][y]=0;

      while(!qx.empty())
      {
      	int x1=qx.front(), y1=qy.front();
      	qx.pop();
      	qy.pop();

      	rep(i,4)
      	{
      	      int x2=x1+dx[i], y2=y1+dy[i], v;
      	      if(x2<0 || x2>=h || y2<0 || y2>=w || ds[x2][y2]!=INF || g[x2][y2]=='#') continue;

      	      ds[x2][y2]=ds[x1][y1]+1;
      	      qx.push(x2);
      	      qy.push(y2);
      	      if((v=id[x2][y2])!=-1)
      	      {
      	            c++;
      	            adj[u][v]=ds[x2][y2];
      	      }
      	}
      }

      if(c<cnt) flag=true;

      return;

}


int DP(int u,int bitmask)
{
      int mn=INF;

      if(bitmask==((1<<cnt)-1)) return dp[u][bitmask]=adj[u][0];
      if(dp[u][bitmask]!=-1) return dp[u][bitmask];

      rep(i,cnt)
      {
            if(!(bitmask&(1<<i)))
            {
                  int ret=adj[u][i]+DP(i,bitmask|(1<<i));
                  if(ret<mn) mn=ret;
            }
      }

      return dp[u][bitmask]=mn;

}

int main()
{
	//READ;

	while(sii(h,w) && (h || w))
	{

	      cnt=1;
	      flag=false;
	      SET(id);
	      SET(dp);

	      rep(i,h) sl(g[i]);

	      rep(i,h) rep(j,w)
	      {
	            if(g[i][j]=='*')
	            {
	                  rep(k,8)
	                  {
	                        int x=i+dx[k], y=j+dy[k];
	                        if(x<0 || x>=h || y<0 || y>=w || g[x][y]=='#' || g[x][y]=='*') continue;
	                        if(g[x][y]=='@' || g[x][y]=='!') flag=true;
	                        g[x][y]='#';
	                  }
	            }
	            else if(g[i][j]=='!') id[i][j]=cnt++;
	            else if(g[i][j]=='@') id[i][j]=0;
	            else if(g[i][j]=='~') g[i][j]='#';
	      }

	      if(flag)
	      {
	            printf("-1\n");
	            continue;
	      }

            rep(i,cnt) rep(j,cnt) adj[i][j]=INF;
	      rep(i,cnt) adj[i][i]=0;

	      rep(i,h) rep(j,w) if(id[i][j]!=-1) BFS(i,j);

	      if(flag)
	      {
	            printf("-1\n");
	            continue;
	      }

	      printf("%d\n",DP(0,1));

	}

	return 0;
}
