

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
#define SZ 100005

using namespace std;

struct siti
{
    int l,r,e;

}grid[30][105];
char a[20],b[20];
int lst[30][105];

int main()
{
    //READ
    bool f;
    int t,ca,n,i,j,k,p,q,r,c,m,lr,lc;
    while(scanf("%d %d",&r,&c)==2 && (r || c))
    {
        CLR(lst);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                grid[i][j].e=grid[i][j].l=grid[i][j].r=-1;
            }
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %s",a,b);
            lr=a[0]-'A'+1;
            lc=0;
            for(j=1;a[j];j++)lc=lc*10+a[j]-'0';
            if(grid[lr][lc].e==-1) grid[lr][lc].e=1;
            if(b[0]=='-')
            {
                grid[lr][lc].l=1;
                grid[lr][lc-1].r=1;
            }
            else if(b[0]=='+')
            {
                grid[lr][lc].r=1;
                grid[lr][lc+1].l=1;
            }
        }
        scanf("%d",&n);
        f=true;
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            lr=a[0]-'A'+1;
            lc=0;
            for(j=1;a[j];j++)lc=lc*10+a[j]-'0';
            lst[lr][lc]=1;
        }
        for(i=1;i<=r;i++)
        {
            if(!f) break;
            for(j=1;j<=c;j++)
            {
                if(!f) break;
                if(lst[i][j])
                {
                    if(grid[i][j].e==-1)
                    {
                        if(grid[i][j].l==-1)
                        {
                            grid[i][j].l=1;
                            grid[i][j-1].r=1;
                        }
                        else if(grid[i][j].r==-1)
                        {
                            grid[i][j].r=1;
                            grid[i][j+1].l=1;
                        }
                        else f=false;
                    }
                    else f=false;
                }
            }
        }
        if(f)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
