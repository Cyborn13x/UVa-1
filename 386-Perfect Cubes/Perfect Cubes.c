#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-386
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,a,b,c,d,left,sum,s1,s2,s3,test,blank;
	for(k=2;k<201;k++)
	{
	      left=k*k*k;
		for(l=2;l<201;l++)
		{
		      s1=l*l*l;
			for(i=l;i<201;i++)
			{
			      s2=i*i*i;
			      if(s1+s2>left) break;
				for(j=i;j<201;j++)
				{
					s3=j*j*j;
					sum=s1+s2+s3;
					if(sum>left) break;
					else if(sum==left) printf("Cube = %d, Triple = (%d,%d,%d)\n",k,l,i,j);
				}
			}
		}
	}
	return 0;
}
