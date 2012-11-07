#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-750
 *
 *language-ANSI C
 *
 */

int top,cnt,fixedrow,fixedcol,row[10],column[10],diagonal1[20],diagonal2[20],solution[100][10];

void DFS(int n)
{
      int i;
      if(n==9)
      {
            for(i=1;i<=8;i++) solution[top][i]=column[i];
            top++;
            return;
      }
      if(n==fixedcol) { DFS(n+1); return; }
      for(i=1;i<=8;i++)
      {
      	if(!row[i] && !diagonal1[8+i-n] && !diagonal2[i+n])
      	{
      	      column[n]=i;
      	      row[i]=diagonal1[8+i-n]=diagonal2[i+n]=1;
      	      DFS(n+1);
      	      row[i]=diagonal1[8+i-n]=diagonal2[i+n]=0;
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0;
      scanf("%d",&t);
      while(t--)
      {
            if(blank) printf("\n"); blank=1;
            memset(row,0,sizeof(row));
            memset(column,0,sizeof(column));
            memset(diagonal1,0,sizeof(diagonal1));
            memset(diagonal2,0,sizeof(diagonal2));
      	scanf("%d %d",&fixedrow,&fixedcol);
      	column[fixedcol]=fixedrow; top=0;
      	diagonal1[8+fixedrow-fixedcol]=diagonal2[fixedrow+fixedcol]=row[fixedrow]=1;
      	DFS(1);
      	printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
      	for(i=0;i<top;i++)
      	{
      	      printf("%2d     ",i+1);
      		for(j=1;j<=8;j++) printf(" %d",solution[i][j]);
      		printf("\n");
      	}
      }
	return 0;
}
