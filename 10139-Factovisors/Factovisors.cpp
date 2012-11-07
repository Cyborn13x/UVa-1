#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10139
 *
 *language-C++
 *
 */

using namespace std;

#define N 46500
#define N1 sqrt(N)
#define lim N/2

bool p[N];
int prime[lim];
int last;

void Sieve()
{
      int i;
      int j;
      int k=1;
      prime[0]=2;
      for(i=4;i<N;i+=2) p[i]=true;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=true;
      for(i=3;i<N;i+=2) if(!p[i]) prime[k++]=i;
      last=k;
      return;
}

int HighestPower(int n,int prm)
{
      int c=0;
      while(prm<=n)
      {
      	c+=n/prm;
      	n/=prm;
      }
      return c;
}

int main()
{
      //freopen("in.txt","r",stdin);
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	bool flag;
	bool felag;
	Sieve();
	while(scanf("%d %d",&n,&m)==2)
	{
	      flag=true;
	      if(!n && m==1) printf("%d divides %d!\n",m,n);
	      else if(!n && m>1) printf("%d does not divide %d!\n",m,n);
	      else if(!m) printf("%d does not divide %d!\n",m,n);
		else if(m<=n) printf("%d divides %d!\n",m,n);
		else
		{
		      x=m;felag=false;
                  for(i=0;prime[i]*prime[i]<=x && i<last && flag;i++)
                  {
                        if(x%prime[i]==0)
                        {
                              felag=true;
                              k=0;
                              while(x%prime[i]==0)
                              {
                              	k++;
                              	x/=prime[i];
                              }
                              l=HighestPower(n,prime[i]);
                              if(k>l) flag=false;
                        }
                  }
                  if(x!=1 && HighestPower(n,x)==0) flag=false;
                  if(!felag) {flag=false;}
                  if(flag) printf("%d divides %d!\n",m,n);
                  else printf("%d does not divide %d!\n",m,n);
		}
	}
	return 0;
}
