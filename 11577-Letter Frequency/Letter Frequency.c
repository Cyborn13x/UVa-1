#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11577
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j;
	int n;
	int l;
	int max;
	int ar[30];
	char s[200];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
	      memset(ar,0,sizeof(int)*30);
		gets(s);
		l=strlen(s);
		max=0;
		for(i=0;i<l;i++) if(isalpha(s[i])) ar[tolower(s[i])-'a']++;
		for(i=0;i<26;i++) if(ar[i]>max) max=ar[i];
		for(i=0;i<26;i++) if(ar[i]==max) printf("%c",i+'a');
		printf("\n");
	}
	return 0;
}
