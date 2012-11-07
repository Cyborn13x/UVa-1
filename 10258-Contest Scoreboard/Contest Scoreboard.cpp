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

/*problem id-10258
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
      int num,AC,WA[15],time[15],solved,penalty,used;
}team;

team ar[102],contest[102];

void init()
{
      for(int i=0;i<102;i++)
      {
      	ar[i].num=i;
      	ar[i].AC=ar[i].solved=ar[i].penalty=ar[i].used=0;
      	memset(ar[i].WA,0,sizeof(ar[i].WA));
      }
      return;
}

int cmp(const void *p1,const void *p2)
{
      team *a=(team*)p1,*b=(team*)p2;
      if(a->solved<b->solved) return 1;
      else if(a->solved==b->solved)
      {
            if(a->penalty>b->penalty) return 1;
            else if(a->penalty==b->penalty)
            {
                  if(a->num>b->num) return 1;
                  else return -1;
            }
            else return -1;
      }
      else return -1;
}

int main()
{
	int i,j,k,l,m,n,p,t,x,y,test,blank=0;
	char res,line[30];
	scanf("%d\n\n",&test);
	while(test--)
	{
	      if(blank) putchar('\n');
	      init(); blank=1;
		while(gets(line) && line[0])
		{
			sscanf(line,"%d %d %d %c",&n,&p,&t,&res);
			ar[n].used=1;
			if(res=='C' && !(ar[n].AC&1<<p)) ar[n].AC=(ar[n].AC)|1<<p, ar[n].time[p]=t, ar[n].solved++;
			else if(res=='I' && !(ar[n].AC&1<<p)) ar[n].WA[p]++;
		}
		for(i=1,k=0;i<102;i++)
		{
		      if(ar[i].solved)
		      {
		            for(j=1;j<15;j++)
		            {
		            	if(ar[i].AC&1<<j) ar[i].penalty+=ar[i].time[j]+ar[i].WA[j]*20;
		            }
		            contest[k++]=ar[i];
		      }
		      else if(ar[i].used) contest[k++]=ar[i];
		}
		qsort(contest,k,sizeof(team),&cmp);
		for(i=0;i<k;i++)
		{
			printf("%d %d %d\n",contest[i].num,contest[i].solved,contest[i].penalty);
		}
	}
	return 0;
}
