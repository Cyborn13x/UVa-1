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

#define INF 10000000

/*problem id-186
 *
 *language-C++
 *
 */

using namespace std;

const char Title[]="From                 To                   Route      Miles";
const char Total[]="                                          Total      ";
const char dot[]="-------------------- -------------------- ---------- -----";
const char dot1[]="                                                     -----";
char name[105][30],route[102][102][30];
int City,Floyd[105][105],Predessor[105][105];
map<string,int> idx;

int min(int a,int b) { return a<b ? a : b; }

void _init_()
{
      int i;
      int j;
      for(i=1;i<105;i++)
      {
      	for(j=i+1;j<105;j++)
      	{
      		Floyd[i][j]=Floyd[j][i]=INF;
      		Predessor[i][j]=Predessor[j][i]=-1;
      	}
      }
      return;
}

void PrintPath(int a,int b)
{
      if(Predessor[a][b]==-1) printf("%-20s %-20s %-10s %5d\n",name[a],name[b],route[a][b],Floyd[a][b]);
      else { PrintPath(a,Predessor[a][b]); PrintPath(Predessor[a][b],b); }
}

void FloydWarshall()
{
      int i,j,k;
      for(k=1;k<City;k++)
      {
      	for(i=1;i<City;i++)
      	{
      		for(j=1;j<City;j++)
      		{
      			if(Floyd[i][k]+Floyd[k][j]<Floyd[i][j])
      			{
      			      Floyd[i][j]=Floyd[i][k]+Floyd[k][j];
      			      Predessor[i][j]=Predessor[j][i]=k;
      			}
      		}
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,ans,val,cnt=1,top=0;
	char tmp[200],a[30],b[30],r[30],*p;
	_init_(); City=1;
      while(gets(tmp) && tmp[0])
      {
            p=strtok(tmp,",");
            strcpy(a,p);
            if(!idx[p]) { idx[p]=City; strcpy(name[City++],p); }
            p=strtok(NULL,",");
            strcpy(b,p);
            if(!idx[p]) { idx[p]=City; strcpy(name[City++],p); }
            p=strtok(NULL,",");
            x=idx[a], y=idx[b];
            strcpy(r,p);

            p=strtok(NULL,",");
            val=atoi(p);
            if(val<Floyd[x][y])
            {
                  Floyd[x][y]=Floyd[y][x]=val;
                  strcpy(route[x][y],r);
                  strcpy(route[y][x],r);
            }
      }
      FloydWarshall();
      while(gets(tmp)!=NULL)
      {
      	p=strtok(tmp,",");
      	x=idx[p];
      	p=strtok(NULL,",");
      	y=idx[p];
      	ans=Floyd[x][y];
      	printf("\n\n%s\n%s\n",Title,dot);
      	PrintPath(x,y);
      	printf("%s\n%s%5d\n",dot1,Total,ans);
      }
	return 0;
}
