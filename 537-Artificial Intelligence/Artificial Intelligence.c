#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-537
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	double v1;
	double v2;
	double v3;
	int flag=0;
	char s[1000];
	char s1[10];
	char s2[10];
	char a;
	char b;
	scanf("%d",&t);
	getchar();
	k=1;
	while(t--)
	{
		gets(s);
		i=0;
		while(s[i++]!='=');
		a=s[i-2];x=0;
		for(m=i-2;isalpha(s[m]) || isdigit(s[m]) || s[m]=='=' || s[m]=='.';m++) s1[x++]=s[m];
		s1[x]=0;while(!isalpha(s1[--x])) s1[x]=0;
		sscanf(s1,"%*c=%lf",&v1);
		l=strlen(s1);
		if(isalpha(s1[l-2]))
		{
		    if(s1[l-2]=='m') v1/=1000.00;
		    else if(s1[l-2]=='M') v1*=1000000.00;
		    else if(s1[l-2]=='k') v1*=1000.00;
		}
		j=i+1;
		while(s[j++]!='=');
		b=s[j-2];x=0;
		for(m=j-2;isalpha(s[m]) || isdigit(s[m]) || s[m]=='=' || s[m]=='.';m++) s2[x++]=s[m];
		s2[x]=0;while(!isalpha(s2[--x])) s2[x]=0;
		sscanf(s2,"%*c=%lf",&v2);
		l=strlen(s2);
		if(isalpha(s2[l-2]))
		{
		    if(s2[l-2]=='m') v2/=1000.00;
		    else if(s2[l-2]=='M') v2*=1000000.00;
		    else if(s2[l-2]=='k') v2*=1000.00;
		}
		printf("Problem #%d\n",k++);
		if((a=='I'||b=='I') && (a=='U'||b=='U'))
		{
		    v3=v1*v2;
		    printf("P=%.2lfW\n",v3);
		}
		else if(a=='P' && b=='U')
		{
		    v3=v1/v2;
		    printf("I=%.2lfA\n",v3);
		}
		else if(a=='U' && b=='P')
		{
		    v3=v2/v1;
		    printf("I=%.2lfA\n",v3);
		}
		else if(a=='P' && b=='I')
		{
		    v3=v1/v2;
		    printf("U=%.2lfV\n",v3);
		}
		else if(a=='I' && b=='P')
		{
		    v3=v2/v1;
		    printf("U=%.2lfV\n",v3);
		}
		printf("\n");
	}
	return 0;
}
