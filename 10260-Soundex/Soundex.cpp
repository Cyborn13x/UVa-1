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

/*problem id-10260
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
	char a[30];
	char b[30];
	map<char,int> mp;
	mp['B']=mp['F']=mp['P']=mp['V']=1;
	mp['C']=mp['G']=mp['J']=mp['K']=mp['Q']=mp['S']=mp['X']=mp['Z']=2;
	mp['D']=mp['T']=3;
	mp['L']=4;
	mp['M']=mp['N']=5;
	mp['R']=6;
	while(scanf("%s\n",a)!=EOF)
	{
		l=strlen(a);
		j=1;
		b[0]=a[0];
		for(i=1;i<l;i++) if(a[i]!=b[j-1] && mp[a[i]]!=mp[b[j-1]]) b[j++]=a[i];
		b[j]='\0';
		for(i=0;i<j;i++) if(mp[b[i]]) printf("%d",mp[b[i]]);
		printf("\n");
	}
	return 0;
}
