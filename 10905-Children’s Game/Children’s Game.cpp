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
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10905
 *
 *language-C++
 *
 */

using namespace std;

bool cmp(string a,string b)
{
    string x=a+b;
    string y=b+a;
    if(x>y) return true;
    return false;
}
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
	string numbers[55];
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++) cin >> numbers[i];
		sort(numbers,numbers+n,cmp);
		for(i=0;i<n;i++) cout << numbers[i];
        printf("\n");
	}
	return 0;
}
