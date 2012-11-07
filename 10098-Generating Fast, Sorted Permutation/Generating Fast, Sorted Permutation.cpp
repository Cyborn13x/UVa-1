#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10098
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int t;
	int l;
	char s[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		l=strlen(s);
		sort(s,s+l);
		do{printf("%s\n",s);}while(next_permutation(s,s+l));
		printf("\n");
	}
	return 0;
}
