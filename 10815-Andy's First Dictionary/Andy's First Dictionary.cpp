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

/*problem id-10815
 *
 *language-C++
 *
 */

using namespace std;

int l;

void ToLower(char *s)
{
    int i,j;
    j=strlen(s);
    for(i=0;i<j;i++) s[i]=tolower(s[i]);
    return;
}

int main()
{
	int i;
	int j;
	int k;
	int m;
	int n;
	int t;
	char s[300];
	char a[200];
	vector<string> v;
	vector<string>::iterator it;
	map<string,bool> mp;
	mp.clear();
	v.clear();
	while(scanf("%s",s)!=EOF)
	{
	    l=strlen(s);
	    if(!l) continue;
	    j=0;
	    for(i=0;i<=l;i++)
	    {
	    	if(!isalpha(s[i]) || s[i]=='\0')
	    	{
	    	    a[j]='\0';
	    	    j=0;
	    	    ToLower(a);
	    	    v.push_back(a);
	    	    mp[a]=1;
	    	}
	    	else a[j++]=s[i];
	    }
	}
	sort(v.begin(),v.end());
	unique(v.begin(),v.end());
	for(it=v.begin();it!=v.end();it++)
	{
	    if(*it!="" && mp[*it]==1)
	    {
	        cout << *it << endl;
	        mp[*it]=0;
	    }
	}
	return 0;
}
