#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11960
 *
 *language-ANSI C
 *
 */

#define N 1000010

int maxi[N];
int n[N];
int a[N];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	n[1]=1;
	for(i=2;i<500005;i++) for(j=i;j<N;j+=i) a[j]++;
	for(i=2;i<N;i++)
	{
        if(a[i]>=maxi[i-1])
		{
		    l=i;
		    maxi[i] = a[i];
		    n[i] = i;
		}
		else
		{
		    maxi[i] = maxi[i-1];
		    n[i]=l;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		printf("%d\n",n[m]);
	}
	return 0;
}
