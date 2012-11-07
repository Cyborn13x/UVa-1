#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11713
 *
 *language-ANSI C
 *
 */

int IsVowel(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return 1;
    return 0;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	char a[25];
	char b[25];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(a);
		gets(b);
		k=strlen(a);
		l=strlen(b);
		if(k!=l)
		{
		    printf("No\n");
		    continue;
		}
		n=1;
		for(i=0;i<k;i++)
		{
			if(a[i]!=b[i] && (!IsVowel(a[i]) || !IsVowel(b[i])))
			{
			    n=0;
			    break;
			}
		}
		if(!n) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
