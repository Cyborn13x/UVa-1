#include <stdio.h>

/*problem id-102
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank;
	long long int min,b1,b2,b3,g1,g2,g3,c1,c2,c3;
	char ans[5];
	while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)!=EOF)
	{
		min=b2+b3+g1+g2+c1+c3; strcpy(ans,"BCG");
		if(b2+b3+g1+g3+c1+c2<min) { min=b2+b3+g1+g3+c1+c2; strcpy(ans,"BGC"); }
		if(b1+b3+g1+g2+c3+c2<min) { min=b1+b3+g1+g2+c3+c2; strcpy(ans,"CBG"); }
		if(b2+b1+g1+g3+c3+c2<min) { min=b2+b1+g1+g3+c3+c2; strcpy(ans,"CGB"); }
		if(b1+b3+g2+g3+c1+c2<min) { min=b1+b3+g2+g3+c1+c2; strcpy(ans,"GBC"); }
		if(b2+b1+g2+g3+c1+c3<min) { min=b2+b1+g2+g3+c1+c3; strcpy(ans,"GCB"); }
		printf("%s %lld\n",ans,min);
	}
	return 0;
}
