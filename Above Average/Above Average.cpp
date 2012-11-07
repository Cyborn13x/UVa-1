#include<stdio.h>

int main()
{
	int test_case,number_of_students,mark[1000],sum,avarage;
	scanf("%d",&test_case);
	for(int i=1;i<=test_case;i++)
	{
	      sum=0;
		scanf("%d",&number_of_students);
		for(int j=1;j<=number_of_students;j++)
		{
			scanf("%d",&mark[j-1]);
		}
		for(int k=0;k<number_of_students;k++)
		{
			sum+=mark[k];
		}
		avarage=float (sum)/number_of_students;
		sum=0;
		for(int k=0;k<number_of_students;k++)
		{
			if(float (mark[k])>avarage)
			{
			      sum++;
			}
		}
		printf("%.3f%c\n",100*(float (sum)/number_of_students),'%');
	}
	return 0;
}
