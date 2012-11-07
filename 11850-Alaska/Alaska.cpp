#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*problem id-11850
 *
 *language-C++
 *
 *
 */

using namespace std;

int main()
{
	int i;
	int j;
	int n;
	int m;
	bool f;
	vector<int> v;
	while(cin>>n && n)
	{
	      f=1;
	      v.clear();
		for(i=0;i<n;i++)
		{
			cin >>m;
			v.push_back(m);
		}
		sort(v.begin(),v.end());
            for(i=1;i<n;i++)
            {
            	if(v[i]-v[i-1]>200) f=0;
            }
            if(2*(1422-v[n-1])>200) f=0;
            if(f) cout << "POSSIBLE" << endl;
            else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
