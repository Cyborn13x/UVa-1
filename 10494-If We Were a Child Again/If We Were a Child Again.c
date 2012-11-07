#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10494
 *
 *language-ANSI C
 *
 *
 */


char a[1000];
char b[1000];
int m;

void str_rev(char *p)
{
      int i;
      int l=strlen(p);
      char t;
      for(i=0;i<l/2;i++)
      {
            t=p[i];
            p[i]=p[l-i-1];
            p[l-i-1]=t;
      }
      return;
}

void divide(char *a,unsigned long long int n)
{
      unsigned long long int rem=0;
      int i;
      for(i=0;i<m;i++)
      {
      	rem=(10*rem+a[i]-'0');
      	b[i]=(rem/n)+'0';
      	rem%=n;
      }
      b[i]='\0';
      str_rev(b);
      while(b[--i]=='0') b[i]='\0';
      str_rev(b);
      return;
}

int main()
{
	int i;
	int j;
	unsigned long long int n;
	int rem;
	char c;
	while(scanf("%s %c %llu",a,&c,&n)!=EOF)
	{
	      m=strlen(a);
		if(c=='/')
		{
		      divide(a,n);
		      if(!strlen(b)) b[0]='0';
		      printf("%s\n",b);
		}
		else if(c=='%')
		{
		      rem=0;
                  for(i=0;i<m;i++) rem=(10*rem+a[i]-'0')%n;
                  printf("%d\n",rem);
		}
	}
	return 0;
}
