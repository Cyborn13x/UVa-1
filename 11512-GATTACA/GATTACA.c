#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11512
 *
 *language-ANSI C
 *
 */

int sa[1005];
char s[1005];

int cmp(const void *a,const void *b)
{
      return strcmp(s+*(int *)a,s+*(int *)b);
}

int lenght(char *a,char *b)
{
      int i,l;
      for(i=l=0;a[i] && a[i]==b[i];i++,l++);
      return l;
}

int find(char *a,char *b)
{
      int i;
      for(i=0;a[i];i++) if(a[i]!=b[i]) return 0;
      return 1;
}

int main()
{
	int i,j,k,l,m,n,t,x,y;
	int lcp,rep;
	char a[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		for(i=0,l=strlen(s);i<l;i++) sa[i]=i;
		qsort(sa,l,sizeof(int),&cmp);
		for(i=1,x=0,lcp=0;i<l;i++)
		{
		      x=lenght(s+sa[i-1],s+sa[i]);
		      if(x>lcp) { lcp=x; rep=2; strncpy(a,s+sa[i-1],x); a[x]=0; }
		      else if(x==lcp && find(a,s+sa[i])) rep++;
		}
		if(!lcp) printf("No repetitions found!\n");
		else printf("%s %d\n",a,rep);
	}
	return 0;
}
