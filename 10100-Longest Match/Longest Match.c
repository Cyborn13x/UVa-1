#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problemid-10100
 *
 *language-ANSI C
 *
 */

int lcs[1005][1005];

int max(int a,int b) { return a>b ? a : b; }

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
	char tmp[50];
      char line1[1015];
      char line2[1015];
      char a[1005][25];
      char b[1005][25]; t=1;
      while(gets(line1)!=NULL)
      {
      	gets(line2);
      	if(!strlen(line1) || !strlen(line2)) { printf("%2d. Blank!\n",t++); continue; }
      	for(i=x=y=0;line1[i];i++)
      	{
      		if(isalpha(line1[i]) || isdigit(line1[i]))
      		{
      		      l=0;
      		      while(isalpha(line1[i]) || isdigit(line1[i])) tmp[l++]=line1[i++];
      		      tmp[l]=0;
      		      strcpy(a[x++],tmp);
      		}
      	}
      	for(i=0;line2[i];i++)
      	{
      		if(isalpha(line2[i]) || isdigit(line2[i]))
      		{
      		      l=0;
      		      while(isalpha(line2[i]) || isdigit(line2[i])) tmp[l++]=line2[i++];
      		      tmp[l]=0;
      		      strcpy(b[y++],tmp);
      		}
      	}
      	for(i=0;i<505;i++) lcs[i][0]=lcs[0][i]=0;
      	for(i=1;i<=x;i++)
      	{
      		for(j=1;j<=y;j++)
      		{
      			if(!strcmp(a[i-1],b[j-1])) lcs[i][j]=lcs[i-1][j-1]+1;
      			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
      		}
      	}
            printf("%2d. Length of longest match: %d\n",t++,lcs[x][y]);

      }
	return 0;
}
