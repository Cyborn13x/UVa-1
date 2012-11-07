#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ar[10000000];

int main()
{
	int temp,a,b,i,j,common;
	while(1)
	{
		scanf("%d %d",&a,&b);
		if(!a && !b)
		{
		    break;
		}
		for(i=0;i<a;i++)
		{
			scanf("%d",&ar[i]);
		}
		common=0;
		j=0;
		for(i=0;i<b;i++)
		{
			scanf("%d",&temp);
			for(;temp>=ar[j] && j<a;j++)
			{
				if(temp==ar[j])
				{
				    common++;
				    break;
				}
			}
		}
		printf("%d\n",common);
	}
	return 0;
}
