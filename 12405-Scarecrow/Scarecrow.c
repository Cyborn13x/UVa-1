#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[200];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&n,a);
		for(i=x=0,l=strlen(a);i<l;)
		{
			if(a[i]=='.') x++, i+=3;
			else i++;
		}
		printf("Case %d: %d\n",++test,x);
	}
	return 0;
}
