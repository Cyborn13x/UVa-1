#include <stdio.h>
#include <stdlib.h>

/*problem id-639
 *
 *language-ANSI C
 *
 */

const int a[]={1,-1,0,0}, b[]={0,0,1,-1};
int N,rook[4][4];
char grid[5][5];

int BackTrack(int R)
{
      int i,j,k,r,c,ret=R,mx;
      for(i=0;i<N;i++)
      {
      	for(j=0;j<N;j++)
      	{
      		if(!rook[i][j])
      		{
                        for(k=0,rook[i][j]=1;k<4;k++)
                        {
                              r=i+a[k], c=j+b[k];
                              while(r>=0 && r<N && c>=0 && c<N && rook[r][c]!=-1) rook[r][c]++, r+=a[k], c+=b[k];
                        }
                        mx=BackTrack(R+1);
                        if(mx>ret) ret=mx;
                        for(k=rook[i][j]=0;k<4;k++)
                        {
                              r=i+a[k], c=j+b[k];
                              while(r>=0 && r<N && c>=0 && c<N && rook[r][c]!=-1) rook[r][c]--, r+=a[k], c+=b[k];
                        }

      		}
      	}
      }
      return ret;
}

int main()
{
	int i,j;
	while(scanf("%d",&N) && N)
	{
	      memset(rook,0,16*sizeof(int));
		for(i=0;i<N;i++) scanf("%s",grid[i]);
		for(i=0;i<N;i++) for(j=0;j<N;j++) if(grid[i][j]=='X') rook[i][j]=-1;
		printf("%d\n",BackTrack(0));
	}
	return 0;
}
