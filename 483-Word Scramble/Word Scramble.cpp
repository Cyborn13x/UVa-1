#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-483
 *
 *language-C++
 *
 */

int main()
{
      char a[1000];
      char c;
      int l;
	int i;
	int j;
	while(scanf("%s",a)!=EOF)
	{
	      c=getchar();
		for(i=strlen(a)-1;i>=0;i--)
		{
			printf("%c",a[i]);
		}
		printf("%c",c);
	}
	return 0;
}
