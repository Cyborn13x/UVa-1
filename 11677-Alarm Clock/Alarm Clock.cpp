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

/*problem id-11677
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int h1;
	int m1;
	int h2;
	int m2;
	while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)!=EOF && (h1 || m1 || h2 || m2))
	{
		int a=h1*60+m1;
		int b=h2*60+m2;
		if(b<a) b+=1440;
		printf("%d\n",b-a);

	}
	return 0;
}
