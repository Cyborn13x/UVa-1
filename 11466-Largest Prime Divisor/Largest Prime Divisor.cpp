#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11466
 *
 *language-C++
 *
 */

using namespace std;

#define N 10001000

bool prime[N];
long long int a[1000000];

int main()
{
	int i;
	long long int j;
	long long int k=0;
	long long int l;
	long long int m;
	long long int n;
	int t=N/2;
	a[0]=2;
	prime[0]=prime[1]=1;
	for(i=4;i<N;i+=2) prime[i]=1;
	for(i=3;i<=t;i+=2)
	{
	    if(!prime[i])
        {
            a[++k]=(long long)i;
            for(j=2*i;j<N;j+=i) prime[j]=1;
        }
    }
    l=k;
    while(cin >> n && n)
    {
    	if(n<0) n*=-1;
    	k=0;
    	for(i=0;i<=l && n>1 && a[i]<=n;i++)
    	{
    	    if(n%a[i]==0)
    	    {
                while(n>1 && n%a[i]==0)
                {
                    n/=a[i];
                }
                k++;
                j=a[i];
    	    }
    	}
    	if(n==1)
    	{
    	    if(k>1) printf("%lld\n",j);
    	    else printf("-1\n");
    	}
    	else
    	{
    	    if(k>0) printf("%lld\n",n);
    	    else printf("-1\n");
    	}
    }
	return 0;
}
