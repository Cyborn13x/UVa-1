#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-11777
 *
 *
 *language-ANSI C
 *
 */
void BubbleSort(int *ptr,int NumberOfElement)
{
      int i,j,temp;
      for(i=0;i<NumberOfElement;i++)
	{
		for(j=0;j<(NumberOfElement-i-1);j++)
		{
			if(ptr[j]>ptr[j+1])
			{
			      temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
			}
		}
	}
	return;
}

int main()
{
	int i;
	int a;
	int b;
	int c;
	int d;
	int q[3];
	int sum;
	int t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&q[0],&q[1],&q[2]);
		BubbleSort(q,3);
		sum=a+b+c+d+(q[2]+q[1])/2;
		printf("Case %d: ",i+1);
		if(sum>=90) printf("A");
		else if(sum>=80 && sum<90) printf("B");
		else if(sum>=70 && sum<80) printf("C");
		else if(sum>=60 && sum<70) printf("D");
		else if(sum<60) printf("F");
		printf("\n");
	}
	return 0;
}
