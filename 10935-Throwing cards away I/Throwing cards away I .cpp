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

/*problem id-10935
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
	int flag;
    deque<int> dq;
    while(scanf("%d",&n)==1 && n)
    {
        flag=false;
        dq.clear();
    	for(i=1;i<=n;i++) dq.push_back(i);
    	printf("Discarded cards:");
    	for(i=1;i<n;i++)
    	{
    	    if(flag) printf(",");
    		flag=true;
    		printf(" %d",dq.front());
    		dq.pop_front();
    		dq.push_back(dq.front());
    		dq.pop_front();
    	}
    	printf("\nRemaining card: %d\n",dq.front());
    }
	return 0;
}
