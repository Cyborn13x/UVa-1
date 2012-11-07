#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 30

/*problem id-836
 *
 *language-ANSI C
 *
 */

int mat[SZ][SZ],one[SZ][SZ];

int min(int a,int b) { return a<b ? a : b; }

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,max,tmp,lim;
	char a[50];
	scanf("%d\n",&t);
	gets(a);
	while(t--)
	{
	      if(blank) putchar('\n');
		for(n=blank=1,max=0;gets(a)!=NULL && a[0];n++)
		{
		      if(n==1) m=strlen(a);
		      for(i=1;a[i-1];i++) mat[n][i]=a[i-1]-'0';
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{
				one[i][j]=mat[i][j]+one[i-1][j]+one[i][j-1]-one[i-1][j-1];
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{
			      if(mat[i][j])
				{
				      for(k=i,lim=m;k<n;k++)
                              {
                                    for(l=j;l<=lim;l++)
                                    {
                                         if(!mat[k][l]) break;
                                         tmp=one[k][l]-one[i-1][l]-one[k][j-1]+one[i-1][j-1];
                                         if(tmp>max) max=tmp;
                                    }
                                    lim=min(m,l-1);
                                    if(l==j) break;
                              }
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
