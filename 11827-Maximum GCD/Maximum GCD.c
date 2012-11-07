#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX(a,b) ((a>b)?a:b)

/*problem id-11827
 *
 *language-ANSI C
 *
 */

int GCD(int a,int b)
{
      int t;
      int c=1;
      if(b>a) {t=b;b=a;a=t;}
      while(c)
      {
      	c=a%b;
      	a=b;b=c;
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
	int x[105];
	int y;
	char a[10000];
	char *ptr;
	scanf("%d",&n,&m);
	getchar();
	while(n--)
	{
		gets(a);i=0;m=0;
		ptr=strtok(a," ");
		while(ptr!=NULL)
		{
			x[i++]=atoi(ptr);
                  ptr=strtok(NULL," ");
		}
		y=i;
		for(i=0;i<y;i++) for(j=i+1;j<y;j++) m=MAX(m,GCD(x[i],x[j]));
            printf("%d\n",m);
	}
	return 0;
}
