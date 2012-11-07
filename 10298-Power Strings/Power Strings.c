#include <stdio.h>

#define INF 1<<30
#define SZ 1000006

/*problem id-10298
 *
 *language-ANSI C
 *
 */

int Preffix[SZ];

int KMPPreffix(char *a)
{
      int x,k=-1;
      for(x=1,Preffix[0]=-1;a[x];x++)
      {
      	while(k>-1 && a[k+1]!=a[x]) k=Preffix[k];
      	if(a[k+1]==a[x]) k++;
      	Preffix[x]=k;
      }
      return k+1;
}

int main()
{
	int n,x;
	char a[SZ];
	while(gets(a))
	{
		if(a[0]=='.' && !a[1]) break;
		x=(n=strlen(a))-KMPPreffix(a);
		if(n%x==0) printf("%d\n",n/x);
		else puts("1");
	}
	return 0;
}
