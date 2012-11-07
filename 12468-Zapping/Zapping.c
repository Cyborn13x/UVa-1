#include <stdio.h>

int main()
{
	int m,n,x,y;
	while(scanf("%d %d",&m,&n) && m!=-1 && n!=-1)
	{
		if(n>=m) x=(n-m), y=100-(n-m);
		else x=(m-n), y=100-(m-n);
		printf("%d\n",x<y ? x : y);
	}
	return 0;
}
