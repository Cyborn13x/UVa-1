#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-514
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
      //freopen("in.txt","r",stdin);
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,flag;
	while(scanf("%d",&n) && n)
	{
		while(scanf("%d",&x))
		{
		      if(!x)
		      {
		            putchar('\n');
		            break;
		      }
			stack<int> a,b;
			a.push(x);
			for(i=flag=1;i<n;i++)
			{
				scanf("%d",&x);
				a.push(x);
			}
			for(i=n;i>0 && flag;i--)
			{
				if(!b.empty() && b.top()==i) { b.pop(); continue; }
				while(1)
				{
					if(!a.empty() && a.top()==i)
					{
					      a.pop();
					      flag=1;
					      break;
					}
					else if(!a.empty() && a.top()!=i)
					{
					      b.push(a.top());
					      a.pop();
					      flag=0;
					}
					else { flag=0; break; }
				}
			}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
