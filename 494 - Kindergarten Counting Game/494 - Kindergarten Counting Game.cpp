#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int IfAlpha(char *ch);

int main()
{
	int WordNumber,len,i;
	char s[1000];
	while(gets(s))
	{
	    WordNumber=0;
	    len=strlen(s);
	    if((s[0]>=65 && s[0]<=90)||(s[0]>=97 && s[0]<=122)) WordNumber++;
	    for(i=0;i<len-1;i++)
	    {
	    	if(IfAlpha(&s[i]))
	    	{
	    	    WordNumber++;
	    	}
	    }
	    printf("%d\n",WordNumber);
	}
	return 0;
}

int IfAlpha(char *ch)
{
    char *p=ch+1;
    bool a,b;
    a=(*ch>=65 && *ch<=90)||(*ch>=97 && *ch<=122);
    b=(*p>=65 && *p<=90)||(*p>=97 && *p<=122);
    if(!a && b)
    {
        return 1;
    }
    return 0;
}
