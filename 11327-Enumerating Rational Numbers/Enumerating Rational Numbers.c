#include<stdio.h>

#define N 200004
#define N1 N/2

/*problem id-11327
 *
 *language-ANSI C
 *
 */

typedef unsigned long long ull;

int p[N],phi[N];
ull sum[N];

void EulerPhiSieve()
{
      int i,j;
      phi[1]=2, phi[2]=1;
      for(i=3;i<N;i++) phi[i]=i;
      for(i=4;i<N;i+=2) { phi[i]/=2;p[i]=1; }
      for(i=3;i<N;i+=2)
      {
      	if(!p[i])
      	{
      	      phi[i]=i-1;
      	      for(j=i+i;j<N;j+=i) { phi[j]/=i; phi[j]*=(i-1); p[j]=1; }
      	}
      }
      return;
}

void PreCal()
{
      int i;
      EulerPhiSieve();
      for(i=1;i<N;i++) sum[i]=(ull)phi[i]+sum[i-1];
      return;
}

int gcd(int a,int b)
{
      if(!b) return a;
      else gcd(b,a%b);
}

int BinarySearch(int low,int high,ull val)
{
      int mid;
      while(low<=high)
      {
      	mid=(low+high)/2;
      	if(val>sum[mid])
      	{
      	      low=mid+1;
      	      if(val<sum[mid+1]) return mid+1;
      	}
      	else if(val==sum[mid]) return mid;
      	else
      	{
      	      high=mid-1;
      	      if(val>sum[mid-1]) return mid;
      	}
      }
}

void Solve(ull K)
{
      int i,idx,remain;
      if(K==1) { printf("0/1\n"); return; }
      idx=BinarySearch(1,N,K);
      remain=K-sum[idx-1];
      for(i=1;i<idx;i++)
      {
            if(gcd(idx,i)==1) remain--;
            if(!remain) break;
      }
      printf("%d/%d\n",i,idx);
      return;
}

int main()
{
	ull K;
      PreCal();
      while(scanf("%llu",&K) && K) Solve(K);
	return 0;
}
