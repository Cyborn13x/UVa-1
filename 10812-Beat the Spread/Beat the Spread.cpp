#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int i;
	int j;
	int s;
	int d;
	int x;
	int y;
	int TestCase;
	cin>>TestCase;
	for(i=0;i<TestCase;i++)
	{
	      cin>>s>>d;
            y=(s-d)/2;
            x=d+y;
            if(x<0 || y<0 || (s-d)%2)
            {
                  cout<<"impossible"<<endl;
            }
            else
            {
                  cout<<x<<" "<<y<<endl;
            }
	}
	return 0;
}
