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

/*problem id-10954
 *
 *language-C++
 *
 */

using namespace std;

struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int sum;
	priority_queue<int,vector<int>,compare> p;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			p.push(m);
		}
		l=p.size()-1;
		sum=0;
		while(l--)
		{
		    m=0;
			m+=p.top();
			p.pop();
			m+=p.top();
			p.pop();
			p.push(m);
			sum+=m;
		}
		printf("%d\n",sum);
		p.pop();
	}
	return 0;
}
