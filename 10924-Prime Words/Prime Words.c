#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int p[1050];

int main()
{
	int i;
	int j;
	int n;
	int l;
	char a[25];
	for(i=2;i<=525;i++)
	{
		for(j=2*i;j<1050;j+=i)
		{
			p[j]=1;
		}
	}
	while(scanf("%s",a)!=EOF)
	{
		n=0;
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]>=97 && a[i]<=122) n+=a[i]-96;
			else n+=a[i]-38;
		}
		if(!p[n]) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
	return 0;
}
