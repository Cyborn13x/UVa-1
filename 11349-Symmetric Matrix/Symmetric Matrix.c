#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11349
 *
 *language-ANSI C
 *
 */

long long int  matrix[101][101],N;

int check()
{
      int i,j;
      for(i=0;i<N;i++)
      {
      	for(j=0;j<N;j++)
      	{
      		if(matrix[i][j]!=matrix[N-i-1][N-j-1]) return 0;
      	}
      }
      return 1;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,flag;
	char a[50];
      scanf("%d",&t);
      while(t--)
      {
            gets(a); /**This is not input ,it's for clearing the buffer**/
      	gets(a);
      	sscanf(a,"N = %d",&N);
      	for(i=0,flag=1;i<N;i++)
      	{
      		for(j=0;j<N;j++)
      		{
      			scanf("%lld",&matrix[i][j]);
      			if(matrix[i][j]<0) flag=0;
      		}
      	}printf("Test #%d: ",++test);
      	if(!flag)
      	{
      	      printf("Non-symmetric.\n");
      	      continue;
      	}
      	if(!check()) printf("Non-symmetric.\n");
      	else printf("Symmetric.\n");
      }
	return 0;
}
