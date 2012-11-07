#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-11879
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j;
	int l;
	int n;
	int rem;
	char a[150];
	while(gets(a) && strcmp(a,"0"))
	{
            rem=0;
            l=strlen(a);
		for(i=0;i<l;i++) rem=(10*rem+a[i]-'0')%17;
		if(rem==0) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
