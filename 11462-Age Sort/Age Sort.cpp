#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator i;
    int n,m,j;
    while(scanf("%d",&n) && n)
    {
        v.clear();
        for(m=0;m<n;m++)
        {
        	scanf("%d",&j);
        	v.push_back(j);
        }
        sort(v.begin(),v.end());
        for(i=v.begin();i!=v.end();i++)
        {
        	if(i<v.end()-1)
        	{
        	    printf("%d ",*i);
        	}
        	else
        	{
        	    printf("%d",*i);
        	}
        }
        printf("\n");
    }
}
