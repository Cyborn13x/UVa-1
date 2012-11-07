#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10931
 *
 *language-C++
 *
 */

char a[100000000];

void str_rev()
{
      int i;
      int l=strlen(a);
      char temp;
      for(i=0;i<=(l-1)/2;i++)
      {
            temp=a[i];
            a[i]=a[l-1-i];
            a[l-1-i]=temp;
      }
      return;
}

void Binary(int n)
{
      int i=0;
      while(n)
      {
      	a[i]=48+(n%2);
      	i++;
      	n/=2;
      }
      a[i]='\0';
      str_rev();
      return;
}

int NumberOfOnes()
{
      int l=strlen(a);
      int i;
      int n=0;
      for(i=0;i<l;i++)
      {
      	if(a[i]=='1') n++;
      }
      return n;
}
int main()
{
	int i;
	int j;
	int n;
	while(scanf("%d",&n)==1)
	{
		if(!n) break;
		Binary(n);
		printf("The parity of %s is %d (mod 2).\n",a,NumberOfOnes());

	}
	return 0;
}
