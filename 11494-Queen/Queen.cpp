#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*11494
 *
 *
 *
 */
int main()
{
	int x1;
	int x2;
	int y1;
	int y2;
	int RowDiff;
	int ColDiff;
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)==4)
	{
	      if(!x1 && !y1 && !x2 && !y2) break;
	      RowDiff=fabs(x1-x2);
	      ColDiff=fabs(y1-y2);
	      if(RowDiff==ColDiff)
	      {
	            if(!RowDiff) printf("0");
	            else printf("1");
	      }
	      else
	      {
	            if(!RowDiff || !ColDiff) printf("1");
	            else printf("2");
	      }
	      printf("\n");
	}
	return 0;
}
