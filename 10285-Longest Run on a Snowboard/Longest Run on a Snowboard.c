#include<stdio.h>

/*problem id-10285
 *
 *language-ANSI C
 *
 */

const int a[]={1,-1,0,0}, b[]={0,0,1,-1};
int grid[100][100],data[100][100],max,R,C;

int BackTrack(int x,int y)
{
    int i,r,c,tmp,mx=0,flag=0;
    if(data[x][y]) return data[x][y];
    for(i=0;i<4;i++)
    {
        r=x+a[i], c=y+b[i];
    	if(grid[x][y]>grid[r][c] && r>=0 && r<R && c>=0 && c<C)
    	{
    	    tmp=1+BackTrack(r,c);
    	    if(tmp>mx) mx=tmp;
    	    flag=1;
    	}
    }
    if(!flag) return data[x][y]=1;
    data[x][y]=mx;
    if(mx>max) max=mx;
    return mx;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,test=0,blank=0;
	char name[500];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d %d",name,&R,&C);
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
			    data[i][j]=0;
				scanf("%d",&grid[i][j]);
			}
		}
		for(i=0,max=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				if(!data[i][j])
				{
				    x=BackTrack(i,j);
				    if(x>max) max=x;
				}
			}
		}
		printf("%s: %d\n",name,max);
	}
	return 0;
}
