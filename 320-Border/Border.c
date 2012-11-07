#include <stdio.h>

/*problem id-320
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,tx,ty,blank=0,test=0;
	char grid[32][32],a[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %s",&ty,&tx,a);
		for(i=0;i<32;i++) for(j=0;j<32;j++) grid[i][j]='.';
		for(i=0;a[i]!='.';i++)
		{
			if(a[i]=='E') grid[tx-1][ty]='X', ty++;
			else if(a[i]=='W') grid[tx][ty-1]='X', ty--;
			else if(a[i]=='N') grid[tx][ty]='X', tx++;
			else grid[tx-1][ty-1]='X', tx--;
		}printf("Bitmap #%d\n",++test);
		for(i=31;i>=0;i--)
		{
			for(j=0;j<32;j++) putchar(grid[i][j]);
                  printf("\n");
		}printf("\n");
	}
	return 0;
}
