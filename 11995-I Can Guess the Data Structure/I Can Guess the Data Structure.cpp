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

/*problem id-11995
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	bool s,q,p,tmp;
	while(scanf("%d",&n)!=EOF)
	{
	      s=q=p=true;
	      stack<int> st;
	      queue<int> qu;
	      priority_queue<int> pq;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			if(x==1)
			{
			      qu.push(y);
			      st.push(y);
			      pq.push(y);
			}
			else
			{
			      tmp=!st.empty() && st.top()==y;
			      if(tmp) st.pop();
			      s&=tmp;
			      tmp=!qu.empty() && qu.front()==y;
			      if(tmp) qu.pop();
			      q&=tmp;
			      tmp=!pq.empty() && pq.top()==y;
			      if(tmp) pq.pop();
			      p&=tmp;
			}
		}
		if(p+q+s>1) printf("not sure\n");
		else if(p) printf("priority queue\n");
		else if(s) printf("stack\n");
		else if(q) printf("queue\n");
		else printf("impossible\n");
	}
	return 0;
}
