#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10282
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
	char s[200],s1[100],s2[100];
	map<string,string> mp;
	while(gets(s))
	{
	    if(s[0]=='\0') break;
	    i=j=0;
	    while(s[i]!=' ') s1[i]=s[i++];
	    s1[i]='\0';
	    i++;
	    while(s[i]!='\0') s2[j++]=s[i++];
	    s2[j]='\0';
		mp[s2]=s1;
	}
	while(cin >> s)
	{
		if(mp[s]!="") cout << mp[s] << endl;
		else cout << "eh" << endl;
	}
	return 0;
}
