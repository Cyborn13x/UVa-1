#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10074
 *
 *language-ANSI C
 *
 */

int a[101][101];
int s[101][101];

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
	int w;
	int max;
	while(scanf("%d %d",&n,&m) && n && m)
	{
	      for(i=max=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&a[i][j]);
            for(i=0;i<n;i++)
            {
                  for(j=m-1,k=0;j>=0;j--)
                  {
                        if(!a[i][j]) k++;
                        else k=0;
                        s[i][j]=k;
                  }
            }
            for(i=0;i<n;i++)
            {
            	for(j=0;j<m;j++)
            	{
            		if(s[i][j])
            		{
            		      x=s[i][j];
            		      if(x>max) max=x;
            		      for(k=i+1,l=2;k<n;k++,l++)
            		      {
            		            if(s[k][j])
            		            {
                                          if(x>s[k][j]) x=s[k][j];
                                          if(x*l>max) max=x*l;
            		            }
            		            else break;
            		      }
            		}
            	}
            }
            printf("%d\n",max);
	}
      return 0;
}
