#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-541
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int n;
	int s1;
	int s2;
	int odr;
	int odc;
	int x;
	int y;
	int b[100][100];
	while(scanf("%d",&n)==1 && n)
	{
	      odr=odc=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			s1=s2=0;
			for(j=0;j<n;j++)
			{
				s1+=b[i][j];
				s2+=b[j][i];
			}
			if(s1%2)
			{
			      odr++;
			      x=i+1;
			}
			if(s2%2)
			{
			      odc++;
			      y=i+1;
			}
		}
		if(!odr && !odc) printf("OK\n");
		else if(odr>1 || odc>1) printf("Corrupt\n");
		else printf("Change bit (%d,%d)\n",x,y);
	}
	return 0;
}
