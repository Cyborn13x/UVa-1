#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-401
 *
 *language-ANSI C
 *
 */

int dat[200];

int IsPalin(char *a,int l)
{
      int i;
      for(i=0;i<l/2;i++) if(a[i]!=a[l-i-1]) return 0;
      return 1;
}

int IsMirror(char *a,int l)
{
      int i;
      int j=l/2;
      if(l&1) j++;
      for(i=0;i<j;i++) if(dat[a[i]]!=a[l-i-1]) return 0;
      return 1;
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
	int p;
	char a[100];
	dat['A']='A';
	dat['E']='3';
	dat['3']='E';
	dat['H']='H';
	dat['I']='I';
	dat['J']='L';
	dat['L']='J';
	dat['M']='M';
	dat['O']='O';
	dat['S']='2';
	dat['2']='S';
	dat['T']='T';
	dat['U']='U';
	dat['V']='V';
	dat['W']='W';
	dat['X']='X';
	dat['Y']='Y';
	dat['Z']='5';
	dat['5']='Z';
	dat['1']='1';
	dat['8']='8';
	while(scanf("%s",a)!=EOF)
	{
        l=strlen(a);
		p=IsPalin(a,l);
		m=IsMirror(a,l);
		printf("%s -- is ",a);
		if(p && m) printf("a mirrored palindrome.");
		else if(p && !m) printf("a regular palindrome.");
		else if(!p && m) printf("a mirrored string.");
		else printf("not a palindrome.");
		printf("\n\n");
	}
	return 0;
}
