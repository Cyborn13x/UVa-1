#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-598
 *
 *language-ANSI C
 *
 */

int start,end,top,level,last,ans[15];
char name[15][35];

void BackTrack(int n,int lev)
{
      int i;
      if(lev==level)
      {
            printf("%s",name[ans[0]]);
            for(i=1;i<last;i++) printf(", %s",name[ans[i]]);
            printf("\n");
            return;
      }
      for(i=n;i<top;i++)
      {
            ans[last++]=i;
            BackTrack(i+1,lev+1);
            last--;
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[10];
      scanf("%d",&t);
      gets(a);
      gets(a);
      while(t--)
      {
            if(blank) putchar('\n');
            blank=1;
            gets(a); top=0;
            m=sscanf(a,"%d %d",&start,&end);
            while(gets(name[top])!=NULL && name[top][0]) top++;
            if(!m) start=1,end=top;
            else if(m==1) end=start;
            for(i=start;(level=i)<=end;i++)
            {
                  printf("Size %d\n",i);
            	BackTrack(0,last=0);
            	putchar('\n');
            }
      }
	return 0;
}
