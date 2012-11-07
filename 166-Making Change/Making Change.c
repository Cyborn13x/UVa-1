#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 10000000
#define ERROR 1e-9

/*problem id-166
 *
 *language-ANSI C
 *
 */

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
	int customer[105];
	int shopper[105];
	int freq[6];
	int doller;
	int min;
	double ammount;
	const int coin[]={1,2,4,10,20,40};
	for(i=0;i<105;i++) shopper[i]=INF;
	for(j=0,shopper[0]=0;j<6;j++)
	{
		for(i=0,x=coin[j];i<102-x;i++)
		{
			if(shopper[i]+1<shopper[i+x]) shopper[i+x]=shopper[i]+1;
		}
	}
      while(scanf("%d %d %d %d %d %d",&freq[0],&freq[1],&freq[2],&freq[3],&freq[4],&freq[5]))
      {
            if(!freq[0] && !freq[1] && !freq[2] && !freq[3] && !freq[4] && !freq[5]) break;
            scanf("%lf",&ammount);
            doller=(ammount*100)+ERROR;
            doller/=5;
            for(i=0;i<102;i++) customer[i]=INF;
            for(i=customer[0]=0;i<6;i++)
            {
            	for(j=0,x=coin[i];j<freq[i];j++)
            	{
            		for(k=102-x;k>=0;k--)
            		{
            			if(customer[k]+1<customer[k+x]) customer[k+x]=customer[k]+1;
            		}
            	}
            }
            for(i=doller,min=INF;i<101;i+=1)
            {
                  if(customer[i]+shopper[i-doller]<min)
                  {
                        min=customer[i]+shopper[i-doller];
                  }
            }
            printf("%3d\n",min);
      }
	return 0;
}
