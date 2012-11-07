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

/*problem id-454
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
	bool flag=false;
	size_t found;
	string a[105];
	string b[105];
	scanf("%d",&t);
	getchar();
	getchar();
	while(t--)
	{
		if(flag) printf("\n");
		flag=true;
		k=0;
		while(1)
		{
			getline(cin,a[k]);
			if(a[k].length()==0) break;
			k++;
		}
		sort(a,a+k);
		for(i=0;i<k;i++)
		{
			b[i]=a[i];
			sort(b[i].begin(),b[i].end());
			while((found=b[i].find(' '))!=string::npos) b[i].erase(found,1);
		}
		for(i=0;i<k;i++)
		{
			for(j=i+1;j<k;j++)
			{
				if(b[i]==b[j])
				{
				    cout << a[i] << " = " << a[j] << endl;
				}
			}
		}
	}
	return 0;
}
