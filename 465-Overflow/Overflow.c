#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


/*problem id-465
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j;
	char n1[10000];
	char n2[10000];
	long double x;
	long double y;
	char ch;
	while(scanf("%s %c %s",n1,&ch,n2)==3)
	{
	      printf("%s %c %s\n",n1,ch,n2);
	      x=atof(n1);
	      y=atof(n2);
		if(x>2147483647) printf("first number too big\n");
		if(y>2147483647) printf("second number too big\n");
		if(ch=='+')
		{
		      if(x+y>2147483647) printf("result too big\n");
		}
		else if(ch=='*')
		{
		      if(x*y>2147483647) printf("result too big\n");
		}
	}
	return 0;
}
