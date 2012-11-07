#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int r;
int c;
int x[]={1,1,1,0,0,-1,-1,-1};
int y[]={-1,0,1,1,-1,1,0,-1};
char a[150][150];

int find(int i,int j)
{
      int k;
      int row;
      int col;
      a[i][j]=48;
      for(k=0;k<8;k++)
      {
      	row=i+x[k];
      	col=j+y[k];
      	if(row>=0 && row<r && col>=0 && col<c && a[row][col]=='*')
      	{
      	      a[i][j]++;
      	}
      }
      return;
}
int main()
{
	int i;
	int j;
	int g=0;
	int l=0;
	scanf("%d %d",&r,&c);
	while(r||c)
	{
	      if(g)
	      {
	            printf("\n");
	      }
		for(i=0;i<r;i++)
		{
			scanf("%s",a[i]);
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(a[i][j]=='.')
				{
				      find(i,j);
				}
			}
		}
		printf("Field #%d:\n",++g);
		for(i=0;i<r;i++)
		{
			printf("%s\n",a[i]);
		}
		scanf("%d %d",&r,&c);
	}
	return 0;
}
