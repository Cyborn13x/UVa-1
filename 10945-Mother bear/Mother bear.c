#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

/*problem id-10945
 *
 *language-ANSI C
 *
 *
 */
char b[10000000];
int l;

int ispalin()
{
      int i;
      l=strlen(b);
      for(i=0;i<=(l/2)-1;i++)
      {
      	if(b[i]!=b[l-i-1]) return 0;
      }
      return 1;
}
int main()
{
	int i;
	int j;
	char c;
	while(1)
	{
	      i=0;
	      while((c=getchar())!='\n')
	      {
	            if(isalpha(c))
	      	{
	      	      b[i++]=c;
	      	}
	      }
	      b[i]='\0';
	      if(strcmp(b,"DONE")==0) break;
		l=strlen(b);
		for(i=0;i<l;i++)
		{
			b[i]=tolower(b[i]);
		}
		if(ispalin()) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}
	return 0;
}
