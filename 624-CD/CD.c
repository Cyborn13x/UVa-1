#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-624
 *
 *language-ANSI C
 *
 */

int N;
int cd;
int top;
int sum;
int a[50];
int ans[50];
int used[50];

void DFS(int tmp,int indx)
{
      int i;
      if(tmp>N) return;
      if(tmp<=N && tmp>sum)
      {
            sum=tmp;
            for(i=top=0;i<cd;i++) if(used[i]) ans[top++]=a[i];
      }
      for(i=indx;i<cd;i++)
      {
      	if(!used[i])
      	{
      	      used[i]=1;
      	      DFS(tmp+a[i],i+1);
      	      used[i]=0;
      	}
      }
      return;
}

int main()
{
	int i;
	while(scanf("%d",&N)!=EOF)
	{
		scanf("%d",&cd);
		for(i=0;i<cd;i++) scanf("%d",&a[i]);
		memset(used,0,sizeof(used));
		DFS(sum=0,0);
		for(i=0;i<top;i++)  printf("%d ",ans[i]);
		printf("sum:%d\n",sum);
	}
	return 0;
}
