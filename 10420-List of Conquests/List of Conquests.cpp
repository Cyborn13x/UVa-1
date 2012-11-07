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

/*problem id-10420
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int t;
	char s[100];
	char *p;
	map<string,int> mp;
	map<string,int>::iterator it;
	scanf("%d\n",&t);
	while(t--) {gets(s);p=strtok(s," ");mp[p]++;}
	for(it=mp.begin();it!=mp.end();it++) cout << it->first << " " << it->second <<endl;
	return 0;
}
