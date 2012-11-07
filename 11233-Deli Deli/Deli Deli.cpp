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

/*problem id-11233
 *
 *language-C++
 *
 */

using namespace std;

bool vowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	char a[50];
	char b[50];
	map<string,string> mp;
	mp.clear();
	scanf("%d %d",&m,&n);
	getchar();
	while(m--)
	{
		scanf("%s %s",a,b);
		mp[a]=b;
	}
	while(n--)
	{
		scanf("%s",a);
		l=strlen(a);
		if(mp[a]!="") cout << mp[a] << endl;
		else if(a[l-1]=='y' && !vowel(a[l-2])) {a[l-1]='i';a[l]='e';a[l+1]='s';a[l+2]=0;printf("%s\n",a);}
		else if(a[l-1]=='o'||a[l-1]=='s'||(a[l-1]=='h'&&a[l-2]=='c')||(a[l-1]=='h'&&a[l-2]=='s')||a[l-1]=='x')
		{
		    a[l]='e';
		    a[l+1]='s';
		    a[l+2]=0;
		    printf("%s\n",a);
        }
        else {a[l]='s';a[l+1]=0;printf("%s\n",a);}
	}
	return 0;
}
