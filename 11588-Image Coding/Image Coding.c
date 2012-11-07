#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11588
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int z;
	int k;
	int l;
	int m;
	int n;
	int t;
	int res;
	int max;
	int a[26];
	char s[30];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	      memset(a,0,sizeof(a));
	      scanf("%d %d %d %d",&k,&l,&m,&n);
	      for(j=0;j<k;j++) {scanf("%s",s);for(z=0;s[z];z++) a[s[z]-'A']++;}
	      max=-1;res=0;
	      for(j=0;j<26;j++) max=a[j]>max?a[j]:max;
	      for(j=0;j<26;j++)
	      {
	            if(a[j]==max) res+=a[j]*m;
	            else res+=a[j]*n;
	      }
		printf("Case %d: %d\n",i+1,res);
	}
	return 0;
}
