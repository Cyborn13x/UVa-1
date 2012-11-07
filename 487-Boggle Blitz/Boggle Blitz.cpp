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

/*problem id-487
 *
 *language-C++
 *
 */

using namespace std;

int N;
int M;
int cnt;
int top;
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
bool vis[21][21];
char tmp[500];
char grid[21][21];
char words[500000][30];
map<string,bool> mp;

bool valid(int x,int y)
{
      return (x>=0 && x<N && y>=0 && y<N && !vis[x][y]);
}

void search(int x,int y)
{
      int i;
      char cur;
      vis[x][y]=true; cur=grid[x][y]; tmp[cnt++]=cur;
      if(cnt>=3 && cnt<=M)
      {
            tmp[cnt]=0;
            if(!mp[tmp])
            {
                  mp[tmp]=true;
                  strcpy(words[top++],tmp);
            }
      }
      for(i=0;i<8;i++)
      {
            if(valid(x+dx[i],y+dy[i]) && cur<grid[x+dx[i]][y+dy[i]])
            {
                  search(x+dx[i],y+dy[i]);
            }
      }
      cnt--; vis[x][y]=false;
      return;
}

int cmp(const void *a,const void *b)
{
      char *c=(char *)a;
      char *d=(char *)b;
      int l1=strlen(c);
      int l2=strlen(d);
      if(l1!=l2) return l1-l2;
      else return strcmp(c,d);
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
	int blank=0;
	scanf("%d",&t);
	while(t--)
	{
		if(blank) printf("\n");
		blank=1; mp.clear(); scanf("%d",&N); M=N*N;
		for(i=0;i<N;i++) scanf("%s",grid[i]);
		for(i=top=0;i<N;i++) for(j=0;j<N;j++) { cnt=0; search(i,j); }
		qsort(words,top,sizeof(words[0]),&cmp);
		for(i=0;i<top;i++) printf("%s\n",words[i]);
	}
	return 0;
}
