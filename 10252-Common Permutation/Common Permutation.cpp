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

/*problem id-10252
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
	int l1;
	int l2;
	int a[30];
	char s1[1100];
	char s2[1100];
	while(gets(s1))
	{
	    gets(s2);
	    memset(a,0,sizeof(a));
	    l1=strlen(s1);
	    sort(s1,s1+l1);
		for(i=0;i<l1;i++) a[s1[i]-'a']++;
		l2=strlen(s2);
		sort(s2,s2+l2);
		for(i=0;i<l2;i++)
		{
		    if(a[(s2[i]-'a')])
		    {
		        printf("%c",s2[i]);
		        a[(s2[i]-'a')]--;
            }
		}
		printf("\n");
	}
	return 0;
}
