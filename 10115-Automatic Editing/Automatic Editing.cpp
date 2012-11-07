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

/*problem id-10115
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
	char a[300];
	char b[300];
	size_t found;
	string s1;
	vector<string> v1;
	vector<string> v2;
	while(scanf("%d",&n)==1 && n)
	{
		getchar();
		v1.clear();
		v2.clear();
		for(i=0;i<n;i++)
		{
			gets(a);
			v1.push_back(a);
			gets(a);
			v2.push_back(a);
		}
		gets(a);
		s1=a;
		l=v1.size();
		for(i=0;i<l;i++)
		{
			while((found=s1.find(v1[i]))!=string::npos)
			{
				s1.replace(found,v1[i].length(),v2[i]);
			}
		}
		cout << s1 << endl;
	}
	return 0;
}
