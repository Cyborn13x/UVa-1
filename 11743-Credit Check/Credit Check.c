#include <stdio.h>
#include <string.h>

/*problem id-11743
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,sum;
	char a[30],tmp[10];
	scanf("%d",&t);
	while(t--)
	{
		for(i=sum=0;i<4;i++)
		{
			scanf("%s",tmp);
			strcat(a,tmp);
		}
		for(i=15;i>=0;i-=2) sum+=(a[i]-'0');
		for(i=14;i>=0;i-=2)
		{
		      x=2*(a[i]-'0');
		      if(x>=10) x=x%10+1;
		      sum+=x;
		}
		if(sum%10) printf("Invalid\n");
		else printf("Valid\n");
		a[0]=0;
	}
	return 0;
}
