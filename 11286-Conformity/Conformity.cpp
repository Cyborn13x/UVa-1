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

/*problem id-11286
 *
 *language-C++
 *
 */

using namespace std;

int cmp(const void *a,const void *b)
{
      return strcmp((char*)a,(char*)b);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,mx,res;
	char a[5][5],total[30];
	map<string,int> cnt;
	map<string,int>::iterator it;
	while(scanf("%d",&n) && n)
	{
	      cnt.clear();
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++) scanf("%s",a[j]);
			qsort(a,5,sizeof(a[0]),&cmp);
			strcpy(total,a[0]);
			strcat(total,a[1]);strcat(total,a[2]);
			strcat(total,a[3]);strcat(total,a[4]);
			cnt[total]++;
		}
		for(it=cnt.begin(),mx=res=0;it!=cnt.end();it++)
		{
			if(it->second>mx)
			{
			      mx=it->second;
			      res=mx;
			}
			else if(it->second==mx) res+=mx;
		}
		printf("%d\n",res);

	}
	return 0;
}
