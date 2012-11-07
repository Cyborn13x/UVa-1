#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-11965
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	bool flag=false;
	char a[505];
	char b[505];
	scanf("%d",&t);
	for(i=0;i<t;i++)
      {
		scanf("%d",&n);
		getchar();
		if(flag) printf("\n");
		flag=true;
		printf("Case %d:\n",i+1);
		while(n--)
		{
		      gets(a);
                  l=strlen(a);
                  k=0;
                  b[k++]=a[0];
                  for(j=1;j<=l;j++) if((a[j]==' ' && a[j-1]!=' ') || a[j]!=' ') b[k++]=a[j];
                  printf("%s\n",b);
		}
      }
	return 0;
}
