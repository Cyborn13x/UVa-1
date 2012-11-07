#include <iostream>
#include <sstream>
#include <fstream>
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

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-x):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 100

/*problem id-353
 *
 *language-C++
 *
 */

using namespace std;

int IsPalindrom(char *a)
{
      int i,l=strlen(a);
      For(i,l/2) if(a[i]!=a[l-i-1]) return 0;
      return 1;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
      char a[SZ],b[SZ];
      map<string,bool> used;
      while(gets(a)!=NULL)
      {
            used.clear();
      	l=strlen(a);
      	For(i,l)
      	{
      	      for(j=i,b[0]=0;j<l;j++)
      	      {
      	      	b[j-i]=a[j], b[j-i+1]=0;
      	      	if(IsPalindrom(b)) used[b]=true;
      	      }
      	}
      	printf("The string '%s' contains %d palindromes.\n",a,(int)used.size());
      }
	return 0;
}
