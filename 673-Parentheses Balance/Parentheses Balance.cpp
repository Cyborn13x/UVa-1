#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

/*problem id-673
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i;
	int j;
	int n;
	int l;
	int flag;
	string a;
	stack<char> s;
	scanf("%d",&n);
	getline(cin,a);
	for(i=0;i<n;i++)
	{
	      flag=1;
		getline(cin,a);
		l=a.length();
		for(j=0;j<l;j++)
		{
			if(a[j]=='(' || a[j]=='[')
                  {
                        s.push(a[j]);
                  }
                  else
                  {
                        if(a[j]==')')
                        {
                              if(!s.empty())
                              {
                                    if(s.top()=='(')
                                    {
                                          s.pop();
                                          continue;
                                    }
                                    else
                                    {
                                          flag=0;
                                          break;
                                    }
                              }
                              else
                              {
                                    flag=0;
                                    break;
                              }
                        }
                        else if(a[j]==']')
                        {
                              if(!s.empty())
                              {
                                    if(s.top()=='[')
                                    {
                                          s.pop();
                                          continue;
                                    }
                                    else
                                    {
                                          flag=0;
                                          break;
                                    }
                              }
                              else
                              {
                                    flag=0;
                                    break;
                              }
                        }
                  }
		}
		if(s.empty()==false)
		{
		      flag=0;
		}
		if(flag)
		{
		      printf("Yes\n");
		}
		else
		{
		      printf("No\n");
		}
		while (!s.empty())
            {
                  s.pop();
            }
	}
	return 0;
}
