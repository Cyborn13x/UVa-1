#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11228
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int u;
      int v;
      double w;
}edge;

int parent[1002];
int point[1002][2];
edge list[1004004];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

int IsUnion(int A,int B)
{
      return FindParent(A)==FindParent(B);
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}

double Distance(int x1,int y1,int x2,int y2)
{
      return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int cmp(const void *a,const void *b)
{
      return ((edge *)a)->w>((edge *)b)->w ? 1 : -1;
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
	int r;
	int states;
	double RoadCost;
	double RailCost;
	scanf("%d",&t);k=1;
	while(t--)
	{
	      states=1;RoadCost=RailCost=0;
		scanf("%d %d",&n,&r);
		for(i=0;i<n;i++) parent[i]=i;
		for(i=0;i<n;i++) scanf("%d %d",&point[i][0],&point[i][1]);
		for(i=x=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				list[x].u=i;
				list[x].v=j;
				list[x].w=Distance(point[i][0],point[i][1],point[j][0],point[j][1]);
				x++;
			}
		}
		qsort(list,x,sizeof(edge),&cmp);
		for(i=y=0;i<x && y<n-1;i++)
		{
			if(!IsUnion(list[i].u,list[i].v))
			{
			      y++;
			      MakeUnion(list[i].u,list[i].v);
			      if(list[i].w>r)
			      {
			            RailCost+=list[i].w;
			            states++;
			      }
			      else RoadCost+=list[i].w;
			}
		}
		printf("Case #%d: %d %.lf %.lf\n",k++,states,RoadCost,RailCost);
	}
	return 0;
}
