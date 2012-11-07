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

/*problem id-10075
 *
 *language-C++
 *
 */

using namespace std;

const int R=6378;
const double PI=3.141592653589793;
const double INF=1e30;

double ToRadian(double x)
{
      return (x*PI/180);
}

double Distance(double lt1,double ln1,double lt2,double ln2)
{
      double lat1=ToRadian(lt1);
      double lat2=ToRadian(lt2);
      double lon1=ToRadian(ln1);
      double lon2=ToRadian(ln2);
      double dis=acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(lon2-lon1));
      return (dis*R);
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
	int N;
	int M;
	int Q;
	int test=1;
	int blank=0;
	double X;
	double Y;
	double position[101][2];
	double floyd[101][101];
	char a[50];
	char b[50];
	map<string,int> idx;
	map<string,int>::iterator it;
	while(scanf("%d %d %d",&N,&M,&Q) && (N || M || Q))
	{
	      if(blank) printf("\n");
	      blank=1; idx.clear();
		for(i=0;i<=N;i++)
		{
		      for(j=i+1;j<=N;j++)
		      {
		            floyd[i][j]=floyd[j][i]=INF;
		      }
		      floyd[i][i]=0;
		}
		for(i=0;i<N;i++)
		{
			scanf("%s %lf %lf",a,&position[i][0],&position[i][1]);
			idx[a]=i;
		}
		for(i=0;i<M;i++)
		{
			scanf("%s %s",a,b);
			x=idx[a]; y=idx[b];
			X=Distance(position[x][0],position[x][1],position[y][0],position[y][1]);
			floyd[x][y]=floyd[x][y]>floor(X+.5) ? floor(X+.5) : floyd[x][y];
		}
		for(k=0;k<N;k++)
		{
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
				{
				      if(floyd[i][k]!=INF && floyd[k][j]!=INF)
					{
					      if(floyd[i][k]+floyd[k][j]<floyd[i][j])
                                    {
                                          floyd[i][j]=floyd[i][k]+floyd[k][j];
                                    }
					}
				}
			}
		}
		printf("Case #%d\n",test++);
		for(i=0;i<Q;i++)
		{
			scanf("%s %s",a,b);
			x=idx[a]; y=idx[b];
			if(floyd[x][y]==INF) printf("no route exists\n");
			else printf("%.lf km\n",floyd[x][y]);
		}
	}
	return 0;
}
