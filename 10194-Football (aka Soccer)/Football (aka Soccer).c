#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ll long long int

/*problem id-10194
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int points,GmPlayed,wins,ties,losses,GlDiff,GlScored,GlAgainst;
      char name[35];
}team;

int cmp(const void *p1,const void *p2)
{
      int i;
      team a=*((team *)p1), b=*((team *)p2);
      if(a.points!=b.points) return b.points-a.points;
      if(a.wins!=b.wins) return b.wins-a.wins;
      if(a.GlDiff!=b.GlDiff) return b.GlDiff-a.GlDiff;
      if(a.GlScored!=b.GlScored) return b.GlScored-a.GlScored;
      if(a.GmPlayed!=b.GmPlayed) return a.GmPlayed-b.GmPlayed;
      return strcasecmp(a.name,b.name);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,game,g1,g2;
      char Tournament[120],t1[35],t2[35],tmp[100],*p;
      team list[32];
      scanf("%d%*c",&t);
      while(t--)
      {
            if(blank) putchar('\n'); blank=1;
      	gets(Tournament);
      	scanf("%d%*c",&n);
      	for(i=0;i<n;i++)
      	{
      		strcpy(list[i].name,"");
      		list[i].points=list[i].GmPlayed=list[i].wins=list[i].ties=list[i].losses=list[i].GlDiff=list[i].GlScored=list[i].GlAgainst=0;
      	}
      	for(i=0;i<n;i++) gets(list[i].name);
      	scanf("%d%*c",&game);
      	while(game--)
      	{
      		gets(tmp);
      		p=strtok(tmp,"#");
      		strcpy(t1,p);
      		p=strtok(NULL,"@");
      		g1=atoi(p);
      		p=strtok(NULL,"#");
      		g2=atoi(p);
      		p=strtok(NULL,"\0");
      		strcpy(t2,p);
      		if(g1>g2) x=3, y=0;
      		else if(g1<g2) x=0, y=3;
      		else x=y=1;
      		for(i=0;i<n;i++)
      		{
      		      if(!strcmp(list[i].name,t1))
      		      {
      		            list[i].points+=x, list[i].wins+=(g1>g2), list[i].losses+=(g2>g1), list[i].ties+=(g1==g2);
      		            list[i].GlScored+=g1, list[i].GlAgainst+=g2;
      		            list[i].GmPlayed++;
      		            break;
                        }
      		}
      		for(i=0;i<n;i++)
      		{
      		      if(!strcmp(list[i].name,t2))
      		      {
      		            list[i].points+=y, list[i].wins+=(g2>g1), list[i].losses+=(g1>g2), list[i].ties+=(g1==g2);
      		            list[i].GlScored+=g2, list[i].GlAgainst+=g1;
      		            list[i].GmPlayed++;
      		            break;
                        }
      		}
      	}
      	for(i=0;i<n;i++) list[i].GlDiff=list[i].GlScored-list[i].GlAgainst;
      	qsort(list,n,sizeof(team),&cmp);
      	puts(Tournament);
      	for(i=0;i<n;i++)
      	{
      		printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,list[i].name,list[i].points,list[i].GmPlayed,list[i].wins,list[i].ties,list[i].losses,list[i].GlDiff,list[i].GlScored,list[i].GlAgainst);
      	}
      }
	return 0;
}
