

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
#define SZ 105

using namespace std;

LL sum[10];

LL digitsum(LL a,LL m)
{
    if(a<=0) return 0;
    else
    {
        LL l,ret=0,left=0,b;
        l=a%10;
        b=a/10;
        a/=10;
        while(b)
        {
            left=left+b%10;
            b/=10;
        }
        return sum[l]*m+left*(1+l)*m+ a*45*m+digitsum(a-1,m*10);
    }
}

int main()
{
    int a,b;
    while(sii(a,b)==2)
    {
        rep(i,10) sum[i]=i;
        FOR(i,1,9) sum[i]+=sum[i-1];
        if(a==0 || b==0) break;
        if(a>b) swap(a,b);
        LL ret=digitsum((LL)b,1);
        ret-=digitsum((LL)a-1,1);
        printf("%lld\n",ret);
    }
    return 0;
}


/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
#include <utility>
#include <algorithm>
#define f first
#define s second
using namespace std;

//fahim zubayer's solution

long long ar[50];

long long find_sum(long long x){
	long long a,b,c,d,e,y,z;
	e=1;
	z=0;
	y=x;
	while(1){
		ar[z++]=y%10;
		y=y/10;
		if(y<=0) break;
	}
	d=0;
	c=0;
	y=x;
	for(a=0;a<z;a++){
		c=c+(d+1)*ar[a];
		for(b=0;b<ar[a];b++) c=c+b*e;
		d=ar[a]*e+d;
		e=e*10;
		y=x-d;
		y=y/10;
		for(b=0;b<=9;b++) c=c+b*y;
	}
	return c;
}

int main(){

	long long x,y;
	while(1){
		cin>>x>>y;
		if(x==0 && y==0) break;
		cout<<find_sum(y)-find_sum(x-1)<<endl;
	}
	return 0;
}

///another solution
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<deque>
#include<set>
#define MAX 100000
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
#define sf scanf
#define pf printf
#define pb push_back
using namespace std;

ll p(int a,int n)
{
	ll res=1;
	for(int i=0;i<n;i++)
		res*=a;
	return res;
}

ll sum(ll n)
{
  ll ans=0;
  while(n)
  {
    ans+=n%10;
    n=n/10;
  }
  return ans;
}

int dig(ll a)
{
	int ans=0;
	while(a)
	{
		a/=10;
		ans++;
	}
	return ans;
}

ll a[11]={0};

ll ResSum(ll b)
{
	int c=dig(b);
	ll ans=0;
	for(int j=c-1;j>=0;j--)
	{
		int temp=(b/p(10,j))%10;
		int old=0;
		for(int k=c-1;k>j;k--)
			old+=b/p(10,k)%10;
		int temp2=0;
		for(int k=0;k<temp;k++)
			temp2+=k;
		ans+=old*temp*p(10,j)+a[j]*temp+temp2*p(10,j)+temp;
	}
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll n,m;
	for(int i=0;i<10;i++)
	{
		a[i+1]=a[i]*10+45*p(10,i);

	}
	while(scanf("%lld %lld",&n,&m)&&(n||m))
	{
		pf("%lld\n",ResSum(m)-ResSum(n-1));
	}

	//cout<<ans<<endl;
	return 0;
}
*/
