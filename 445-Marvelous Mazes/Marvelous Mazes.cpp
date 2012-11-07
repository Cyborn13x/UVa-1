#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*
 *445
 *
 *
 */
int main()
{
	int i=0,j;
	char c;
	while((c=getchar())!=EOF)
	{
	      if(c>='0' && c<='9')
	      {
	            i+=(c-'0');
	            continue;
	      }
            for(j=0;j<i;j++)
            {
                  if(c=='b') printf(" ");
                  else printf("%c",c);
            }
	      if(c=='!' || c=='\n') printf("\n");
	      i=0;
	}
	return 0;
}
