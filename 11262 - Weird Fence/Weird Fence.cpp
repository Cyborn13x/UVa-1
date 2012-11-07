

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

#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sdd(x,y) scanf("%lf %lf",&x,&y)
#define sii(x,y) scanf("%d %d",&x,&y)
#define sll(x,y) scanf("%s %s",x,y)
#define ciii(x,y,z) cin >>x>>y>>z
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
#define SZ 101

using namespace std;

int P,K,B,R,MX,RES,match[SZ<<1];
DD blue[SZ][2],red[SZ][2],ds[SZ][SZ];
bool vis[SZ<<1];
vi adj[SZ<<1];


bool DFS(int u)
{
      rep(i,adj[u].sz())
      {

            int v=adj[u][i];

            if(!vis[v])
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



int Matching()
{

      int MaxMatch=0;
      bool ok;


      SET(match);

      while(true)
      {

      	ok=true;

      	CLR(vis);

      	repl(i,B)
      	{
      	      if(match[i]==-1 && DFS(i))
      	      {
      	            MaxMatch++;
      	            ok=false;
      	      }
      	}

      	if(ok) break;

      }

      return MaxMatch;


}


void ConstructGraph(DD E)
{

      repl(i,B) adj[i].cl();

      rep(i,B)
      {
            rep(j,R)
            {
                  if(ds[i][j]<=E) adj[i+1].pb(j+1+B);
            }
      }


      return;

}


void Solve()
{
      int low=0, high=MX, mid;

      RES=-1;


      while(low<=high)
      {

      	mid=(low+high)>>1;


      	ConstructGraph((DD) mid);

      	int MM=Matching();

      	if(MM<K) low=mid+1;
      	else
      	{

      	      RES=mid;
      	      high=mid-1;

      	}


      }


      if(RES==-1) printf("Impossible\n");
      else printf("%d\n",RES);

      return;
}


int main()
{
	//READ;

	int T;
	char a[10];
	DD x,y;


	si(T);

	while(T--)
	{

            B=0, R=0, MX=0;

            sii(P,K);

            rep(i,P)
            {

                  sdd(x,y);
                  sl(a);

                  if(a[0]=='b') blue[B][0]=x, blue[B++][1]=y;
                  else red[R][0]=x, red[R++][1]=y;

            }

            rep(i,B)
            {
                  rep(j,R)
                  {
                        ds[i][j]=Dist(blue[i][0],blue[i][1],red[j][0],red[j][1]);
                        MX=max(MX,ceil(ds[i][j]));
                  }
            }

            Solve();


	}



	return 0;
}
