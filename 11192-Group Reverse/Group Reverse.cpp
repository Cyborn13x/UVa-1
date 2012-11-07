#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*Problem ID UVA-11192
 *
 *
 */

void GroupReverse(char *String,int Number)
{
    int j,i,m,StartPoint,EndPoint;
    char Temp;
    j=strlen(String)/Number;
    StartPoint=0;
    EndPoint=j-1;
    for(i=1;i<=Number;i++)
    {
    	for(m=0;m<=(EndPoint-StartPoint)/2;m++)
    	{
    		Temp=String[EndPoint-m];
    		String[EndPoint-m]=String[StartPoint+m];
    		String[StartPoint+m]=Temp;
    	}
    	StartPoint=EndPoint+1;
    	EndPoint+=j;
    }
}
int main()
{
	int Number,len;
	char String[150];
	while(1)
	{
	    scanf("%d",&Number);
	    if(Number==0)
	    {
	        break;
	    }
	    scanf("%s",String);
	    GroupReverse(String,Number);
	    printf("%s\n",String);
	}
	return 0;
}
