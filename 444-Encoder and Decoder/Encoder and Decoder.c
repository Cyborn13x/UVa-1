#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-444
 *
 *language-ANSI C
 *
 */

void encode(char *a,int l)
{
    int i;
    int n;
    for(i=l-1;i>=0;i--)
    {
    	n=a[i];
    	while(n)
    	{
    		printf("%d",n%10);
    		n/=10;
    	}

    }
    return;
}

void decode(char *a,int l)
{
    int i;
    int j;
    int m;
    for(i=l-1;i>=0;)
    {
    	if(a[i]<'3')
    	{
    	    m=(a[i]-'0')*100+(a[i-1]-'0')*10+(a[i-2]-'0');
    	    i-=3;
    	}
    	else
    	{
    	    m=(a[i]-'0')*10+(a[i-1]-'0');
    	    i-=2;
    	}
    	printf("%c",m);
    }
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
	char a[1000];
	while(gets(a)!=NULL)
	{
		l=strlen(a);
		if(isdigit(a[0])) decode(a,l);
		else encode(a,l);
		printf("\n");
	}
	return 0;
}
