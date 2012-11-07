#include <stdio.h>

/*problem id-12157
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int k;
	int n;
	int t;
	int Mile;
	int Juice;
	int a[20];
	scanf("%d",&t); k=1;
	while(t--)
	{
		scanf("%d",&n);
		for(i=Mile=Juice=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) { Mile+=(a[i]/30+1)*10; Juice+=(a[i]/60+1)*15; }
		printf("Case %d: ",k++);
		if(Mile<Juice) printf("Mile %d\n",Mile);
		else if(Juice<Mile) printf("Juice %d\n",Juice);
		else printf("Mile Juice %d\n",Mile);
	}
	return 0;
}
