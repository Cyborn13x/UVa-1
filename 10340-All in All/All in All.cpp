#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int i,j,len,sp,l;
	bool Validity;
	char MainString[100000],SubString[100000];
	while(scanf("%s %s",SubString,MainString)==2)
	{
		len=strlen(MainString), l=strlen(SubString);
		if(l>len) { printf("No\n"); continue; }
		for(i=sp=0,Validity=1;i<l && Validity;i++)
		{
			for(j=sp;j<len;j++)
			{
				if(SubString[i]==MainString[j])
				{
				    sp=j+1;
				    Validity=1;
				    break;
				}
			}
			if(j==len) Validity=0;
		}
		if(Validity) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
