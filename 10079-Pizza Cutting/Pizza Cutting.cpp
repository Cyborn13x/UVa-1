#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

/*problem id-10079
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int j;
	int n;
	long long unsigned int a;
	while(cin>>n && n>=0)
	{
	      a=1;
		for(unsigned long i=1;i<=n;i++)
		{
			a+=i;
		}
		cout<<a<<endl;
	}
	return 0;
}
