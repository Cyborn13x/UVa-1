#include <iostream>
#include <cstdio>
#include <map>

/*problem id-417
 *
 *language-C++
 *
 */

using namespace std;

int cnt;
char a[6];
map<string,int> idx;

void Generate(int lev,int len)
{
      char c;
      char i;
      if(len==lev)
      {
            idx[a]=++cnt;
            return;
      }
      if(!len) c='a';
      else c=a[len-1]+1;
      for(i=c;i<='z';i++)
      {
            a[len]=i;
      	Generate(lev,len+1);
      }
      return;
}

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
	for(i=1;i<=5;i++)
	{
		a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=0;
		Generate(i,0);
	}
      while(scanf("%s",a)!=EOF) cout << idx[a] <<endl;
	return 0;
}
