#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ll long long int

/*problem id-489
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,f[200],flag,plus,minus;
	char a[100],b[100];
	while(scanf("%d",&test) && test!=-1)
	{
		scanf("%s %s",a,b);
		memset(f,0,sizeof(f));
		for(i=plus=minus=0,x=strlen(a),y=strlen(b);i<y;i++)
		{
			if(plus==x || minus==7) break;
			for(j=flag=0;j<x && !f[b[i]];j++) if(b[i]==a[j]) flag=1, plus++;
			if(!flag) minus++;
			else f[b[i]]=1;
		}
		printf("Round %d\n",test);
            if(plus==x) printf("You win.\n");
            else if(minus==7) printf("You lose.\n");
            else printf("You chickened out.\n");
	}
	return 0;
}
