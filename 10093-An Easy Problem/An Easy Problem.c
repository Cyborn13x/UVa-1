#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int data[150];

void copy(char *a,char *b)
{
      int i,j;
      for(i=j=0;a[i];i++) if(isdigit(a[i]) || isalpha(a[i])) b[j++]=a[i];
      b[j]=0;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,max,mx,sum,blank=0,test=0;
      char a[10000],b[10000];
      for(i='0',x=0;i<='9';i++,x++) data[i]=x;
      for(i='A';i<='Z';i++,x++) data[i]=x;
      for(i='a';i<='z';i++,x++) data[i]=x;
      while(scanf("%s",b)!=EOF)
      {
      	copy(b,a);
      	for(i=0,mx=-100;a[i];i++) if(a[i]>mx) max=data[a[i]], mx=a[i];
      	for(i=sum=0;a[i];i++) sum+=data[a[i]];
      	if(max<=1)
      	{
      	      printf("2\n");
      	      continue;
      	}
      	for(i=max;i<62;i++) if(!(sum%i)) break;
      	if(i<62) printf("%d\n",i+1);
      	else printf("such number is impossible!\n");
      }
	return 0;
}
