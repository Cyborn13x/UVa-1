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

/*problem id-895
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
	int vl;
	int count;
	int f[30];
	int c[30];
	char a[20];
	char b[1000];
	bool flag;
	string s;
    vector<string> v;
    v.clear();
    while(1)
    {
    	scanf("%s",a);
    	if(a[0]=='#') break;
    	v.push_back(a);
    }
    getchar();
    vl=v.size();
    while(1)
    {
    	scanf("%[^\n]",b);
    	getchar();
    	if(b[0]=='#') break;
    	l=strlen(b);
    	count=0;
    	memset(f,0,sizeof(f));
    	for(i=0;i<l;i++) if(b[i]!=' ') f[b[i]-'a']++;
    	for(i=0;i<vl;i++)
    	{
    	    flag=true;
    		for(j=0;j<30;j++) c[j]=f[j];
    		s=v[i];
    		l=s.length();
    		for(j=0;j<l;j++)
    		{
    			if(c[s[j]-'a']) c[s[j]-'a']--;
    			else flag=false;
    			if(!flag) break;
    		}
    		if(flag) count++;
    	}
    	printf("%d\n",count);

    }
	return 0;
}
