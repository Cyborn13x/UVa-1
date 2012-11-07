#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-490
 *
 *language-C++
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int ml;
	int l[100];
	char a[100][105];
	i=0;
	ml=0;
	while(gets(a[i]))
	{
	      l[i]=strlen(a[i]);
	      if(l[i]>ml) ml=l[i];
		i++;
	}
	for(k=0;k<ml;k++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(k<l[j]) printf("%c",a[j][k]);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
