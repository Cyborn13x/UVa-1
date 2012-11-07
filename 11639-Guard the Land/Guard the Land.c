#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11639
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,x1,x2,x3,x4,y1,y2,y3,y4,ans1,ans2,ans3,a[101][101];
	scanf("%d",&t);k=1;
	while(t--)
	{
	      scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	      memset(a,0,sizeof(a));ans1=ans2=ans3=0;
	      for(i=x1;i<x2;i++) for(j=y1;j<y2;j++) a[i][j]++;
	      for(i=x3;i<x4;i++) for(j=y3;j<y4;j++) a[i][j]++;
	      for(i=0;i<100;i++)
	      {
	      	for(j=0;j<100;j++)
	      	{
	      		if(!a[i][j]) ans3++;
	      		else if(a[i][j]==1) ans2++;
	      		else ans1++;
	      	}
	      }
		printf("Night %d: %d %d %d\n",k++,ans1,ans2,ans3);
	}
	return 0;
}
