#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-748
 *
 *language-ANSI C
 *
 */

#define N 10000

char a[N];
char b[N];
char c[N];

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

void multiply(char *p1,char *p2,char *p3)
{
      int i;
      int j;
      int k;
      int l;
      int rem;
      int t;
      int z;
      int LenA=strlen(p1);
      int LenB=strlen(p2);
      strcpy(b,"0");
      for(i=LenB-1,l=0;i>=0;i--,l++)
      {
      	rem=0;
      	for(j=LenA-1,k=0;j>=0;j--,k++)
      	{
      		a[k]=((p1[j]-'0')*(p2[i]-'0')+rem)%10+'0';
      		rem=((p1[j]-'0')*(p2[i]-'0')+rem)/10;
      	}
      	if(rem) a[k++]=rem+'0';
      	a[k]='\0';
      	str_rev(a);
      	for(z=0;z<l;z++) a[k++]='0';
      	a[k]='\0';
      	add(a,b,c);
      	strcpy(b,c);
      }
      strcpy(p3,b);
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
	int x;
	int y;
	int power;
	int point;
    char s[10000];
    char tmp[20];
    char ans[10000];
    while(scanf("%s %d",s,&power)!=EOF)
    {
        l=strlen(s);
    	j=l;
    	while(s[--j]=='0') s[j]=0;
    	l=strlen(s);
    	i=l;
    	while(s[--i]!='.');
    	for(j=i;j<l;j++) s[j]=s[j+1];
    	str_rev(s);j=l-1;
    	while(s[--j]=='0') s[j]=0;
    	str_rev(s);
    	x=l-i-1;
    	strcpy(tmp,s);
    	for(i=0;i<power-1;i++)
    	{
    		multiply(s,tmp,ans);
    		strcpy(s,ans);
    	}
    	l=strlen(s);j=l;
    	while(s[--j]=='0') {s[j]=0;l--;}
    	x*=power;
        x=l-x;
        k=x;
        if(x<0) {k=0;}
        for(i=0;i<k;i++) printf("%c",s[i]);
        printf(".");
        if(x<0) for(j=0;j<-x;j++) printf("0");
        for(i=k;s[i];i++) printf("%c",s[i]);
        printf("\n");
    }
	return 0;
}
