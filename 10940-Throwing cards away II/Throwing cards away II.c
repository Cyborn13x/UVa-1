#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10940
 *
 *language-ANSI C
 *
 */

int main()
{
	int n;
	int x;
	int TwoPower[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
	while(scanf("%d",&n) && n)
	{
            x=19;
		while(TwoPower[x]>n) x--;
		if(n==TwoPower[x]) printf("%d\n",TwoPower[x]);
		else printf("%d\n",(n-TwoPower[x])*2);
	}
	return 0;
}
