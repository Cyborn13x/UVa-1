#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int sumdig(int n)
{
      int s=0;
      while(n)
      {
      	s+=n%10;
      	n/=10;
      }
      return s;
}

int main()
{
	int i;
	int j;
	int n;
	int m;
	int l;
	int s;
	int x;
	int z;
	char a[1005];
	while(1)
	{
	      gets(a);
	      if(!strcmp(a,"0")) break;
		l=strlen(a);
		s=0;
		for(i=0;i<l;i++)
		{
			s+=a[i]-48;
		}
		x=0;
		while(s%9==0)
		{
		      x++;

		      if(s==sumdig(s))
		      {
		            break;
		      }
		      s=sumdig(s);

		}
		if(!x) printf("%s is not a multiple of 9.\n",a);
		else printf("%s is a multiple of 9 and has 9-degree %d.\n",a,x);

	}
	return 0;
}
