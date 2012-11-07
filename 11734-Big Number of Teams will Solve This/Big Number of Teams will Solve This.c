#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-11734
 *
 *language-ANSI C
 *
 *
 */


char team[10000];
char judge[10000];
char a[10000];
char b[10000];
int l1;
int l2;

int match()
{
      int i;
      int j;
      int k;
      int l;
      if(!strcmp(team,judge)) return 1;
      else
      {
            i=j=0;
            for(k=0;k<=l1;k++) if(team[k]!=' ') a[i++]=team[k];
            for(k=0;k<=l1;k++) if(judge[k]!=' ') b[j++]=judge[k];
            if(!strcmp(a,b)) return 3;
            else return 2;
      }
}

int main()
{
	int i;
	int j;
	int n;
	int t;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
            gets(team);
            gets(judge);
            l1=strlen(team);
            l2=strlen(judge);
            printf("Case %d: ",i+1);
		n=match();
		if(n==1) printf("Yes");
		else if(n==2) printf("Wrong Answer");
		else printf("Output Format Error");
		printf("\n");
	}
	return 0;
}
