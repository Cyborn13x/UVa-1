#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int i,j,n,len,ans;
	char SkewBinaryNumber[40];
	while(1)
	{
	    gets(SkewBinaryNumber);
	    if(SkewBinaryNumber[0]=='0' && SkewBinaryNumber[1]=='\0')
	    {
	        break;
	    }
	    len=strlen(SkewBinaryNumber);
	    n=2;
	    ans=0;
	    for(i=len-1;i>=0;i--)
	    {
	    	ans=ans+(SkewBinaryNumber[i]-48)*(n-1);
	    	n*=2;
	    }
	    printf("%lu\n",ans);
	}
	return 0;
}
