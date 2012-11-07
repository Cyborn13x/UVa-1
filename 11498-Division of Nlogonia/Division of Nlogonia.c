#include <stdio.h>

/*problem id-11498
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0;
	while(scanf("%d",&k)!=EOF)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<k;i++)
		{
			scanf("%d %d",&x,&y);
			if(!(x-n) || !(y-m)) printf("divisa\n");
			else if(x<n && y>m) printf("NO\n");
			else if(x>n && y>m) printf("NE\n");
			else if(x<n && y<m) printf("SO\n");
			else printf("SE\n");
		}
	}
	return 0;
}
