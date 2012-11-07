#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


/*problem id-492
 *
 *language-C++
 *
 */
bool IsVowel(char c)
{
      if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
      return false;
}

int main()
{
	int i;
	int j;
	char c;
	char temp;
	while((c=getchar())!=EOF)
	{
		if(isalpha(c))
		{
                  if(IsVowel(c))
                  {
                        while(isalpha(c))
                        {
                        	printf("%c",c);
                        	c=getchar();
                        }
                        printf("ay");
                  }
                  else
                  {
                        temp=c;
                        c=getchar();
                        while(isalpha(c))
                        {
                        	printf("%c",c);
                        	c=getchar();
                        }
                        printf("%cay",temp);
                  }
		}
		printf("%c",c);
	}
	return 0;
}
