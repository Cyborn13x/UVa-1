#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-11830
 *
 *language-ANSI C
 *
 *
 */


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


int main()
{
	int i;
	int j;
	int n;
	int l;
	int m;
	int k;
	char a[200];
	char b[200];
	char d;
	char t;

	while(scanf("%c %s",&d,&a)==2 && (d!='0' && strcmp(a,"0")))
	{
	      getchar();
		l=strlen(a);
		j=0;
		b[j]=b[j+1]='\0';
		for(i=0;i<=l;i++)
		{
			if(a[i]!=d) b[j++]=a[i];
		}
		str_rev(b);
		for(i=j;i>=0;i--) if(b[i]=='0') b[i]='\0';
		if(b[0]=='\0') b[0]='0';
		str_rev(b);
		printf("%s\n",b);

	}
	return 0;
}
