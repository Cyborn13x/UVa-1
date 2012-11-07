#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int j,m,c,h,NumberOfMurbales,NumberOfSearch;
	vector<int> Marble;
	vector<int> Search;
	vector<int>::iterator i,o;
	h=0;
	while(scanf("%d %d",&NumberOfMurbales,&NumberOfSearch) && NumberOfMurbales && NumberOfSearch)
	{
	    h++;
		for(j=0;j<NumberOfMurbales;j++)
		{
		    scanf("%d",&m);
			Marble.push_back(m);
		}
		for(j=0;j<NumberOfSearch;j++)
		{
			scanf("%d",&m);
			Search.push_back(m);
		}
		sort(Marble.begin(),Marble.end());
		printf("CASE# %d:\n",h);
		for(o=Search.begin(),j=0;o!=Search.end();o++,j++)
		{
		    c=0;
			for(i=Marble.begin(),m=0;i!=Marble.end();i++,m++)
			{
				if(*o==*i)
				{
				    printf("%d found at %d\n",*o,m+1);
				    c=1;
				    break;
				}
			}
			if(!c)
			{
			    printf("%d not found\n",*o);
			}
		}
		Marble.clear();
		Search.clear();
	}
	return 0;
}
