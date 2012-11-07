#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-11362
 *
 *language-C++
 *
 */

using namespace std;

bool check(string a,string b)
{
    int l1=a.length();
    int l2=b.length();
    if(l2<l1) return false;
    for(int i=0;i<l1;i++) if(a[i]!=b[i]) return false;
    return true;
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
	bool flag;
	string s[10010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=true;
		for(i=0;i<n;i++) cin >> s[i];
		sort(s,s+n);
		for(i=0;i<n-1;i++) if(check(s[i],s[i+1])) {flag=false;break;}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
    }
	return 0;
}
