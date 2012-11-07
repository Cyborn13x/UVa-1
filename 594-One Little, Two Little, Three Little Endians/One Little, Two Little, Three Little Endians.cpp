#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
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

/*problem id-594
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,ans;
	bitset<100> bs;
	while(scanf("%d",&n)!=EOF)
	{
            for(i=x=ans=0;i<32;i++) bs[x++]=n&(1<<i);
            for(i=0;i<8;i++)
            {
                  x=31-(7-i);
            	if(bs[i]) ans|=1<<x;
            	if(bs[x]) ans|=1<<i;
            }
            for(i=8;i<16;i++)
            {
            	x=23-(7-(i-8));
            	if(bs[i]) ans|=1<<x;
            	if(bs[x]) ans|=1<<i;
            }
            printf("%d converts to %d\n",n,ans);
	}
	return 0;
}
