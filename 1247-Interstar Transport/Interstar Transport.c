#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 200000000

/*problem id-1247
 *
 *language-ANSI C
 *
 */

int floyd[30][30],path[30][30],N,str,end;

void PrintPath(int a,int b)
{
      if(path[a][b]==-1)
      {
            printf("%c ",a+'A');
            if(b==end) printf("%c\n",b+'A');
            return;
      }
      PrintPath(a,path[a][b]);
      PrintPath(path[a][b],b);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a,b;
	while(scanf("%d %d\n",&N,&m)!=EOF)
	{
		for(i=0;i<30;i++)
		{
			for(j=0;j<30;j++)
			{
				floyd[i][j]=INF, path[i][j]=-1;
			}floyd[i][i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%c %c %d\n",&a,&b,&x);
			floyd[a-'A'][b-'A']=floyd[b-'A'][a-'A']=x;
		}
		for(k=0;k<30;k++)
		{
			for(i=0;i<30;i++)
			{
				for(j=0;j<30;j++)
				{
					if(floyd[i][k]+floyd[k][j]<floyd[i][j])
					{
					      floyd[i][j]=floyd[i][k]+floyd[k][j];
					      path[i][j]=k;
					}
				}
			}
		}
		scanf("%d\n",&n);
		for(i=0;i<n;i++)
		{
			scanf("%c %c\n",&a,&b);
			PrintPath(str=a-'A',end=b-'A');
		}
	}
	return 0;
}
