#include <stdio.h>

/*problem id-10701
 *
 *language-ANSI C
 *
 */

int idx,pos[200];
char pre[100],in[100];

void post(int x,int y)
{
      int z;
      char c;
      if(x>y) return;
      z=pos[c=pre[idx++]];
      post(x,z-1);
      post(z+1,y);
      printf("%c",c);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank;
	scanf("%d",&t);
	while(t--)
	{
	      idx=0;
		scanf("%d %s %s",&n,pre,in);
		for(i=0;i<n;i++) pos[in[i]]=i;
		post(0,n-1);
		printf("\n");
	}
	return 0;
}
