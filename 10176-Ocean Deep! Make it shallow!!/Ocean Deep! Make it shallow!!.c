#include <stdio.h>

#define MOD 131071

int main()
{
	int i,j,k,l,m,n,t,x=0,y,blank,test=0;
	char c;
	while((c=getchar())!=EOF)
	{
		if(c=='#')
		{
		      printf("%s\n",x ? "NO" : "YES");
		      x=0;
		}
		else if(c!='\n') x = (x*2+c-'0')%MOD;
	}
	return 0;
}
