#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10193
 *
 *language-ANSI C
 *
 */

int BinToDec(char *a)
{
    int l=strlen(a);
    int i;
    int sum=0;
    for(i=l-1;i>=0;i--) if(a[i]!='0') sum+=pow(2,l-i-1);
    return sum;
}

int GCD(int a,int b)
{
    int c=10;
    while(c)
    {
    	c=a%b;
    	a=b;
    	b=c;
    }
    return a;
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
	char a[50];
	char b[50];
	scanf("%d\n",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s %s",a,b);
		m=BinToDec(a);
		n=BinToDec(b);
		k=GCD(m,n);
		printf("Pair #%d: ",i+1);
		if(k>1) printf("All you need is love!\n");
		else printf("Love is not all you need!\n");
	}
	return 0;
}
