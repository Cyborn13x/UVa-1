#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>

/*problem id-855
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int r;
	int c;
	int x;
	int y;
	int a[50000];
	int b[50000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&r,&c,&n);
		for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		printf("(Street: %d, Avenue: %d)\n",n%2==0 ? a[(n-1)/2]:a[n/2],n%2==0 ? b[(n-1)/2]:b[n/2]);
	}
	return 0;
}
