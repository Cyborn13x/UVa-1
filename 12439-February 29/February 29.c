#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000

/*problem id-12439
 *
 *language-ANSI C
 *
 */

char data[][20]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int IsLeap(int y) { return (y%4==0 && y%100!=0) || y%400==0; }

int LeapYear(char *a1,int d1,int y1,char *a2,int d2,int y2)
{
      int i,j,x=y1/4-y1/100+y1/400,y=(y2-1)/4-(y2-1)/100+(y2-1)/400,ret=y-x;
      for(i=0;i<12;i++) if(!strcmp(a1,data[i])) break;
      for(j=0;j<12;j++) if(!strcmp(a2,data[j])) break;
      if(i<2 && IsLeap(y1)) ret++;
      if((j>1 || (j==1 && d2>=29)) && IsLeap(y2)) ret++;
      return ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,day1,day2,year1,year2,blank=0,test=0;
	char a[50],b[50],month1[20],month2[20];
	scanf("%d\n",&t);
	while(t--)
	{
		gets(a);
		gets(b);
		sscanf(a,"%s %d, %d",month1,&day1,&year1);
		sscanf(b,"%s %d, %d",month2,&day2,&year2);
		printf("Case %d: %d\n",++test,LeapYear(month1,day1,year1,month2,day2,year2));
	}
	return 0;
}
