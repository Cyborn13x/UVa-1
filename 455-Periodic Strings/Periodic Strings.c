#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int comp(char *a ,char *b)
{
      int i;
      for(i=0;b[i];i++) if(a[i]!=b[i]) return 1;
      return 0;
}

int Period(char * a)
{
      int i,j,l=strlen(a),flag,btop=0;
      char b[100];
      memset(b,0,l*sizeof(char));
      for(i=0;i<l;i++)
      {
      	b[btop++]=a[i];
      	for(j=flag=0;j<l;j+=i+1) if(comp(a+j,b)==1) flag=1;
      	if(!flag) return i+1;
      }
      return l;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[100];
	scanf("%d",&t);
	while(t--)
	{
	      if(blank) putchar('\n');
	      blank=1;
		scanf("%s",a);
		printf("%d\n",Period(a));
	}
	return 0;
}
