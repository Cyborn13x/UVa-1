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

/*problem id-755
 *
 *language-C++
 *
 */

using namespace std;

map<char,int> mobile;

void Process(char *a)
{
      char p[50];
      int i,j,l=strlen(a);
      for(i=j=0;i<l;i++)
      {
      	if(isdigit(a[i])) p[j++]=a[i];
      	else if(isalpha(a[i])) p[j++]=mobile[a[i]]+'0';
      	if(j==3) p[j++]='-';
      }
      p[j]=0;
      strcpy(a,p);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,flag;
	char a[50];
      map<string,int> freq;
      map<string,int>::iterator it;
      for(i='A',x=0,y=2;i<='Z';i++)
      {
            if(i=='Q' || i=='Z') continue;
      	mobile[i]=y;
      	x++;
      	if(x%3==0) y++;
      }
      scanf("%d\n\n",&t);
      while(t--)
      {
            if(blank) putchar('\n'); blank=1; flag=0;
            while(gets(a)!=NULL && a[0])
            {
            	Process(a);
            	freq[a]++;
            }
            for(it=freq.begin();it!=freq.end();it++)
            {
            	if(it->second>1) { cout << it->first << " " << it->second <<endl; flag=1; }
            }
            if(!flag) printf("No duplicates.\n");
            freq.clear();
      }
	return 0;
}
