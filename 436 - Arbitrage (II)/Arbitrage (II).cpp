

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
#define eps (1e-5)
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
#define SZ 32

using namespace std;


int main()
{
	//READ;

      int n,m,k,tr=0;
      STR a,b;
	DD f[SZ][SZ],t;
      msi id;

      while(si(n) && n)
      {

            k=0;

      	id.cl();

      	repl(i,n) repl(j,n) f[i][j]=0.0;
      	repl(i,n) f[i][i]=1.0;

      	rep(i,n)
      	{
      	      ci(a);

      	      id[a]=++k;
      	}

      	si(m);

      	rep(i,m)
      	{

                  ciii(a,t,b);


                  int x=id[a], y=id[b];


                  f[x][y]=t;

      	}


      	repl(k,n)
      	{
      	      repl(i,n)
      	      {
      	            repl(j,n)
      	            {
      	                  f[i][j]=max(f[i][j],f[i][k]*f[k][j]);
      	            }
      	      }
      	}


      	bool flag=false;

      	repl(i,n) if(f[i][i]>1+eps) flag=true;

      	printf("Case %d: ",++tr);


      	printf("%s\n",flag ? "Yes" : "No");

      }



	return 0;
}
