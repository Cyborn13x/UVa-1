#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 32

/*problem id-11045
 *
 *language-ANSI C
 *
 */

int data[6],flag,m;
char member[SZ][2][5],sz[][5]={"XXL","XL","L","M","S","XS"};

void BackTrack(int n)
{
      int i,j;
      if(n==m) { flag=1; return; }
      if(flag) return;
      for(i=0;i<6;i++) if(!strcmp(member[n][0],sz[i])) break;
      for(j=0;j<6;j++) if(!strcmp(member[n][1],sz[j])) break;
      if(data[i])
      {
            data[i]--;
            BackTrack(n+1);
            data[i]++;
      }
      if(data[j])
      {
            data[j]--;
            BackTrack(n+1);
            data[j]++;
      }
      return;
}

int main()
{
	int i,j,k,l,n,t,x,y,blank=0,test=0;
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d %d",&n,&m);
      	for(i=0,l=n/6;i<6;i++) data[i]=l;
      	for(i=flag=0;i<m;i++) scanf("%s %s",member[i][0],member[i][1]);
      	BackTrack(0);
      	printf("%s\n",flag ? "YES" : "NO");
      }
	return 0;
}
