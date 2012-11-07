#include <stdio.h>

#define INF 1<<30
#define SZ 1000002
#define ll long long int

/*problem id-11136
 *
 *language-ANSI C
 *
 */

int freq[SZ];

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,min,max;
	ll total;
	while(scanf("%d",&n) && n)
	{
		max=-(min=INF), m=0, total=0;
		memset(freq,0,SZ*sizeof(int));
		while(n--)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&x);
				if(x>max) max=x;
				if(x<min) min=x;
				freq[x]++, m++;
			}
			total+=max-min, m-=2, freq[max]--, freq[min]--;
			if(freq[max]<0) freq[max]=0;
			if(freq[min]<0) freq[min]=0;
			if(!freq[max]) while(!freq[max] && max>=min) max--;
			if(!freq[min]) while(!freq[min] && min<=max) min++;
			if(!m) max=-(min=INF);
		}
		printf("%lld\n",total);
	}
	return 0;
}
