#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,j,i,counter;
	float f;
	for(;;)
	{
	      counter=0;
	      scanf("%d %d",&a,&b);
	      if(a==0&&b==0)
	      {
	            break;
	      }
	      for(i=a;i<=b;i++)
	      {
	      	f=sqrt(i);
	      	j=(int)f;
	      	if(j==f)
	      	{
	      	      counter++;
	      	}
	      }
	      printf("%d\n",counter);
	}
	return 0;
}
