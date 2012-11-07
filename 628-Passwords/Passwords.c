#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-628
 *
 *language-ANSI C
 *
 */

int n,m,len;
char name[101][260],rule[101][260],res[65540];

void BackTrack(char *rl,int pos)
{
      int i,t;
      if(!rl[pos]) printf("%s\n",res);
      else if(rl[pos]=='#')
      {
            for(i=0;i<n;i++)
            {
                  strcat(res,name[i]);
                  len+=t=strlen(name[i]);
                  BackTrack(rl,pos+1);
                  res[len-=t]=0;
            }
      }
      else if(rl[pos]=='0')
      {
            for(i=0;i<10;i++)
            {
                  res[len++]=i+'0';
                  res[len]=0;
                  BackTrack(rl,pos+1);
                  len--;
            }
      }
      return;
}

int main()
{
	int i,j,k,l,t,x,y,blank,test=0;
	while(scanf("%d",&n)!=EOF)
	{
	      printf("--\n");
            for(i=0;i<n;i++) scanf("%s",name[i]);
            scanf("%d",&m);
            for(i=0;i<m;i++) scanf("%s",rule[i]);
            for(i=0;i<m;i++) BackTrack(rule[i],res[0]=len=0);
	}
	return 0;
}
