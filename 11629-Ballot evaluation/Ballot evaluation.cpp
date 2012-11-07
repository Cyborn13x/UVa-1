#include <iostream>
#include <sstream>
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
#include <algorithm>

using namespace std;

int main()
{
      //freopen("in.txt","r",stdin);
	int i,j,k,l,m,n,t,x,y,test=0,blank;
	double v,sum;
	bool flag;
	char a[2000],b[50],cmp[5],*p;
	map<string,int> value;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
	      value.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s %d.%d",b,&x,&y);
			value[b]=10*x+y;
		}
		getchar();
            for(i=0;i<m;i++)
            {
            	gets(a); sum=0;
            	p=strtok(a," +");
            	while(p!=NULL && p[0]!='<' && p[0]!='>' && p[0]!='=')
            	{
            		sum+=value[p];
            		p=strtok(NULL," +");
            	}
            	strcpy(cmp,p);
            	p=strtok(NULL," ");
            	sscanf(p,"%d",&x,&y); v=10*x;
            	if(cmp[0]=='>' && !cmp[1]) flag=sum>v;
            	else if(cmp[0]=='<' && !cmp[1]) flag=sum<v;
            	else if(cmp[0]=='>' && cmp[1]=='=' && !cmp[2]) flag=sum>=v;
            	else if(cmp[0]=='<' && cmp[1]=='=' && !cmp[2]) flag=sum<=v;
            	else if(cmp[0]=='='&& !cmp[1]) flag=sum==v;
            	printf("Guess #%d was %s\n",++test,flag ? "correct." : "incorrect.");
            }
	}
	return 0;
}
