#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10035
 *
 *language-ANSI C
 *
 */
int main()
{
	int i;
	int j;
	int n;
	unsigned long int a;
	unsigned long int b;
	int c;
	int s;
	while(scanf("%lu %lu",&a,&b)==2 && (a || b))
	{
		c=0;
		s=0;
		while(a || b)
		{
			if((a%10+b%10+s)/10)
			{
			      c++;
			}
			s=(a%10+b%10+s)/10;;
			a/=10;
			b/=10;
		}
		if(!c) printf("No carry operation.\n");
		else
		{
		      if(c>1) printf("%d carry operations.\n",c);
		      else printf("1 carry operation.\n",c);
		}
	}
	return 0;
}
