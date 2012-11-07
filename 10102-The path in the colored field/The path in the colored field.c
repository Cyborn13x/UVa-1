#include <stdio.h>

#define INF 100000
#define MINF -100000

/*problem id-443
 *
 *language-ANSI C
 *
 */

char grid[105][105];

int abs(int a) { return a<0 ? -a : a; }

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,tmp1,min,max,test=0;
      while(scanf("%d\n",&n)!=EOF)
      {
      	for(i=0;i<n;i++)
            {
                  for(j=0;j<n;j++) scanf("%c",&grid[i][j]);
                  getchar();
            }
      	for(i=0,max=MINF;i<n;i++)
      	{
      		for(j=0;j<n;j++)
      		{
      			if(grid[i][j]=='1')
      			{
      			      for(k=0,min=INF;k<n;k++)
      			      {
      			      	for(l=0;l<n;l++)
      			      	{
      			      		if(grid[k][l]=='3')
      			      		{
      			      		      tmp1=abs(i-k)+abs(j-l);
                                                if(tmp1<min) min=tmp1;
      			      		}
      			      	}
      			      }
      			      if(min>max) max=min;
      			}
      		}
      	}
      	printf("%d\n",max);
      }
	return 0;
}
