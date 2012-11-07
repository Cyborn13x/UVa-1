#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-599
 *
 *language-ANSI C
 *
 */

int parent[30];

int FindParent(int n) { return parent[n]==n ? n: (parent[n]=FindParent(parent[n])); }

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
	int tree;
	int acron;
	int value[30];
	char n1;
	char n2;
	char c;
	char a[1000];
	scanf("%d",&t);
	while(t--)
	{

	      memset(value,0,sizeof(value));
	      for(i=1;i<27;i++) parent[i]=i;

		while(scanf("%s",a) && a[0]!='*')
		{
			sscanf(a,"(%c,%c)",&n1,&n2);
			A=FindParent(n1-'A'+1);
			B=FindParent(n2-'A'+1);
			if(A!=B) MakeUnion(A,B);
		}
		scanf("%s",a);
		for(i=0;a[i];i++) if(a[i]!=',') value[FindParent(a[i]-'A'+1)]++;
		tree=acron=0;
		for(i=1;i<27;i++)
		{
			if(value[i]==1) acron++;
			else if(value[i]>1) tree++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n",tree,acron);
	}
	return 0;
}
