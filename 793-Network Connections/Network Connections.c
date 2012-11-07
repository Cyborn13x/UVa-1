#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-793
 *
 *language-ANSI C
 *
 */

int parent[1000002];

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

void MakeUnion(int A,int B) { (A<=B) ? (parent[B]=A) : (parent[A]=B); return; }

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
	int yes;
	int no;
	int blank=0;
	char a[20];
	char ask;
	scanf("%d",&t);
	while(t--)
	{
	      if(blank) printf("\n");
	      blank=1;yes=no=0;
		scanf("%d",&n);
		getchar();
		for(i=1;i<=n;i++) parent[i]=i;
		while(scanf("%c",&ask)==1 && ask!='\n')
		{
			scanf("%d %d",&x,&y);
			A=FindParent(x);
                  B=FindParent(y);
			if(ask=='c') MakeUnion(A,B);
			else if(ask=='q')
			{
			      if(A==B) yes++;
			      else no++;
			}
			getchar();
		}
		printf("%d,%d\n",yes,no);
	}
	return 0;
}
