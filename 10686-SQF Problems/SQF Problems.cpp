#include <algorithm>
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

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 100000

/*problem id-10686
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,catagory,score[20],catagoryrequir[20],flag;
	char catagoryname[30][50],tmp[500],line[120];
      map<string,bool> valid[22],all;
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d",&catagory);
      	CLEAR(score); all.clear();
      	FOR(i,catagory) valid[i].clear();
      	FOR(i,catagory)
      	{
      		scanf("%s %d %d",catagoryname[i],&n,&catagoryrequir[i]);
      		while(n--)
      		{
      			scanf("%s",tmp);
      			valid[i][tmp]=true;
      			all[tmp]=true;
      		}
      	}getchar();
      	while(gets(line)!=NULL && line[0])
      	{
      	      for(i=0,l=strlen(line);i<l;i++)
      	      {
      	            x=0;
      	      	while(i<l && isalpha(line[i])) tmp[x++]=line[i++];
      	      	tmp[x]=0;
      	      	if(!x) continue;
      	      	if(all[tmp])
      			{
      			      for(j=0;j<catagory;j++)
      			      {
      			      	if(valid[j][tmp]) {score[j]++; valid[j][tmp]=false;}
      			      }
      			}
      	      }
      	}
      	for(i=j=flag=0;i<catagory;i++)
      	{
      		if(score[i]>=catagoryrequir[i])
      		{
      		      if(j) putchar(',');
      		      printf("%s",catagoryname[i]);
      		      j=flag=1;
      		}
      	}
      	if(!flag) printf("SQF Problem.");
      	printf("\n");
      }
	return 0;
}
