#include <stdio.h>

#define INF 100000
#define last 22

/*problem id-10780
 *
 *language-ANSI C
 *
 */

const int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
int a[50],top;

int  min(int a,int b) { return a<b ? a : b; }

int FacPow(int n,int p)
{
      int ret=0;
      while(n) ret+=n/p, n/=p;
      return ret;
}

void Factorize(int n)
{
      int i,cnt;
      for(i=top=0;i<last && prime[i]*prime[i]<=n;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      a[top++]=prime[i], cnt=0;
      	      while(n%prime[i]==0) n/=prime[i], cnt++;
      	      a[top++]=cnt;
      	}
      }
      if(n!=1) a[top++]=n, a[top++]=1;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,ans;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d %d",&m,&n);
            top=0;
            Factorize(m);
            for(i=0,ans=INF;i<top;i+=2) ans=min(ans,FacPow(n,a[i])/a[i+1]);
      	if(ans) printf("Case %d:\n%d\n",++test,ans);
      	else printf("Case %d:\nImpossible to divide\n",++test);
      }
	return 0;
}
