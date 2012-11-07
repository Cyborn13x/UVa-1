#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problrm id-10082
 *
 *language-C++
 *
 */

int l;
char k[]="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";

int Position(char c)
{
      for(int i=0;i<l;i++)
      {
      	if(k[i]==c) return i-1;
      }
}

int main()
{

	char c;
	l=strlen(k);
	while(scanf("%c",&c)!=EOF)
	{
		if(c==' ') printf(" ");
		else if(c=='\n') printf("\n");
		else printf("%c",k[Position(c)]);
	}
	return 0;
}
