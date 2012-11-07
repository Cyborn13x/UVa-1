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

/*problem id-11936
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
	int x;
	int y;
	int a[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		if(a[0]+a[1]>a[2]) printf("OK\n");
		else printf("Wrong!!\n");
	}
	return 0;
}
