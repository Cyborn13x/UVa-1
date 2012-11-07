#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11541
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	char a[1000];
	char c;
	scanf("%d",&t);
	for(i=0;i<t;i++)
    {
		scanf("%s",a);
		printf("Case %d: ",i+1);
		for(j=0;a[j]!=0;)
		{
			c=a[j];
			j++;
			n=0;
			while(isdigit(a[j]))
			{
				n=n*10+(a[j]-'0');
				j++;
			}
			for(k=0;k<n;k++) printf("%c",c);
		}
		printf("\n");
	}
	return 0;
}
