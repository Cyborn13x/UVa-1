#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-120
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,tmp,down,idx,blank=0,max,test=0,a[50],b[50];
	char line[200],*p;
	while(gets(line)!=NULL)
	{
	      n=0;
		p=strtok(line," ");
		while(p!=NULL)
		{
			a[n++]=atoi(p);
			p=strtok(NULL," ");
		}printf("%d",a[0]);
		for(i=1;i<n;i++) printf(" %d",a[i]);
		printf("\n");
		for(i=n-1;i>=0;i--)
		{
			max=a[i];
			idx=i;
			for(j=i-1;j>=0;j--) if(a[j]>max) { max=a[j], idx=j; }
			if(idx!=i)
			{
			      if(idx) printf("%d ",n-idx);
			      printf("%d ",n-i);
			      if(!idx)
			      {
			            for(j=0;j<(i+1)/2;j++) { tmp=a[i-j], a[i-j]=a[j], a[j]=tmp; }
			      }
			      else
			      {
			            for(j=0;j<(idx+1)/2;j++) { tmp=a[j], a[j]=a[idx-j], a[idx-j]=tmp; }
			            for(j=0;j<(i+1)/2;j++) { tmp=a[i-j], a[i-j]=a[j], a[j]=tmp; }
			      }
			}
		}printf("0\n");
	}
	return 0;
}
