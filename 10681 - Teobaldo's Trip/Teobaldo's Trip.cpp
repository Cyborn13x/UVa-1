


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
#define SZ 101

/*problem id-10681
 *
 *language-C++
 *
 *Matrix Multiplication Theory
 *Finding shortest path in a graph from start node
 *to end node which consists of exactly N edges (N can be very large)
 *
 */

using namespace std;


int C,L,S,E,D;
int adj[SZ][SZ],dis[SZ][SZ],tmp[SZ][SZ];


void Floyd(int a[][SZ],int b[][SZ])
{

      CLR(tmp);

      repl(k,C) repl(i,C) repl(j,C) if(a[i][k] && b[k][j]) tmp[i][j]=1;//Floyd Warshell

      repl(i,C) repl(j,C) a[i][j]=tmp[i][j];//copying the data of tmp to dis / adj.

      return;
}

int MatrixMultiply()
{

      while(D)
      {
      	if(D&1) Floyd(dis,adj); //if the last bit is 1 then add adj^x to dis.

      	Floyd(adj,adj); //square the adj matrix, ie : adj^4*adj^4=adj^8

      	D>>=1;
      }


      return dis[S][E];

}

int main()
{

      //READ;

      int x,y,ANS;

	while(sii(C,L) && ( C || L ))
	{

	      CLR(adj);
	      CLR(dis);
	      repl(i,C) dis[i][i]=1;

	      while(L--)
	      {
	      	sii(x,y);

	      	adj[x][y]=adj[y][x]=1;
	      }

	      siii(S,E,D);

            ANS=MatrixMultiply();

		if(ANS) printf("Yes, Teobaldo can travel.\n");
		else printf("No, Teobaldo can not travel.\n");


	}
	return 0;
}
