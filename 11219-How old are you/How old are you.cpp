#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-11219
 *
 *language-C++
 *
 */

using namespace std;

int birth_date;
int birth_month;
int birth_year;
int cur_date;
int cur_month;
int cur_year;
int year;

bool IsValid()
{
      if(birth_year>cur_year) return true;
      if(birth_year<cur_year) return false;
      if(birth_month>cur_month) return true;
      if(birth_month<cur_month) return false;
      if(birth_date>cur_date) return true;
      return false;
}

void age()
{
      year=cur_year-birth_year;
      if(cur_month<birth_month) year--;
      else if(cur_month==birth_month) if(cur_date<birth_date) year--;
      return;
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
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d/%d/%d",&cur_date,&cur_month,&cur_year);
		scanf("%d/%d/%d",&birth_date,&birth_month,&birth_year);
		printf("Case #%d: ",i+1);
		if(IsValid()) printf("Invalid birth date");
		else
		{
		      age();
		      if(year>130) printf("Check birth date");
		      else printf("%d",year);
		}
		printf("\n");
	}
	return 0;
}
