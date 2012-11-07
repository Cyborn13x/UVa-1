#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 1000000

/*problem id-10013
 *
 *language-ANSI C
 *
 *
 */


char a[N];
char b[N];
char c[N+3];

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
	str_rev(p3);
	return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int n;
	int t;
	int x=1;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
	      if(!x) printf("\n");
	      x=0;
		scanf("%d",&n);
		getchar();
		j=0;
		k=0;
		for(l=0;l<n;l++)
		{
			scanf("%c %c",&a[l],&b[l]);
			getchar();
		}
		a[l]='\0';
		b[l]='\0';
            add(a,b,c);
		printf("%s\n",c);
	}
	return 0;
}
