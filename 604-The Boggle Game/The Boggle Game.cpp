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

/*problemid-604
 *
 *language-C++
 *
 */

using namespace std;

int vowel;
int row;
int n;
bool vis[4][4];
int a[]={1,1,1,-1,-1,-1,0,0};
int b[]={1,0,-1,1,0,-1,1,-1};
char Boggle[2][4][4];
char s[10];
char line[300];
vector<string> v;
vector<string>::iterator it;
map<string,int> mp1;
map<string,int> mp2;

int IsVowel(char c)
{
      return (c=='A' ||c=='E' || c=='I' || c=='O' || c=='U' || c=='Y');
}

void DFS(int r,int c,int len)
{

      if(r>3 || c>3 || r<0 || c<0 || len>4) return;
      if(vis[r][c]==true) return;
      int i;
      vis[r][c]=true;
      s[len-1]=Boggle[n][r][c];
      s[len]=0;
      if(len==4)
      {
            vowel=0;
            for(i=0;i<4;i++) vowel+=IsVowel(s[i]);
            if(vowel==2)
            {
                  v.push_back(s);
                  if(n==0) mp1[s]=1;
                  else mp2[s]=1;
            }
            vis[r][c]=false;
            return;
      }

      for(i=0;i<8;i++) DFS(r+a[i],c+b[i],len+1);
      vis[r][c]=false;
      return;
}

void Build()
{
      int i;
      int j;
      int k=0;
      for(i=0,j=0;i<7;i++) if(line[i]!=' ') {k++;Boggle[0][row][j++]=line[i];}
      for(i=11,j=0;i<18;i++) if(line[i]!=' ') Boggle[1][row][j++]=line[i];
      row++;
      return;
}

void Solve()
{
      int i;
      int j;
      int vl;
      int match;
      for(n=0;n<2;n++)
      {
      	for(i=0;i<4;i++)
      	{
      		for(j=0;j<4;j++)
      		{

      			memset(vis,false,sizeof(vis));
      			s[0]=0;
      			DFS(i,j,1);
      		}
      	}
      }
      sort(v.begin(),v.end());
      it=unique(v.begin(),v.end());
      v.resize(it-v.begin());
      vl=v.size();
      match=0;
      for(i=0;i<vl;i++)
      {
      	if(mp1[v[i]]==1 && mp2[v[i]]==1)
      	{
      	      match++;
      	      cout << v[i] <<endl;
      	}
      }
      if(!match) printf("There are no common words for this pair of boggle boards.\n");
      row=0;
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int m;
	int t;
	char c;
	bool flag=false;
      row=0;
      while(gets(line) && strcmp(line,"#"))
      {
      	if(line[0]) Build();
      	if(row==4)
      	{
      	      mp1.clear();
      	      mp2.clear();
      	      v.clear();
      	      if(flag) printf("\n");
                  flag=true;
      	      Solve();
      	      gets(line);
            }
      }
	return 0;
}
