#include <iostream>
#include <sstream>
#include <fstream>
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

#define INF 1<<30
#define SZ 100000

/*problem id-789
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y=0,blank=0,test=0;
	char key,a[100],b[30];
	map<string,set<int> > idx;
	scanf("%c%*c",&key);
	idx.clear();
	while(gets(a))
	{
	      y++;
		for(i=0,l=strlen(a);i<l;i++)
		{
			if(!isalpha(a[i])) continue;
			x=0;
			while(i<l && isalpha(a[i])) b[x++]=a[i++];
			b[x]=0;
			if(b[0]==key) idx[b].insert(y);
		}
	}
	for(map<string,set<int> >::iterator it1=idx.begin();it1!=idx.end();it1++)
	{
	      cout << it1->first;
		for(set<int>::iterator it2=(it1->second).begin();it2!=(it1->second).end();it2++)
		{
			printf(" %d",*it2);
		}printf("\n");
	}
	return 0;
}
