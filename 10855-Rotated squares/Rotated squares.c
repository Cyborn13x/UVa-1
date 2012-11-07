#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10855
 *
 *language-ANSI C
 *
 */

int N,n;
char a[105][105],b[105][105],c[105][105];

void Rotate()
{
      int i,j;
      for(i=0;i<n;i++)
      {
      	for(j=0;j<n;j++)
      	{
      		c[j][n-i-1]=b[i][j];
      	}
      }
      for(i=0;i<n;i++) strcpy(b[i],c[i]);
      return;
}

int Count()
{
      int i,j,k,l,c=N-n,flag,ret=0;
      for(i=0;i<=c;i++)
      {
      	for(j=0;j<=c;j++)
      	{
      		for(k=0,flag=1;k<n && flag;k++)
      		{
      			for(l=0;l<n && flag;l++)
      			{
      				if(a[i+k][j+l]!=b[k][l]) flag=0;
      			}
      		}
      		if(flag) ret++;
      	}
      }
      return ret;
}

int main()
{
	int i,j,k,l,m,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&N,&n) && (N || n))
	{
		for(i=0;i<N;i++) scanf("%s",a[i]);
		for(i=0;i<n;i++) scanf("%s",b[i]);
		printf("%d",Count());
		Rotate();
		printf(" %d",Count());
		Rotate();
		printf(" %d",Count());
		Rotate();
		printf(" %d\n",Count());
	}
	return 0;
}
