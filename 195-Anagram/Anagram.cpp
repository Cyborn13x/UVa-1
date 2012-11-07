#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

/*problem id-195
 *
 *language-C++
 *
 */

using namespace std;

int cmp(char a,char b)
{
    int d=tolower(a)-tolower(b);
    if(d)
    {
        if(d>0) return 0;
        else return 1;
    }
    else
    {
        if(a<b) return 1;
        else return 0;
    }
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int s;
	int t;
    char a[1000];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%s",a);
	    l=strlen(a);
	    sort(a,a+l,cmp);
		do
        {
            printf("%s\n",a);
        }while(next_permutation(a,a+l,cmp));
	}
	return 0;
}
