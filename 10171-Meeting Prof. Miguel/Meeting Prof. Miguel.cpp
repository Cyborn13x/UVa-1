#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 10000000

/*problem id-10171
 *
 *language-ANSI C
 *
 */

int min(int a,int b) { return a<b ? a : b; }

int main()
{
	int i,j,k,l,m,n,t,x,y,floyda[26][26],floydb[26][26],sum,best,top;
      char ans[30],age,dir,st,en,src,trg;
      while(scanf("%d\n",&m) && m)
      {
            for(i=0;i<26;i++)
            {
                  for(j=i+1;j<26;j++)
                  {
                        floyda[i][j]=floyda[j][i]=INF;
                        floydb[i][j]=floydb[j][i]=INF;
                  }floyda[i][i]=floydb[i][i]=0;
            }
      	for(i=0;i<m;i++)
      	{
      		scanf("%c %c %c %c %d",&age,&dir,&st,&en,&l); getchar();
      		if(dir=='B')
      		{
      		      if(age=='Y')
      		      {
      		            floyda[st-'A'][en-'A']=min(l,floyda[st-'A'][en-'A']);
      		            floyda[en-'A'][st-'A']=min(l,floyda[en-'A'][st-'A']);
      		      }
      		      else
      		      {
      		            floydb[st-'A'][en-'A']=min(l,floydb[st-'A'][en-'A']);
      		            floydb[en-'A'][st-'A']=min(l,floydb[en-'A'][st-'A']);
      		      }
      		}
      		else
      		{
      		      if(age=='Y') floyda[st-'A'][en-'A']=min(l,floyda[st-'A'][en-'A']);
      		      else floydb[st-'A'][en-'A']=min(l,floydb[st-'A'][en-'A']);
      		}
      	}
      	scanf("%c %c",&src,&trg);
      	for(k=0;k<26;k++)
      	{
      		for(i=0;i<26;i++)
      		{
      			for(j=0;j<26;j++)
      			{
                              if(floyda[i][k]+floyda[k][j]<floyda[i][j])
                              {
                                    floyda[i][j]=floyda[i][k]+floyda[k][j];
      				}
      				if(floydb[i][k]+floydb[k][j]<floydb[i][j])
                              {
                                    floydb[i][j]=floydb[i][k]+floydb[k][j];
      				}
      			}
      		}
      	}
      	for(i=0,best=INF,top=0;i<26;i++)
      	{
      	      sum=floyda[src-'A'][i]+floydb[trg-'A'][i];
      		if(sum<best) best=sum, top=0;
      		if(sum==best) ans[top++]=i+'A';
      	}
      	if(best==INF) printf("You will never meet.\n");
      	else
      	{
      	      printf("%d",best);
      	      for(i=0;i<top;i++) printf(" %c",ans[i]);
      	      printf("\n");
      	}
      }
	return 0;
}
