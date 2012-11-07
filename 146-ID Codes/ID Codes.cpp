#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-146
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
	char a[60];
	while(1)
	{
		scanf("%s",a);
		if(a[0]=='#') break;
        if(next_permutation(a,a+strlen(a))) printf("%s\n",a);
        else printf("No Successor\n");
	}
	return 0;
}
