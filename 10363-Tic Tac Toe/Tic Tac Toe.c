#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 100000

/*problem id-10636
 *
 *language-ANSI C
 *
 */

char a[3][4],W1,W2;

int Check(char c)
{
      return
      ((a[0][0]==c && a[0][1]==c && a[0][2]==c)||
      (a[1][0]==c && a[1][1]==c && a[1][2]==c)||
      (a[0][1]==c && a[1][1]==c && a[2][1]==c)||
      (a[0][0]==c && a[1][0]==c && a[2][0]==c)||
      (a[2][0]==c && a[2][1]==c && a[2][2]==c)||
      (a[0][2]==c && a[1][2]==c && a[2][2]==c)||
      (a[0][0]==c && a[1][1]==c && a[2][2]==c)||
      (a[0][2]==c && a[1][1]==c && a[2][0]==c));
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,X,O,A,B,blank=0,test=0;
      scanf("%d",&t);
      while(t--)
      {
            getchar();
            X=O=0;
      	FOR(i,3)
      	{
      		FOR(j,3)
      		{
      		      a[i][j]=getchar();
      			if(a[i][j]=='X') X++;
      			else if(a[i][j]=='O') O++;
      		}getchar();
      	}
      	A=Check('X'), B=Check('O');
      	if((A && B) || (A && X-O!=1) || (B && X-O!=0) || (X-O!=1 && X-O!=0)) puts("no");
      	else puts("yes");
      }
	return 0;
}
