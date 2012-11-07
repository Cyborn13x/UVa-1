#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 100000
#define R 1001

/*problem id-10220
 *
 *language-ANSI C
 *
 *
 */


char f[R][N];
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
	int n;
	int l;
	int ans;
	char b[10]="10";
	char c[10];
	strcpy(f[0],"1");
	strcpy(f[1],"1");
	strcpy(f[2],"2");
	strcpy(f[3],"6");
	strcpy(f[4],"24");
	strcpy(f[5],"120");
	strcpy(f[6],"720");
	strcpy(f[7],"5040");
	strcpy(f[8],"40320");
	strcpy(f[9],"362880");
	for(i=10;i<R;i++)
	{
		multiply(f[i-1],b,f[i]);
		strcpy(c,b);
		add(c,f[0],b);
	}
	while(scanf("%d",&n)==1)
	{
	      ans=0;
		l=strlen(f[n]);
            for(i=0;i<l;i++)
            {
                  ans+=f[n][i]-'0';
            }
            printf("%d\n",ans);
	}
	return 0;
}
