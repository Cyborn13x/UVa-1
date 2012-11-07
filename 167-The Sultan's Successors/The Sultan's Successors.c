#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-167
 *
 *language-ANSI C
 *
 */

int sum;
int maxsum;
int chess[8][8];
int row[8];
int dia1[20];
int dia2[20];

int abs(int a) { return a<0 ? -a : a; }

void Backtrack(int n)
{
      int i;
      if(n==8) return;
      for(i=0;i<8;i++)
      {
      	if(!row[i] && !dia1[n+i] && !dia2[8+n-i])
      	{
      	      sum+=chess[i][n];
      	      if(n==7) maxsum = sum>maxsum ? sum : maxsum;
      	      row[i]=dia1[n+i]=dia2[8+n-i]=1;
      	      Backtrack(n+1);
      	      row[i]=dia1[n+i]=dia2[8+n-i]=0;
      	      sum-=chess[i][n];
      	}
      }
      return;
}

int main()
{
	int i;
	int j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(i=sum=maxsum=0;i<8;i++) for(j=0;j<8;j++) scanf("%d",&chess[i][j]);
		Backtrack(0);
		printf("%5d\n",maxsum);
	}
	return 0;
}
