#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-640
 *
 *language-ANSI C
 *
 */

int a[1000100];

int digit(int n)
{
      int c=0;
      while(n) {c+=n%10;n/=10;}
      return c;
}

int main()
{
	int i;
	for(i=1;i<=1000000;i++) a[i+digit(i)]=1;
	for(i=1;i<=1000000;i++) if(!a[i]) printf("%d\n",i);
	return 0;
}
