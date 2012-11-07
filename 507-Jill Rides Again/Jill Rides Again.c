#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-507
 *
 *language-ANSI C
 *
 */

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
	int  ansx,ansy,max,test=0,a[20005],s[20005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n-1;i++) scanf("%d",&a[i]);
		for(i=1,s[0]=a[0];i<n-1;i++) s[i]=a[i]+s[i-1];
		for(i=j=0,max=0;i<n-1;i++)
		{
			if(s[i]-s[j]+a[j]>max) ansx=j, ansy=i, max=s[i]-s[j]+a[j];
			else if(s[i]-s[j]+a[j]==max && i-j>ansy-ansx) ansy=i, ansx=j;
			else if(s[i]-s[j]+a[j]<0) j=i+1;
		}
		if(max) printf("The nicest part of route %d is between stops %d and %d\n",++test,ansx+1,ansy+2);
		else printf("Route %d has no nice parts\n",++test);
	}
	return 0;
}
