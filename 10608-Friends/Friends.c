#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10608
 *
 *language-ANSI C
 *
 */

int parent[30002];
int size[30002];

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

void MakeUnion(int A,int B)
{
      if(A<=B)
      {
            parent[B]=A;
            size[A]+=size[B];
      }
      else
      {
            parent[A]=B;
            size[B]+=size[A];
      }
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int A;
	int B;
	scanf("%d",&t);
	while(t--)
	{
	      l=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++) {parent[i]=i;size[i]=1;}
		while(m--)
		{
			scanf("%d %d",&x,&y);
			A=FindParent(x);
			B=FindParent(y);
			if(A!=B) MakeUnion(A,B);
		}
		for(i=1;i<=n;i++) if(size[i]>l) l=size[i];
		printf("%d\n",l);
	}
	return 0;
}
