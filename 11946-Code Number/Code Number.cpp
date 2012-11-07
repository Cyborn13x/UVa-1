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

/*problem id-11946
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
	char c;
	char a[100];
	map<char,char> mp;
	mp.clear();
	mp['3']='E';mp['0']='O';mp['1']='I';mp['4']='A';mp['9']='P';mp['8']='B';mp['5']='S';mp['7']='T';mp['2']='Z';mp['6']='G';
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		while(gets(a)!=NULL)
		{
			if(!a[0]) break;
			for(i=0;a[i];i++)
			{
				if(a[i]>='0' && a[i]<='9') printf("%c",mp[a[i]]);
				else printf("%c",a[i]);
			}
			printf("\n");
		}
		if(t>0)printf("\n");
	}
	return 0;
}
