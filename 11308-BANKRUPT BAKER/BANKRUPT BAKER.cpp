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

/*problem id-11308
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
      int cost;
      char name[500];
}recipe;

int cmp(const void *p1,const void *p2)
{
      recipe *a=(recipe*)p1,*b=(recipe*)p2;
      if(a->cost!=b->cost) return a->cost - b->cost;
      return strcmp(a->name,b->name);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,nb,nr,total,flag;
	char BinderName[1000],a[500],tmp[500];
	map<string,int> price;
	recipe list[100];
	scanf("%d\n",&nb);
	while(nb--)
	{
	      price.clear();
		gets(BinderName);
		for(i=0,l=strlen(BinderName);i<l;i++) BinderName[i]=toupper(BinderName[i]);
		scanf("%d %d %d",&m,&nr,&total);
		for(i=0;i<m;i++)
		{
			scanf("%s %d\n",tmp,&x);
			price[tmp]=x;
		}
		for(i=0;i<nr;i++)
		{
			gets(list[i].name);
			list[i].cost=0;
			scanf("%d",&x);
			for(j=0;j<x;j++)
			{
				scanf("%s %d\n",tmp,&y);
				list[i].cost+=y*price[tmp];
			}
		}
		qsort(list,nr,sizeof(recipe),&cmp);
		puts(BinderName);
		for(i=flag=0;i<nr;i++)
		{
			if(list[i].cost>total) break;
			puts(list[i].name); flag=1;
		}
		if(!flag) printf("Too expensive!\n");
		printf("\n");
	}
	return 0;
}
