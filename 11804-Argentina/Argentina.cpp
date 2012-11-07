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

/*problem id-11804
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
      char name[20];
      int attack;
      int defend;
}player;

int cmp(const void *a,const void *b)
{
      player p1=*(player *)a;
      player p2=*(player *)b;
      if(p1.attack<p2.attack) return 1;
      else if(p1.attack==p2.attack)
      {
            if(p1.defend>p2.defend) return 1;
            else if(p1.defend==p2.defend) return strcmp(p1.name,p2.name);
            else return -1;
      }
      else return -1;
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
	int y; y=0;
      player team[10];
      set<string> Attack;
      set<string> Defend;
      set<string>::iterator it;
      scanf("%d",&t);
      while(t--)
      {
            Attack.clear(); Defend.clear();
      	for(i=0;i<10;i++) scanf("%s %d %d",team[i].name,&team[i].attack,&team[i].defend);
      	qsort(team,10,sizeof(player),&cmp);
      	for(i=0;i<5;i++) Attack.insert(team[i].name);
      	for(i=5;i<10;i++) Defend.insert(team[i].name);
      	printf("Case %d:\n(",++y);
      	cout << *(it=Attack.begin());
      	for(++it;it!=Attack.end();it++) cout << ", " << *it;
      	printf(")\n(");
      	cout << *(it=Defend.begin());
      	for(++it;it!=Defend.end();it++) cout << ", " << *it;
      	printf(")\n");
      }
	return 0;
}
