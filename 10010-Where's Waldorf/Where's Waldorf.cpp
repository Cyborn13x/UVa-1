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

/*problemid-10010
 *
 *language-C++
 *
 */

using namespace std;

int len;
int tl;
int row;
int col;
int X;
int Y;
int a[]={1,1,1,-1,-1,-1,0,0};
int b[]={1,0,-1,1,0,-1,1,-1};
char Boggle[52][52];
char line[1000];

void find()
{
      int i;
      int j;
      int k;
      int x1;
      int y1;
      int pos;
      for(i=0;i<row;i++)
      {
            for(j=0;j<col;j++)
            {
                  if(Boggle[i][j]==line[0])
                  {
                        for(k=0;k<8;k++)
                        {
                              x1=i;y1=j;pos=0;
                        	while(line[pos] && line[pos]==Boggle[x1][y1]) {x1+=a[k];y1+=b[k];pos++;}
                        	if(pos==tl) {printf("%d %d\n",i+1,j+1);return;}
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
	bool blank=false;
	cin >> t ;
      for(i=0;i<t;i++)
      {
            if(blank) printf("\n");
            blank=true;
            cin >> row >> col ;
            for(j=0;j<row;j++)
            {
                  cin >> Boggle[j] ;
                  for(k=0;k<col;k++) Boggle[j][k]=tolower(Boggle[j][k]);
            }
            cin >> n ;
            for(k=0;k<n;k++)
            {
            	cin >> line ;
            	tl=strlen(line);
            	for(j=0;j<tl;j++) line[j]=tolower(line[j]);
            	find();
            }
      }
	return 0;
}

