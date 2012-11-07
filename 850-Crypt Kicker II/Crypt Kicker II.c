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
#define SZ 1002

/*problem id-850
 *
 *language-ANSI C
 *
 */

int data[30];
char key[]="the quick brown fox jumps over the lazy dog";

int Check(char *a,int len)
{
      int i;
      if(strlen(a)!=len) return 0;
      SET(data);
      for(i=0;i<len;i++)
      {
      	if(a[i]==' ' && key[i]!=' ') return 0;
      	if(key[i]==' ' && a[i]!=' ') return 0;
      	else if(a[i]==' ') continue;
      	if(data[a[i]-'a']!=-1 && data[a[i]-'a']!=key[i]-'a') return 0;
      	data[a[i]-'a']=key[i]-'a';
      }
      return 1;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,match,blank=0,test=0,keylen=strlen(key),len;
	char a[SZ][100];
      scanf("%d%*c",&t);
      gets(a[0]);
      while(t--)
      {
            if(blank) printf("\n");
            blank=1, x=0, match=0;
            while(gets(a[x])!=NULL && a[x][0])
            {
                  if(!match && Check(a[x],keylen)) match=1;
                  x++;
            }
            if(!match) { printf("No solution.\n"); continue; }
            FOR(i,x)
            {
            	for(j=0;a[i][j];j++)
            	{
            	      if(isalpha(a[i][j])) putchar(data[a[i][j]-'a']+'a');
            	      else putchar(a[i][j]);
            	}
            	printf("\n");
            }
      }
	return 0;
}
