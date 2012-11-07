#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10324
 *
 *language-C++
 *
 */

char a[10000000];
int start;
int end;
int b[500000];

int check()
{
      int i;
      char c=a[start];
      for(i=start+1;i<=end;i++)
      {
      	if(a[i]!=c) return false;
      }
      return true;
}

int max(int i,int j)
{
      if(i>=j) return i;
      else return j;
}

int min(int i,int j)
{
      if(i<j) return i;
      else return j;
}

int main()
{
	int i;
	int j=1;
	int n;
	int aa;
	int bb;
	while(scanf("%s",a)==1)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&aa,&bb);
			start=min(aa,bb);
			end=max(aa,bb);
			b[i]=check();
		}
		printf("Case %d:\n",j);
		j++;
		for(i=0;i<n;i++)
		{
			if(b[i]) printf("Yes\n");
			else printf("No\n");
		}
		fflush(stdin);
	}
	return 0;
}
