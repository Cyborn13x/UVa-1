#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*
 *problem id-272
 *
 *language-C++
 */

int main()
{
	int i=0;
	char ch;
	while(scanf("%c",&ch)==1)
	{
	      if(ch=='"')
            {
                  i++;
                  if(i==1)
                  {
                        printf("``");
                  }
                  else if(i%2==0)
                  {
                        printf("''");
                        i=0;
                  }
            }
            else
            {
                  printf("%c",ch);
            }
	}
	return 0;
}
