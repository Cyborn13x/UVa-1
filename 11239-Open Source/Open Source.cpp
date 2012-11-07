#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
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

/*problem id-11239
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
	string p;
	string s;
	string tmp;
	map<string,int> number;
	map<string,int>::iterator i3;
	map<int,set<string> > cnt;
	map<int,set<string> >::iterator i4;
	map<string,set<string> > project;
	map<string,set<string> > student;
	map<string,set<string> >::iterator i1;
	set<string>::iterator i2;
	while(1)
	{
	      number.clear();
	      cnt.clear();
	      project.clear();
            student.clear();
		while(getline(cin,tmp) && tmp!="1" && tmp!="0")
		{
			if(tmp[0]>='A' && tmp[0]<='Z') {p=tmp;project[p].insert("");continue;}
			else s=tmp;
			project[p].insert(s);
			student[s].insert(p);
		}
		if(tmp=="0") break;
		for(i1=project.begin();i1!=project.end();i1++)
		{
			for(i2=(i1->second).begin();i2!=(i1->second).end();i2++)
			{
				number[i1->first]+=(student[*i2].size()==1);
			}
		}
		for(i3=number.begin();i3!=number.end();i3++) cnt[i3->second].insert(i3->first);
		for(i4=cnt.end(),--i4;;i4--)
		{
			for(i2=(i4->second).begin();i2!=(i4->second).end();i2++)
			{
				cout << *i2 << " " << i4->first <<endl;
			}
			if(i4==cnt.begin()) break;
		}

	}
	return 0;
}
