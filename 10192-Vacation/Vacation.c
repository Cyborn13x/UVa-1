#include <stdio.h>
#include <string.h>

/*problem di-10192
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l1,l2,m,n,t,x,y,blank=0,test=0,lcs[102][102];
	char a[110],b[110];
	while(gets(a) && a[0]!='#')
	{
		gets(b);
		for(i=0;i<102;i++) lcs[i][0]=lcs[0][i]=0;
		l1=strlen(a), l2=strlen(b);
		for(i=1;i<=l1;i++)
		{
			for(j=1;j<=l2;j++)
			{
				if(a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
				else lcs[i][j] = lcs[i-1][j]>lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n",++test,lcs[l1][l2]);
	}
	return 0;
}
