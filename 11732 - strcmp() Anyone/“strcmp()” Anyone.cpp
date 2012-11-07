

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
#define SZ 3000005

using namespace std;


struct node
{
      int records, finale, child, brother;
      char child_char, brother_char;
};


node trie[SZ];
LL tot;
int NC,n,m[200];
char s[1005];


void insert(char *a)
{
      int nd=1;

      for(int i=0 ; a[i] ; i++)
      {

      	++trie[nd].records;

      	char ch=m[a[i]];

      	// if current node has no children, create one
      	if(!trie[nd].child)
      	{

      	      ++NC;
      	      trie[NC].records=0;
                  trie[NC].child=0;
                  trie[NC].brother=0;
                  trie[NC].finale=0;

                  trie[nd].child=NC;
                  trie[nd].child_char=ch;

                  nd=NC;
                  continue;

      	}

      	// if the first child is too big, we need to create a new first child
            if(trie[nd].child_char>ch)
            {

                  ++NC;
                  trie[NC].records=0;
                  trie[NC].child=0;
                  trie[NC].finale=0;

                  trie[NC].brother=trie[nd].child;
                  trie[NC].brother_char=trie[nd].child_char;

                  trie[nd].child=NC;
                  trie[nd].child_char=ch;

                  nd=NC;
                  continue;

            }

            // if the first child exactly matches, just descend
            if(trie[nd].child_char==ch)
            {
                  nd=trie[nd].child;
                  continue;
            }

            // walk the list of children to find the matching one, create one if needed
            nd=trie[nd].child;
            while(trie[nd].brother && trie[nd].brother_char < ch) nd = trie[nd].brother;
            if(trie[nd].brother && trie[nd].brother_char==ch)
            {
                  nd=trie[nd].brother;
                  continue;
            }

            ++NC;
            trie[NC].records=0;
            trie[NC].child=0;
            trie[NC].finale=0;

            trie[NC].brother=trie[nd].brother;
            trie[NC].brother_char=trie[nd].brother_char;

            trie[nd].brother=NC;
            trie[nd].brother_char=ch;

            nd=NC;

      }

      ++trie[nd].records;
      ++trie[nd].finale;

      return;
}


void DFS(int nd,int depth)
{
      // every pair of words that reaches here produces two comparisons
      if(depth>0) tot += 1LL * trie[nd].records * (trie[nd].records-1);
      // every pair of words that differs exactly here produces one more comparison
      LL add = trie[nd].finale * (trie[nd].records - trie[nd].finale);
      int id=trie[nd].child;

      while(id)
      {
      	add += 1LL * trie[id].records * (trie[nd].records - trie[id].records);
      	DFS(id,depth+1);
      	id=trie[id].brother;
      }

      tot += add/2;
      // every pair of words that both end here produces one more comparison
      tot += 1LL * trie[nd].finale * (trie[nd].finale-1);
      return;
}


int main()
{
	//READ;

	int l,ts=0;

      FOR(i,'A','Z') m[i]=i-'A'+1;
	FOR(i,'a','z') m[i]=i-'a'+27;
	FOR(i,'0','9') m[i]=i-'0'+53;



      while(si(n) && n)
      {

      	NC=1, tot=0;

      	trie[1].records=0;
      	trie[1].child=0;
      	trie[1].brother=0;
      	trie[1].finale=0;


      	while(n--)
      	{
      	      sl(s);
                  insert(s);
      	}

      	DFS(1,0);

      	printf("Case %d: %lld\n",++ts,tot);
      }


	return 0;
}
