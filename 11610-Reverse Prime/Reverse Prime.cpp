#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define six 1000000
#define seven 10000000
#define size 78500
#define N 1000002
#define N1 sqrt(N)
#define lim 78500

/*problem id-11610
 *
 *language-C++
 *
 */

using namespace std;

int p[N],prime[lim],last,top=1,RevPrime[size],sum[size],bit[size];
map<int,int> idx;
set<int> DelIdx;
set<int>::iterator it;

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int RevNum(int n)
{
      int ret=0;
      while(n) ret=ret*10+n%10, n/=10;
      return ret;
}

int PrimeFactor(int n)
{
      int i,ret=0;
      for(i=0;i<last && prime[i]*prime[i]<=n;i++)
      {
            while(n%prime[i]==0)
            {
                  n/=prime[i], ret++;
            }
      }
      if(n!=1) ret++;
      return ret;
}

int StartPoint(int n)
{
      for(it=DelIdx.begin(),n++;it!=DelIdx.end() && *it<=n;it++) n++;
      return n;
}

void BITDelete(int n)
{
      int del=sum[n]-sum[n-1];
      DelIdx.insert(n);
      while(n<top) bit[n]-=del, n+=(n&-n);
      return;
}

int BITSum(int n)
{
      int ret=0;
      while(n>0) ret+=bit[n], n-=n&-n;
      return ret;
}

void PreCal()
{
      int i,j,tmp;
      Sieve();
      for(i=six+70;i<seven;i+=10)
      {
      	if((tmp=RevNum(i))<six && !p[tmp])
      	{
      	      RevPrime[top]=i;
      	      idx[i]=top++;
      	}
      }
      for(i=1;i<top;i++) sum[i]=sum[i-1]+PrimeFactor(RevPrime[i]);
      for(i=1;i<top;i++) bit[i]=sum[i]-sum[i-(i&-i)];
      return;
}

int main()
{
	int n;
	char c;
	PreCal();
      while(scanf("%c %d\n",&c,&n)!=EOF)
      {
      	if(c=='q') printf("%d\n",BITSum(StartPoint(n)));
      	else BITDelete(idx[n]);
      }
	return 0;
}
