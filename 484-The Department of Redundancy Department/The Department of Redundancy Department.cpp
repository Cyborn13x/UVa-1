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

/*problem id-484
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
	int n;
	int t;
    vector<int> v;
    vector<int>::iterator it;
    map<int,int> m;
    v.clear();
    m.clear();
    while(scanf("%d",&n)!=EOF)
    {
    	if(m[n]>0) m[n]++;
    	else
    	{
    	    v.push_back(n);
    	    m[n]=1;
    	}
    }
    for(it=v.begin();it!=v.end();it++) cout << *it << " " << m[*it] << endl;
	return 0;
}
