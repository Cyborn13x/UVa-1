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

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0;
	bool flag;
	map<pair<int,int>,int> mp;
	map<pair<int,int>,int>::iterator it;;
	pair<int,int> tmp,tmp1;
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			tmp=make_pair(x,y);
			mp[tmp]++;
		}
		for(it=mp.begin(),flag=true;it!=mp.end() && flag;it++)
		{
			tmp=it->first;
			while(it->second>0 && flag)
			{
			      tmp=it->first;
			      tmp1=make_pair(tmp.second,tmp.first);
			      if(mp.count(tmp1))
			      {
			            mp[tmp]--;
			            mp[tmp1]--;
			      }
			      else flag=false;
			}
		}
		if(!flag) printf("NO\n");
		else
		{
		      for(it=mp.begin();it!=mp.end() && flag;it++)
                  {
                        if(it->second) {printf("NO\n"); flag=false;}
                  }
		}
		if(flag) printf("YES\n");
		mp.clear();
	}
	return 0;
}
