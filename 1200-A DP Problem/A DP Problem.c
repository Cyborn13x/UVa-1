#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*problem id-1200
 *
 *language-ANSI C
 *
 */

int a1,a2,b1,b2;

int found(char *p,int n,int *cf)
{
      int i,val=0;
      for(i=n;isdigit(p[i]);i++) val=10*val+(p[i]-'0');
      *cf=val;
      return p[i]=='x';
}

void data(int *a,int *b,char *p)
{
      int i,m,n,x=0,c=0,sign=0,coeff=1;
      for(i=0;p[i];)
      {
      	if(p[i]!='+' && p[i]!='-')
      	{
      	      if(p[i]=='x') x += sign ? -1 : 1;
      	      else found(p,i,&coeff) ? (x += sign ? -coeff : coeff) : (c += sign ? -coeff : coeff);
      	      while(p[i]!='+' && p[i]!='-' && p[i]) i++;
      	}
      	else { sign = p[i]=='+' ? 0 : 1; i++; }
      }
      *a=x; *b=c;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,ans,rem,test=0,blank=0;
	char a[5000],*p;
	scanf("%d",&t);
      while(t--)
	{
		scanf("%s",a);
		p=strtok(a,"=");
		data(&a1,&b1,p);
		p=strtok(NULL,"=");
		data(&a2,&b2,p);
		x=a1-a2; y=b2-b1;
		if(!x)
		{
		      if(b1==b2) printf("IDENTITY\n");
		      else printf("IMPOSSIBLE\n");
		}
		else
		{
		      if(x>0 && y>=0) printf("%d\n",y/x);
		      else if(x<0 && y<=0) printf("%d\n"-(y/x));
		      else
		      {
		            if(y<0) y=-y;
		            else x=-x;
		            if((rem=y%x)) ans=-1;
		            else ans=0;
		            printf("%d\n",-(y/x)+ans);
		      }
		}
	}
	return 0;
}
