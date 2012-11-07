#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-441
 *
 *language-ANSI C
 *
 */

int n;
int a[15];
int used[15];

void DFS(int len,int start)
{
      int i;
      int j;
      if(len==7)
      {
            for(i=j=0;i<n;i++)
            {
            	if(used[i])
            	{
            	      if(j) putchar(' ');
            	      printf("%d",a[i]);
            	      j++;
                  }
            }
            putchar('\n');
            return;
      }
      for(i=start;i<n;i++)
      {
            if(!used[i])
            {
                  used[i]=1;
                  DFS(len+1,i+1);
                  used[i]=0;
            }
      }
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	int x;
	int y;
	int blank=0;
      while(scanf("%d",&n) && n)
      {
      	if(blank) putchar('\n'); blank=1;
      	for(i=0;i<n;i++) scanf("%d",&a[i]);
      	DFS(1,0);
      }
	return 0;
}
