#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problemid-11283
 *
 *language-C++
 *
 */

using namespace std;

int len;
int value;
int tl;
bool vis[4][4];
bool use[30];
int a[]={1,1,1,-1,-1,-1,0,0};
int b[]={1,0,-1,1,0,-1,1,-1};
int point[]={0,0,0,1,1,2,3,5,11,11,11,11,11,11,11,11,11};
char Boggle[4][4];
char s[20];
char line[30];
string ts;
queue<string> q;
map<string,int> ml;
map<string,int> mp;

void DFS(int r,int c,int len)
{

      if(r>3 || c>3 || r<0 || c<0 || vis[r][c] || len>tl || Boggle[r][c]!=ts[len-1]) return;
      int i;
      vis[r][c]=true;
      s[len-1]=Boggle[r][c];
      s[len]=0;
      if(len==tl && mp[s]) {value+=point[len];mp[s]=0;}
      for(i=0;i<8;i++) DFS(r+a[i],c+b[i],len+1);
      vis[r][c]=false;
      return;
}

void Solve()
{
      int i;
      int j;
      value=0;
      memset(vis,false,sizeof(vis));
      memset(use,false,sizeof(use));
      while(!q.empty())
      {
      	ts=q.front();
      	q.pop();
      	tl=ts.length();
            for(i=0;i<4;i++)
            {
                  for(j=0;j<4;j++)
                  {
                        if(Boggle[i][j]==ts[0])
                        {
                              s[0]=0;
                              DFS(i,j,1);
                        }
                  }
            }
      }
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int m;
	int n;
	int t;
	char c;
	scanf("%d",&t);
	getchar();
      for(i=0;i<t;i++)
      {
            getchar();
            mp.clear();
            for(j=0;j<4;j++)
            {
                  scanf("%[^\n]",Boggle[j]);
                  getchar();
            }
            scanf("%d\n",&n);
            for(j=0;j<n;j++)
            {
            	scanf("%[^\n]",line);
            	getchar();
            	mp[line]=1;
            	q.push(line);
            }
            Solve();
            printf("Score for Boggle game #%d: %d\n",i+1,value);
      }
	return 0;
}
