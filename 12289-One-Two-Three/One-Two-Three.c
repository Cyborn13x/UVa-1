#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-12289
 *
 *language-ANSI C
 *
 *
 */



int main()
{
	int i;
	int j;
	int a[26];
	char s[6];
	int t;
	int n;
	int l;
	int m1;
	int m2;
	char one[]="one";
	char two[]="two";
      scanf("%d",&t);
      getchar();
      for(i=0;i<t;i++)
      {
      	gets(s);
      	m1=0;
      	m2=0;
      	for(j=0;j<26;j++) a[j]=0;
      	l=strlen(s);
      	if(l==5) printf("3\n");
      	else
      	{
      	      for(j=0;j<3;j++)
      	      {
      	      	if(s[j]==one[j]) m1++;
      	      	if(s[j]==two[j]) m2++;
      	      }
      	      if(m1>m2) printf("1\n");
      	      else printf("2\n");
      	}
      }
	return 0;
}
