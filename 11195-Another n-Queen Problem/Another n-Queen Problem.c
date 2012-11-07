#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 30

/*problem id-11195
 *language-ANSI C
 *
 *BitMask এর ব্যাপক সেক্সি প্রবলেম
 *
 */

int row,col,dg1,dg2,res,N;
char a[SZ][SZ];

void Backtrack(int idx)
{
      int i,x=row,y=dg1,z=dg2, ok=x|y|z;
      if(idx==N) { res++; return; }
      for(i=0;i<N;i++)
      {
      	if(a[i][idx]=='.' && !(ok&(1<<i)))
      	{
      	      row=x|(1<<i);
      	      dg1=(y<<1)|(1<<(i+1));
      	      dg2=(z>>1)|(i>0 ? (1<<(i-1)) : 0);
      	      Backtrack(idx+1);
      	}
      }
      row=x, dg1=y, dg2=z;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d",&N) && N)
	{
	      row=col=dg1=dg2=0;
		for(i=res=0;i<N;i++) scanf("%s",a[i]);
            Backtrack(0);
            printf("Case %d: %d\n",++test,res);
	}
	return 0;
}
