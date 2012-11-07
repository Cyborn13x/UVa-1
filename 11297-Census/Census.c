#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF (1<<30)

/*Problem id-11297
 *language-ANSI C
 *First problem of 2D segment tree
 *সোজা প্রবলেম কিন্তু implement করতে
 *একটু টাইম লাগছে ।
 *
 */

typedef struct
{
      int min,max,xx,yy;
}Small;

Small Tree[502][2005];
int grid[502][502],N,ANSMIN,ANSMAX;

int min(int a,int b) { return a<b ? a : b; }

int max(int a,int b) { return a>b ? a : b; }

void BuildSmallTree(int I,int node,int start,int end)
{
      int left=node<<1, right=left+1, mid=(start+end)>>1;
      Tree[I][node].xx = start, Tree[I][node].yy = end;
      if(start==end) { Tree[I][node].min=Tree[I][node].max=grid[I][start]; return; }
      BuildSmallTree(I,left,start,mid);
      BuildSmallTree(I,right,mid+1,end);
      Tree[I][node].min=min(Tree[I][left].min,Tree[I][right].min);
      Tree[I][node].max=max(Tree[I][left].max,Tree[I][right].max);
      return;
}

void BuildBigTree(int start,int end)
{
      int i;
      for(i=start;i<end;i++) BuildSmallTree(i,1,0,end-1);
      return;
}

void UpdateSmallTree(int I,int J,int node,int val)
{
      int left=node<<1, right=left+1, x=Tree[I][node].xx, y=Tree[I][node].yy;
      if(J>y || J<x) return;
      if(x==y && y==J) { Tree[I][node].min=Tree[I][node].max=val; return; }
      UpdateSmallTree(I,J,left,val);
      UpdateSmallTree(I,J,right,val);
      Tree[I][node].min=min(Tree[I][left].min,Tree[I][right].min);
      Tree[I][node].max=max(Tree[I][left].max,Tree[I][right].max);
}

void UpdateBigTree(int I,int J,int val)
{
      UpdateSmallTree(I,J,1,val);
}

void SearchSmallTree(int I,int node,int start,int end)
{
      int left=node<<1, right=left+1, x=Tree[I][node].xx, y=Tree[I][node].yy;
      if(start>y || end<x) return;
      if(x>=start && y<=end)
      {
            ANSMIN=min(ANSMIN,Tree[I][node].min);
            ANSMAX=max(ANSMAX,Tree[I][node].max);
            return;
      }
      SearchSmallTree(I,left,start,end);
      SearchSmallTree(I,right,start,end);
      return;
}

void SearchBigTree(int X1,int X2,int Y1,int Y2)
{
      int i;
      ANSMAX=-INF, ANSMIN=INF;
      for(i=X1;i<=X2;i++) SearchSmallTree(i,1,Y1,Y2);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x1,y1,x2,y2,z,blank=0,test=0;
	char q;
	while(scanf("%d %d",&m,&N)!=EOF)
	{
		for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%d",&grid[i][j]);
		BuildBigTree(0,N);
		scanf("%d\n",&l);
		for(i=0;i<l;i++)
		{
                  scanf("%c",&q);
                  if(q=='q')
                  {
                        scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);
                        SearchBigTree(x1-1,x2-1,y1-1,y2-1);
                        printf("%d %d\n",ANSMAX,ANSMIN);
                  }
                  else
                  {
                        scanf("%d %d %d\n",&x1,&y1,&z);
                        UpdateBigTree(x1-1,y1-1,z);
                  }
		}
	}
	return 0;
}
