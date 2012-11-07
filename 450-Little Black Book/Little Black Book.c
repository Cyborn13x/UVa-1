#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 10000
#define SZ 200

/*problem id-450
 *
 *language-ANSI C
 *
 */

typedef struct
{
      char dept[SZ],title[SZ],FirstName[SZ],LastName[SZ],addr[SZ],home[SZ],work[SZ],campus[SZ];
}node;

node list[N];
char line[N],dot[]="----------------------------------------";

int cmp(const void *p1,const void *p2)
{
      node *a=(node *)p1, *b=(node *)p2;
      return strcmp((*a).LastName,(*b).LastName);
}

int main()
{
	int i,j,k,l,m,n,t,x=0,y,blank=0,test=0;
	char dpt[N],*p;
	node tmp;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		gets(dpt);
		while(gets(line) && line[0])
		{
			p=strtok(line,",");
			strcpy(tmp.title,p);
			p=strtok(NULL,",");
			strcpy(tmp.FirstName,p);
			p=strtok(NULL,",");
			strcpy(tmp.LastName,p);
			p=strtok(NULL,",");
			strcpy(tmp.addr,p);
			p=strtok(NULL,",");
			strcpy(tmp.home,p);
			p=strtok(NULL,",");
			strcpy(tmp.work,p);
			p=strtok(NULL,",");
			strcpy(tmp.campus,p);
			strcpy(tmp.dept,dpt);
			list[x++]=tmp;
		}
	}
	qsort(list,x,sizeof(node),&cmp);
	for(i=0;i<x;i++)
	{
		puts(dot);
		printf("%s %s %s\n",list[i].title,list[i].FirstName,list[i].LastName);
		puts(list[i].addr);
		printf("Department: %s\n",list[i].dept);
		printf("Home Phone: %s\n",list[i].home);
		printf("Work Phone: %s\n",list[i].work);
		printf("Campus Box: %s\n",list[i].campus);
	}
	return 0;
}
