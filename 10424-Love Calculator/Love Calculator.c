#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


/*problem id-10424
 *
 *language-ANSI C

 *
 *
 */

int sum(int n)
{
      int s=0;
      while(n)
      {
      	s+=n%10;
      	n/=10;
      }
      return s;
}

int main()
{
	int i;
	int j;
	int a;
	int b;
	int s1;
	int s2;
	int l1;
	int l2;
	char n1[30];
	char n2[30];
	double ans;
	while(gets(n1) && gets(n2))
	{
		s1=s2=0;
		l1=strlen(n1);
		l2=strlen(n2);
		for(i=0;i<l1;i++) if(isalpha(n1[i])) s1+=tolower(n1[i])-'a'+1;
		for(i=0;i<l2;i++) if(isalpha(n2[i])) s2+=tolower(n2[i])-'a'+1;
		while(s1>9) s1=sum(s1);
		while(s2>9) s2=sum(s2);
		if(s1<=s2) ans=(s1*1.0/s2)*100;
		else if(s1>s2) ans=(s2*1.0/s1)*100;
		else if(!s1 && !s2) ans=100.00;
		printf("%.2lf %%\n",ans);
	}
	return 0;
}
