#include <stdio.h>

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[500];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n); l=0;
		printf("Case #%d: ",++test);
		if(!n) { printf("0\n"); continue; }
		while(n)
		{
			x=n%(-2);
			n/=-2;
			if(x<0) { n++; x+=2; }
			a[l++]=x+'0';
		}
		for(i=l-1;i>=0;i--) putchar(a[i]);
		putchar('\n');
	}
	return 0;
}
