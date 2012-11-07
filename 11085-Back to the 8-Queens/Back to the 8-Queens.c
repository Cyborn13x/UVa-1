#include <stdio.h>

int soln[100][8],row[8],col[8],d1[20],d2[20],top;

void BackTrack(int n)
{
      int i;
      if(n==8)
      {
            for(i=0;i<8;i++) soln[top][i]=col[i];
            top++;
            return;
      }
      for(i=0;i<8;i++)
      {
      	if(!row[i] && !d1[7+i-n] && !d2[i+n])
      	{
      	      row[i]=d1[7+i-n]=d2[i+n]=1;
      	      col[n]=i+1;
      	      BackTrack(n+1);
      	      row[i]=d1[7+i-n]=d2[i+n]=0;
      	}
      }
      return;
}

int main()
{
	int i,j,test=0,data[8],diff,min;
	BackTrack(0);
	while(scanf("%d",&data[0])!=EOF)
	{
		for(i=1;i<8;i++) scanf("%d",&data[i]);
            for(i=0,min=1000;i<top;i++)
            {
            	for(j=diff=0;j<8;j++) if(soln[i][j]!=data[j]) diff++;
            	if(diff<min) min=diff;
            }
            printf("Case %d: %d\n",++test,min);
	}
	return 0;
}
