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

/*problem id-902
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
	string s1;
	string s2;
	while(cin >> n >> s1)
	{
		map<string,int> mp;
		map<string,int>::iterator it;
        pair<string,int> ans;
        l=s1.length();
		for(i=0;i<l-n;i++)
		{
			s2=s1.substr(i,n);
			mp[s2]++;
		}
		for(it=mp.begin();it!=mp.end();it++) if(it->second>ans.second) ans=(*it);
		cout << ans.first << endl;
	}
	return 0;
}
