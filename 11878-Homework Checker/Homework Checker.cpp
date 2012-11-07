#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-11878
 *
 *language-ANSI C
 *
 */
int main()
{
	int i;
	int j;
	int n;
	char s;
	int m;
	int r=0;
	char a[10];
	while(scanf("%d%c%d%*c%s",&i,&s,&j,a)!=EOF)
	{
	      m=atoi(a);
		if(a[0]=='?')
		{
		      continue;
		}
		else
		{
		      if(s=='+' && m==i+j)
		      {
		            r++;
		      }
		      else if(s=='-' && m==i-j)
		      {
		            r++;
		      }
		}
	}
      printf("%d\n",r);
	return 0;
}
