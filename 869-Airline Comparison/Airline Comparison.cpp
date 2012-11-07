#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#define N 256

/*problem id-869
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,flag,floyda[N][N],floydb[N][N];
	char src,end;
      scanf("%d",&t);
      while(t--)
      {
      	if(blank) putchar('\n');
      	scanf("%d\n",&n); blank=1;
      	memset(floyda,0,N*N*sizeof(int));
      	memset(floydb,0,N*N*sizeof(int));
      	for(i=0;i<n;i++)
      	{
      		scanf("%c %c\n",&src,&end);
      		floyda[src][end]=floyda[end][src]=1;
      	}
      	scanf("%d\n",&m);
      	for(i=0;i<m;i++)
      	{
      		scanf("%c %c\n",&src,&end);
      		floydb[src][end]=floydb[end][src]=1;
      	}
      	for(k=0;k<N;k++)
      	{
      		for(i=0;i<N;i++)
      		{
      			for(j=0;j<N;j++)
      			{
      			      if(floyda[i][k] && floyda[k][j]) floyda[i][j]=1;
      				if(floydb[i][k] && floydb[k][j]) floydb[i][j]=1;
      			}
      		}
      	}
      	for(i=flag=0;i<N && !flag;i++)
      	{
      		for(j=0;j<N && !flag;j++)
      		{
      			flag=(floyda[i][j]!=floydb[i][j]);
      		}
      	}
      	if(!flag) printf("YES\n");
      	else printf("NO\n");
      }
	return 0;
}
