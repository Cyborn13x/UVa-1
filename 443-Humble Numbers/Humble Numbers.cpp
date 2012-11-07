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

/*problem id-443
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
	set<double> Humble;
	Humble.insert(1);
	set<double>::iterator it=Humble.begin();
	while(Humble.size()<7000)
	{
		Humble.insert(*it *2);
		Humble.insert(*it *3);
		Humble.insert(*it *5);
		Humble.insert(*it *7);
		*it++;
	}
	vector<double> v(Humble.begin(),Humble.end());
	while(scanf("%d",&n) && n)
	{
		printf("The %d",n);
		if(n%10==1 && n%100!=11) printf("st");
		else if(n%10==2 && n%100!=12) printf("nd");
		else if(n%10==3 && n%100!=13) printf("rd");
		else printf("th");
		printf(" humble number is %.0lf.\n",v[n-1]);
	}
	return 0;
}
