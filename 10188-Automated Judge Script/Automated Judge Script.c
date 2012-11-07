#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ll long long int

/*problem id-10188
 *
 *language-ANSI C
 *
 */

char judge[100][150],contest[100][150];

void Solve(int n,int m,int test)
{
      int i,j,k,l,flag,f[300],x,y;
      char a[100*120],b[100*120];
      if(m==n)
      {
            for(i=0,flag=1;i<n;i++)
            {
            	if(strcmp(judge[i],contest[i])) { flag=0; break; }
            }
            if(flag)
            {
                  printf("Run #%d: Accepted\n",test);
                  return;
            }
      }
      for(i=x=0;i<n;i++)
      {
      	for(j=0,l=strlen(judge[i]);j<l;j++)
      	{
      		if(judge[i][j]>='0' && judge[i][j]<='9') a[x++]=judge[i][j];
      	}
      }a[x]=0;
      for(i=x=0;i<m;i++)
      {
      	for(j=0,l=strlen(contest[i]);j<l;j++)
      	{
      		if(contest[i][j]>='0' && contest[i][j]<='9') b[x++]=contest[i][j];
      	}
      }b[x]=0;
      if(strcmp(a,b))
      {
            printf("Run #%d: Wrong Answer\n",test);
      }
      else printf("Run #%d: Presentation Error\n",test);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d%*c",&n) && n)
	{
		for(i=0;i<n;i++) gets(judge[i]);
		scanf("%d%*c",&m);
		for(i=0;i<m;i++) gets(contest[i]);
		Solve(n,m,++test);
	}
	return 0;
}
