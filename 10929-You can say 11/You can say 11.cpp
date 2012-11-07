#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int len,Right,Left,i,j,Difference;
	char Number[150];
	while(1)
	{
		scanf("%s",Number);
		if(Number[0]=='0' && Number[1]=='\0')
		{
		    break;
		}
		Left=0;
		Right=0;
		len=strlen(Number);
		for(i=0;i<len;i+=2)
		{
			Left+=Number[i]-48;
		}
		for(i=1;i<len;i+=2)
		{
			Right+=Number[i]-48;
		}
		Difference=Right-Left;
		if(Difference%11==0)
		{
		    printf("%s is a multiple of 11.\n",Number);
		}
		else
		{
		    printf("%s is not a multiple of 11.\n",Number);
		}
	}
	exit(0);
}
