#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10894
 *
 *language-ANSI C
 *
 */

char data[10][5][5]={{"*****","*....","*****","....*","*****"},
                     {".***.","*...*","*****","*...*","*...*"},
                     {"*...*","*...*","*...*",".*.*.","..*.."},
                     {"*****","*....","***..","*....","*****"},
                     {"*...*","*...*","*****","*...*","*...*"},
                     {"*****","*...*","*****","*.*..","*..**"},
                     {"*****","..*..","..*..","..*..","*****"},
                     {"***..","*..*.","*...*","*..*.","***.."},
                     {"*****","*...*","*...*","*...*","*****"},
                     {"*...*",".*.*.","..*..","..*..","..*.."}};

void Vertical(int n)
{
      int i,j,k,l,x,y,z,a,dot;
      for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
		      for(a=0;a<n;a++)
			{
			      for(k=0;k<5;k++)
			      {
			            for(l=0;l<n;l++) putchar(data[i][j][k]);
			      }putchar('\n');
			}
		}
		dot=n*(i==3 ? 3 : 1)*(i!=9);
		for(x=0;x<dot;x++)
		{
			for(y=0;y<5*n;y++) putchar('.');
                  putchar('\n');
		}
	}printf("\n\n");
	return;
}

void Horizontal(int n)
{
      int i,j,k,l,x,y,dot;
      for(i=0;i<5*n;i++)
      {
      	for(j=0;j<10;j++)
      	{
      		for(k=0;k<5;k++)
      		{
      			for(l=0;l<n;l++) putchar(data[j][i/n][k]);
      		}
      		dot=n*(j==3 ? 3 : 1)*(j!=9);
      		for(l=0;l<dot;l++) putchar('.');
      	}putchar('\n');
      }printf("\n\n");
      return;
}

int main()
{
      freopen("ot.txt","w",stdout);
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d",&n) && n) n<0 ? Vertical(-n) : Horizontal(n);
	return 0;
}
