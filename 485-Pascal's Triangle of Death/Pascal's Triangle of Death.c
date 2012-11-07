#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-485
 *
 *language-ANSI C
 *
 */

char PascelTriangle[1000][1000][75];

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

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int flag;
	for(i=0;i<205;i++)
	{
		strcpy(PascelTriangle[i][0],"1");
		for(j=1;j<i;j++)
		{
			add(PascelTriangle[i-1][j],PascelTriangle[i-1][j-1],PascelTriangle[i][j]);
		}
		strcpy(PascelTriangle[i][i],"1");
	}
	flag=1;
	printf("1\n1 1\n");
    for(i=2;i<205;i++)
    {
        for(j=0;j<=i-1;j++)
        {
            printf("%s ",PascelTriangle[i][j]);
            if(strlen(PascelTriangle[i][j])>=61) flag=0;
        }
        printf("1\n");
        if(!flag) break;
    }
	return 0;
}
