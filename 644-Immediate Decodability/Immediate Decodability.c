#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 100000

/*problem id-644
 *
 *language-ANSI C
 *
 */

int check(char *a,char *b)
{
      int i,l1=strlen(a),l2=strlen(b);
      For(i,l1) if(a[i]!=b[i]) return 0;
      return 1;
}

int cmp(const void *a,const void *b)
{
      return strlen((char *)a)-strlen((char *)b);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,flag;
	char a[10][12],b[12];
	while(scanf("%s",b)!=EOF)
	{
		if(!strcmp(b,"9"))
		{
		      printf("Set %d is immediately decodable\n",++test);
		      continue;
		}
		x=flag=0;
		strcpy(a[x++],b);
		while(scanf("%s",b) && strcmp(b,"9")) strcpy(a[x++],b);
		qsort(a,x,sizeof(a[0]),&cmp);
		For(i,x)
		{
			for(j=i+1;j<x && !flag;j++)
			{
                        if(check(a[i],a[j])) flag=1;
			}
			if(flag) break;
		}
		if(flag) printf("Set %d is not immediately decodable\n",++test);
		else printf("Set %d is immediately decodable\n",++test);
	}
	return 0;
}
