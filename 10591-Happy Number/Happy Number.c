#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10591
 *
 *language-ANSI C
 *
 *
 */
int sqr(unsigned long long int n)
{
      int s=0;
      int i;
      while(n)
      {
            i=n%10;
      	s+=i*i;
      	n=n/10;
      }
      return s;
}

int main()
{
	int i=0;
	int j;
	unsigned long long int n;
	int m;
	int f;
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
	      scanf("%llu",&n);
	      f=1;
	      if(n==1)
	      {
	            printf("Case #%d: %d is a Happy number.\n",i+1,n);
	            continue;
	      }
	      m=n;
		while(1)
		{
		      m=sqr(m);
			if(m==4)
			{
			      f=0;
			      break;
			}
			else if(m==1)
			{
			      f=1;
			      break;
			}
		}
		if(f) printf("Case #%d: %d is a Happy number.\n",i+1,n);
		else printf("Case #%d: %d is an Unhappy number.\n",i+1,n);
	}
	return 0;
}
