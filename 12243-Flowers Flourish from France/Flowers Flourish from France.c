#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-12243
 *
 *language-ANSI C
 *
 */

int main()
{
	int flag;
	char c;
	char a[2000];
	char *p;
	while(gets(a) && strcmp(a,"*"))
	{
		p=strtok(a," ");
		flag=1; c=p[0];
		while(p!=NULL && flag)
		{
			if(tolower(c)!=tolower(p[0])) flag=0;
			c=p[0];
			p=strtok(NULL," ");
		}
		printf(flag ? "Y\n" : "N\n");
	}
	return 0;
}
