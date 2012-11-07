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

/*problem id-642
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
	int x;
	int y;
	bool flag;
	string end("XXXXXX");
	string str;
	string tmp;
	string word[102];
	i=0;
	while(cin >> word[i] && word[i]!=end) i++;
	sort(word,word+i);
	while(cin >> str && str!=end)
	{
	    sort(str.begin(),str.end());
	    flag=false;
		for(j=0;j<i;j++)
		{
			tmp=word[j];
			sort(tmp.begin(),tmp.end());
			if(tmp==str) {cout << word[j] << endl;flag=true;}
		}
		if(!flag) printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}
