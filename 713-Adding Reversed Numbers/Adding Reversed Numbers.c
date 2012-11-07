#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-713
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

void add(char *p1,char *p2,char *p3)
{
      int i;
      int j;
      int LenA;
      int LenB;
      int c;
      int rem=0;
      LenA=strlen(p1);
	LenB=strlen(p2);
      c = LenA>=LenB ? LenA : LenB;
	str_rev(p1);
	str_rev(p2);
	for(i=0;i<c;i++)
	{
	      if(i>=LenA) p1[i]='0';
	      else if(i>=LenB) p2[i]='0';
	      p3[i]=(p1[i]-'0'+p2[i]-'0'+rem)%10+'0';
	      rem=(p1[i]-'0'+p2[i]-'0'+rem)/10;
	}
	if(rem) p3[i++]=rem+'0';
	p3[i]='\0';
	while(p3[--i]=='0') p3[i]='\0';
	p1[LenA]='\0';
	p2[LenB]='\0';
	str_rev(p1);
	str_rev(p2);
	str_rev(p3);
	return;
}

void shape(char *c)
{
      int l=strlen(c);
      while(c[--l]=='0') c[l]='\0';
      return;
}

int main()
{
	int i;
	int j;
	int t;
	char a[10000];
	char b[10000];
	char c[10000];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
		scanf("%s %s",a,b);
		str_rev(a);
		str_rev(b);
		add(a,b,c);
		shape(c);
		str_rev(c);
		printf("%s\n",c);

	}
	return 0;
}
