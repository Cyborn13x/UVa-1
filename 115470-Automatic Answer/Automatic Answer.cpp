#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
	int TestCase,i,Ans;
	long int Number;
	scanf("%d",&TestCase);
	for(i=1;i<=TestCase;i++)
	{
		scanf("%ld",&Number);
		Number*=567;
		Number/=9;
		Number+=7492;
		Number*=235;
		Number/=47;
		Number-=498;
		Number/=10;
		if((Number%10)<0)Ans=-(Number%10);
		else Ans=Number%10;
		printf("%d\n",Ans);
	}
	return 0;
}
