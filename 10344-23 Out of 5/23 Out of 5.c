#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10344
 *
 *language-ANSI C
 *
 */

int flag;
int a[5];
int used[5];

void DFS(int res,int len)
{
      int i;
      if(len==5 && res==23) { flag=1; return; }
      for(i=0;i<5 && !flag;i++)
      {
      	if(!used[i])
      	{
      	      used[i]=1;
      	      DFS(res+a[i],len+1);
      	      DFS(res-a[i],len+1);
      	      DFS(res*a[i],len+1);
      	      used[i]=0;
      	}
      }
      return;
}

int main()
{
	int i;
	while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]))
	{
		if(!a[0] && !a[1] && !a[2] && !a[3] && !a[4]) break;
		flag=0;
		for(i=0;i<5;i++)
		{
		      used[i]=1;
			DFS(a[i],1);
			used[i]=0;
		}
		printf(flag ? "Possible\n" : "Impossible\n");
	}
	return 0;
}
