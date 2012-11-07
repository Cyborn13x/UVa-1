#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11371
 *
 *language-ANSI C
 *
 */

unsigned long long int convert(char *a,int l)
{
      int i;
      unsigned long long res=0;
      for(i=0;i<l;i++) res=(res*10)+(a[i]-'0');
      return res;
}

int cmp(const void *a,const void *b) { return *(char *)a-*(char *)b; }

int cmp1(const void *a,const void *b) { return *(char *)b-*(char *)a; }

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	unsigned long long int x;
	unsigned long long int y;
	char number[30];
	char t;
	while(scanf("%s",number)!=EOF)
	{
	      l=strlen(number);
		qsort(number,l,sizeof(char),&cmp);
		if(number[0]=='0') for(i=1;number[i];i++) if(number[i]!='0') { t=number[i];number[i]='0';number[0]=t;break; }
		x=convert(number,l);
		qsort(number,l,sizeof(char),&cmp1);
		y=convert(number,l);
		printf("%llu - %llu = %llu = 9 * %llu\n",y,x,y-x,(y-x)/9);
	}
	return 0;
}
