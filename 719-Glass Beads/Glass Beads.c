#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,ans;
	char b[10005],a[20010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",b);
		l=strlen(b);
		strcpy(a,b); strcat(a,b);
		i=0, j=1, k=0;
		while(i<l && j<l)
		{
			if(a[i+k]==a[j+k])
			{
			      k++;
			      if(k==l) break;
			}
			else if(a[i+k]<a[j+k])
			{
			      j=j+k+1, k=0;
			      if(j<=i) j=i+1;
			}
			else if(a[j+k]<a[i+k])
			{
			      i=i+k+1, k=0;
			      if(i<=j) i=j+1;
			}
		}
		ans = i<j ? i : j;
		printf("%d\n",ans+1);
	}
	return 0;
}
