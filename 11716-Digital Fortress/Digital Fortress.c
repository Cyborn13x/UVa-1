#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11716
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
	double s;
	int t;
	char a[100][100];
	char b[10005];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(b);
		l=strlen(b);
		s=sqrt(l);
		n=s;
		if(n*100000!=s*100000)
		{
		    printf("INVALID\n");
		    continue;
		}
		k=0;
		for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=b[k++];
		for(i=0;i<n;i++) for(j=0;j<n;j++) printf("%c",a[j][i]);
		printf("\n");
	}
	return 0;
}
