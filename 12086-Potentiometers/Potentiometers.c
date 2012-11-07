#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define SIZE 200002

/*problem id-12086
 *
 *language-ANSI C
 *
 */

int N;
long long int BIT[SIZE];
long long int list[SIZE];

void Update(long long int n,int idx)
{
      while(idx<=N)
      {
      	BIT[idx]+=n;
      	idx+=idx&(-idx);
      }
      return;
}

long long int Sum(int idx)
{
      long long int s=0;
      while(idx)
      {
      	s+=BIT[idx];
      	idx-=idx&(-idx);
      }
      return s;
}

int main()
{
	int i;
	int t;
	int x;
	int blank=0;
	int test=0;
	long long int y;
	char a[5];
	while(scanf("%d",&N) && N)
	{
	      if(blank) printf("\n");
	      for(i=blank=1;i<=N;i++)
	      {
	      	scanf("%lld",&list[i]);
	      	Update(list[i],i);
	      }
	      printf("Case %d:\n",++test);
		while(scanf("%s",a) && strcmp(a,"END"))
		{
		      scanf("%d %lld",&x,&y);
                  if(a[0]=='S')
			{
			      t=y-list[x];
			      list[x]=y;
			      Update(t,x);
			}
			else printf("%lld\n",Sum(y)-Sum(x-1));
		}
		memset(BIT,0,SIZE*sizeof(long long int));
	}
	return 0;
}
