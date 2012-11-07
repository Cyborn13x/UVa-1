#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-12250
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
	map<string,string> mp;
	mp["HELLO"]= "ENGLISH";
	mp["HOLA"]= "SPANISH";
	mp["HALLO"]= "GERMAN";
	mp["BONJOUR"]= "FRENCH";
	mp["CIAO"]= "ITALIAN";
	mp["ZDRAVSTVUJTE"]= "RUSSIAN";
	n=1;
	char a[20];
	while(scanf("%s",a)==1 && a[0]!='#')
	{
	    printf("Case %d: ",n++);
		if(mp[a][0]) cout << mp[a] << endl;
		else printf("UNKNOWN\n");
	}
    return 0;
}
