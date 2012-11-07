#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

/*problem id-10222
 *
 *language-ANSI C
 *
 *
 */

int main()
{
      const char a[]="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	int i;
	int j;
	int n;
	char c;
	while((c=getchar())!=EOF)
	{
		if(c==' ' || c=='\n')
		{
		      putchar(c);
		      continue;
		}
		c=tolower(c);
		for(i=0;c!=a[i];i++);
		putchar(a[i-2]);
	}
	return 0;
}
