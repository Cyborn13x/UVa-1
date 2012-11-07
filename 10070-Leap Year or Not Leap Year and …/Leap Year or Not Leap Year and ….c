#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-10070
 *
 *language-ANSI C
 *
 *
 */

char a[100000];
int l;

int div4()
{
      return ((10*(a[l-2]-'0')+(a[l-1]-'0'))%4==0 ? 1:0);
}

int div100()
{
      return ((a[l-1]=='0' && a[l-2]=='0') ? 1:0);
}

int div5()
{
      return ((a[l-1]=='0' || a[l-1]=='5') ? 1:0);
}

int div3()
{
      int i;
      int s=0;
      for(i=0;i<l;i++) s+=a[i]-'0';
      return (s%3==0 ? 1:0);
}

int div11()
{
      int i;
      int odd=0;
      int even=0;
      for(i=0;i<l;i+=2) odd+=a[i]-'0';
      for(i=1;i<l;i+=2) even+=a[i]-'0';
      return ((odd-even)%11==0 ? 1:0);
}


int main()
{
	int i;
	int j;
	int n=0;
	int d4;
	int d15;
	int d55;
	int d100;
	int d400;
	int leap;
	int hulu;
	int bulu;
	int flag;
	while(scanf("%s",a)==1)
	{
	      if(n)
	      {
	            printf("\n");
	      }
	      n=1;
	      leap=hulu=bulu=0;
            l=strlen(a);
            d4=d100=d400=d15=d55=flag=0;
            for(i=0;i<l;i++)
            {
                  d4=((10*d4)+(a[i]-'0'))%4;
                  d100=((10*d100)+(a[i]-'0'))%100;
                  d400=((10*d400)+(a[i]-'0'))%400;
                  d15=((10*d15)+(a[i]-'0'))%15;
                  d55=((10*d55)+(a[i]-'0'))%55;
            }
            if((!d4 && d100) || !d400)
            {
                  leap=1;
            }
            if(!d15)
            {
                  hulu=1;
            }
            if(!d55)
            {
                  bulu=1;
            }
            if(leap==1)
            {
                  printf("This is leap year.\n");
                  flag=1;
            }
            if(hulu==1)
            {
                  flag=1;
                  printf("This is huluculu festival year.\n");
            }
            if(bulu==1 && leap==1)
            {
                  printf("This is bulukulu festival year.\n");
            }
            if(flag==0)
            {
                  printf("This is an ordinary year.\n");
            }
	}
	return 0;
}
