#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10178
 *
 *language-ANSI C
 *
 */

int parent[150];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

int IsUnion(int A,int B)
{
      return FindParent(A)==FindParent(B);
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}

int main()
{
	int i;
	int m;
	int n;
	int face;
	char a;
	char b;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
	      getchar();
		for(i=0;i<150;i++) parent[i]=i;
		for(i=0,face=1;i<m;i++)
		{
			scanf("%c %c",&a,&b);
			getchar();
			if(!IsUnion(a,b)) MakeUnion(a,b);
			else face++;
		}
		printf("%d\n",face);
	}
	return 0;
}
