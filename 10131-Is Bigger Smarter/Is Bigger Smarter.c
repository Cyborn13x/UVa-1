#include <stdio.h>
#include <stdlib.h>

/*problem id-10131
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int w,q,n;
}elephant;

int top;
elephant a[1002];

int cmp(const void *p1,const void *p2)
{
      elephant *a=(elephant *)p1,*b=(elephant *)p2;
      if(a->q<b->q) return 1;
      else return -1;
}

int main()
{
	int i,j,k,m,n,t,x=0,y,lis=0,blank,start,test=0,ans[1002],l[1002],p[1002];
	while(scanf("%d %d",&a[top].w,&a[top].q)!=EOF) a[top].n=top+1, top++;
	qsort(a,top,sizeof(elephant),&cmp);
	for(i=0;i<top;i++) l[i]=1, p[i]=-1;
	for(i=1;i<top;i++)
	{
		for(j=0;j<i;j++)
		{
                  if(a[i].w>a[j].w && l[j]+1>l[i])
                  {
                        l[i]=l[j]+1;
                        p[i]=j;
                  }
		}
	}
	for(i=lis=x=0;i<top;i++)
	{
		if(l[i]>lis)
		{
		      lis=l[i];
		      start=i;
		}
	}
	while(start!=-1)
	{
		ans[x++]=a[start].n;
		start=p[start];
	}
	printf("%d\n",x);
	for(i=x-1;i>=0;i--) printf("%d\n",ans[i]);
	return 0;
}
