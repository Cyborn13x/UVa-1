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

/*problem id-118
 *
 *language-C++
 *
 */

using namespace std;

int row;
int col;
bool flag;
bool scent[51][51];
char dir;
char a[105];
map<char,char> lefti;
map<char,char> righti;

void Move(int x,int y)
{
      int i;
      int j;
      int r=x;
      int c=y;
      int lr;
      int lc;
      flag=false;
      for(i=0;a[i];i++)
      {
            lr=r;lc=c;
      	if(a[i]=='L') dir=lefti[dir];
      	else if(a[i]=='R') dir=righti[dir];
      	else if(a[i]=='F')
      	{
      	      if(dir=='E') c++;
      	      else if(dir=='N') r++;
      	      else if(dir=='W') c--;
      	      else r--;
      	      if(r<0 || r>row || c<0 || c>col)
      	      {
      	            if(scent[lr][lc]) { r=lr; c=lc; }
      	            else
      	            {
      	                  scent[lr][lc]=true;
      	                  printf("%d %d %c LOST\n",lc,lr,dir);
      	                  flag=true;
      	                  return;
      	            }
      	      }
      	}
      }
      if(!flag) printf("%d %d %c\n",c,r,dir);
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
	lefti['N']='W';lefti['W']='S';lefti['S']='E';lefti['E']='N';
	righti['N']='E';righti['E']='S';righti['S']='W';righti['W']='N';
	scanf("%d %d",&col,&row);
	while(scanf("%d %d %c",&x,&y,&dir)!=EOF)
	{
		scanf("%s",a);
		Move(y,x);
	}
	return 0;
}
