#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int i;
	int j;
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==2) printf("00\n01\n81\n");
		else if(n==4) printf("0000\n0001\n2025\n3025\n9801\n");
		else if(n==6) printf("000000\n000001\n088209\n494209\n998001\n");
		else if(n==8) printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
	}
	return 0;
}
