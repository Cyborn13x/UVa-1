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
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-409
 *
 *language-C++
 *
 */

using namespace std;

struct excuse
{
      excuse():cnt(0){}
      string str;
      int cnt;
};

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int maxn;
	string s;
	string st;
	string temp;
	map<string,bool> keywords;
	k=1;
	while(cin >> m >> n)
	{
		keywords.clear();
		excuse ex[25];
		for(i=0;i<m;i++){cin >> s ;keywords[s]=true;}
		getchar();
		for(i=0;i<n;i++)
		{
			getline(cin,ex[i].str);
			temp=ex[i].str;
			for(j=0;temp[j];j++) temp[j]=tolower(temp[j]);
			l=temp.size();
			for(j=0;j<l;j++)
			{
				st="";
				while(isalpha(temp[j])) st+=temp[j++];
				if(keywords[st]) (ex[i].cnt)++;
			}
		}
		maxn=-1;
		printf("Excuse Set #%d\n",k++);
		for(i=0;i<n;i++) if(ex[i].cnt>maxn) maxn=ex[i].cnt;
            for(i=0;i<n;i++) if(ex[i].cnt==maxn) cout << ex[i].str <<endl;
            printf("\n");
	}
	return 0;
}
