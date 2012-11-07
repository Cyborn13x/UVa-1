#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 100000

/*problem id-10523
 *
 *language-ANSI C
 *
 */

char table[16][151][200];
char a[N];
char b[N];
char c[N];
char s[N];

void str_rev(char *p,int l)
{
      int i;
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
	str_rev(p1,LenA);
	str_rev(p2,LenB);
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
	str_rev(p1,LenA);
	str_rev(p2,LenB);
	str_rev(p3,i+1);
	return;
}

void multiply(char *p1,int p2,char *p3)
{
      int i;
      int j;
      int k;
      int l;
      int rem;
      int t;
      int z;
      int temp;
      int LenA=strlen(p1);
      strcpy(b,"0");
      l=0;
      while(p2)
      {
      	rem=0;
      	temp=p2%10;
      	p2/=10;
      	for(j=LenA-1,k=0;j>=0;j--,k++)
      	{
      		a[k]=((p1[j]-'0')*temp+rem)%10+'0';
      		rem=((p1[j]-'0')*temp+rem)/10;
      	}
      	if(rem) a[k++]=rem+'0';
      	a[k]='\0';
      	str_rev(a,k);
      	for(z=0;z<l;z++) a[k++]='0';
      	l++;
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

      for(i=1;i<151;i++) strcpy(table[0][i],"0");
	strcpy(table[1][1],"1");strcpy(table[2][1],"2");strcpy(table[3][1],"3");
	strcpy(table[4][1],"4");strcpy(table[5][1],"5");strcpy(table[6][1],"6");
	strcpy(table[7][1],"7");strcpy(table[8][1],"8");strcpy(table[9][1],"9");
	strcpy(table[10][1],"10");strcpy(table[11][1],"11");strcpy(table[12][1],"12");
	strcpy(table[13][1],"13");strcpy(table[14][1],"14");strcpy(table[15][1],"15");

	for(i=1;i<16;i++) for(j=2;j<151;j++) multiply(table[i][j-1],i,table[i][j]);
	for(i=1;i<16;i++) for(j=2;j<151;j++) multiply(table[i][j],j,table[i][j]);
      for(i=1;i<16;i++) for(j=2;j<151;j++) {add(table[i][j-1],table[i][j],s); strcpy(table[i][j],s);}

	while(scanf("%d %d",&x,&y)!=EOF)
	{
		printf("%s\n",table[y][x]);
	}
	return 0;
}
