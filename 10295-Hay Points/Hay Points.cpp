#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10295
 *
 *language-ANSI C
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
	char a[1000];
	char c;
	map<string,int> mp;
	while(scanf("%d %d\n",&m,&n)!=EOF)
	{
	    mp.clear();
		while(m--)
		{
			scanf("%s %d\n",a,&l);
			mp[a]=l;
		}
		while(n--)
		{
		    t=0;
		    while(scanf("%s",a)==1 && strcmp(a,"."))
		    {
		        t+=mp[a];
            }
            printf("%d\n",t);
        }
	}
	return 0;
}
