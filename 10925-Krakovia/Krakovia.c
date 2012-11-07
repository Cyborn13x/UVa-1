#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10925
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

void divide(char *a,int b,char *c)
{
      int rem=0;
      int i;
      int LenA=strlen(a);
      for(i=0;i<LenA;i++)
      {
      	rem=(10*rem+a[i]-'0');
      	c[i]=(rem/b)+'0';
      	rem%=b;
      }
      c[i]='\0';
      str_rev(c);
      while(c[--i]=='0') c[i]='\0';
      str_rev(c);
      return;
}

int main()
{
	int i;
	int j;
	int f;
	int n;
	char t[100];
	char total[100];
	char c[100];
	char d[100];
	j=0;
	while(scanf("%d %d",&n,&f)==2 && (n || f))
	{
	      if(j) printf("\n");
            strcpy(total,"0");
		for(i=0;i<n;i++)
		{
			scanf("%s",&t);
			add(total,t,c);
			strcpy(total,c);
            }
            divide(total,f,d);
            if(strlen(d)==0) strcpy(d,"0");
            printf("Bill #%d costs %s: each friend should pay %s\n",++j,total,d);
	}
	printf("\n");
	return 0;
}
