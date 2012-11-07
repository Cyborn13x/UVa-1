#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-12342
 *
 *language-ANSI C
 *
 *
 */



int main()
{
	int i;
	int j;
	int n;
	int income;
	int rest;
	double tax;
	int t;
	int f;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	      scanf("%d",&income);
		tax=0;
		printf("Case %d: ",i+1);
		if(income<=180000)
		{
		      printf("0\n");
		      continue;
		}
		income-=180000;
		f = income>300000 ? 300000:income;
		tax+=f*0.1;
		income-=f;
		if(!income)
		{
		      f=ceil(tax);
		      if(tax<=2000)
		      {
		            printf("2000\n");
		            continue;
		      }
		      printf("%d\n",f);
		      continue;
		}
		f=income>400000?400000:income;
		tax+=f*0.15;
		income-=f;
		if(!income)
		{
		      f=ceil(tax);
		      printf("%d\n",f);
		      continue;
		}
		f=income>300000?300000:income;
		tax+=f*0.2;
		income-=f;
		if(!income)
		{
		      f=ceil(tax);
		      printf("%d\n",f);
		      continue;
		}
		f=income;
		tax+=f*0.25;
		income-=f;
		if(!income)
		{
		      f=ceil(tax);
		      printf("%d\n",f);
		      continue;
		}
	}
	return 0;
}
