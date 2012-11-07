#include<stdio.h>

int main()
{
	int i,testcase;
	while(scanf("%d",&testcase)==1)
	{
		for(i=1;i<=testcase;i++)
		{
			int  amplitude,frequency;
			scanf("%d",&amplitude);
			scanf("%d",&frequency);
			int c1,c2,c3;
			for(c1=1;c1<=frequency;c1++)
			{
				for(c2=1;c2<=amplitude;c2++)
				{
					for(c3=1;c3<=c2;c3++)
					{
						printf("%d",c2);
					}
					printf("\n");
				}
				for(c2=amplitude-1;c2>=1;c2--)
				{
					for(c3=c2;c3>=1;c3--)
					{
						printf("%d",c2);
					}
					printf("\n");
				}

				if(i==testcase && c1== frequency){}
				else
					printf("\n");
			}
		}
	}
	return 0;
}
