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

/*problemid-422
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
char Boggle[102][102];
char line[1000];

void find()
{
      int i;
      int j;
      int k;
      int x1;
      int y1;
      int pos;
      bool found=false;
      for(i=0;i<row;i++)
      {
            for(j=0;j<row;j++)
            {
                  if(Boggle[i][j]==line[0])
                  {
                        for(k=0;k<8;k++)
                        {
                            x1=i;y1=j;pos=0;
                        	while(line[pos] && line[pos]==Boggle[x1][y1])
                        	{
                        	    x1+=a[k];
                        	    y1+=b[k];
                        	    pos++;
                            }
                        	if(pos==tl)
                        	{
                        	    found=true;
                        	    printf("%d,%d %d,%d\n",i+1,j+1,x1-a[k]+1,y1-b[k]+1);
                        	    return;
                            }
                        }
                  }
            }
      }
      if(!found) printf("Not found\n");
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
	cin >> row;
    for(j=0;j<row;j++) cin >> Boggle[j] ;
    while(scanf("%s",line))
    {
        if(line[0]=='0') break;
        tl=strlen(line);
        find();
    }
	return 0;
}


