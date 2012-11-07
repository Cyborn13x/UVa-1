#include <stdio.h>
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

/*problem id-11968
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
	int cake;
	int drink;
	int price[1001];
	long long int sum;
	double avg;
	scanf("%d",&t);x=1;
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(i=sum=0;i<n;i++) { scanf("%d",&price[i]); sum+=price[i]; }
		sort(price,price+m);
		sort(price+m+1,price+m+k);
		for(i=1,avg=(sum*1.0)/n,cake=price[0];i<m;i++) if(fabs(price[i]-avg)<fabs(cake-avg)) cake=price[i];
		for(i=m+1,drink=price[m];i<m+k;i++) if(fabs(price[i]-avg)<fabs(drink-avg)) drink=price[i];
		printf("Case #%d: %d %d\n",x++,cake,drink);
	}
	return 0;
}
