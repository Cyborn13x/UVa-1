#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10062
 *
 *language-C++
 *
 */

#define max(a,b) a>b ? a:b
#define min(a,b) a<b ? a:b

int main()
{
	int i;
	int j;
	int n;
	int m;
	int flag=0;
	char s[1001];
	while(gets(s))
	{
	      if(flag) printf("\n");
		n=strlen(s);
		int a[200]={0};
		int MaxFrequency=0;
		int MinFrequency=1000;
		int MaxValue=0;
		for(i=0;i<n;i++)
		{
		      m=(int)s[i];
			a[m]++;
			MaxFrequency=max(MaxFrequency,a[m]);
			MinFrequency=min(MinFrequency,a[m]);
			MaxValue=max(MaxValue,m);
		}
		for(i=MinFrequency;i<=MaxFrequency;i++)
		{
			for(j=MaxValue;j>=32;j--)
			{
				if(a[j]==i) printf("%d %d\n",j,i);
			}
		}
            flag=1;
	}
	return 0;
}
