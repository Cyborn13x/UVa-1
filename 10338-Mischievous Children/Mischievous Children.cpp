#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10338
 *
 *
 *language-ANSI C
 *
 */
int main()
{
	int i;
	int j;
	int n;
	int t;
	int l;
	int rep[26];
	int h[26];
	unsigned long long f[21];
	unsigned long long ans;
	char a[22];
	f[0]=1;
	f[1]=1;
	f[2]=2;
	for(i=3;i<21;i++) f[i]=f[i-1]*i;
	scanf("%d",&t);
	getchar();
	for(n=0;n<t;n++)
	{
            gets(a);
            l=strlen(a);
            ans=f[l];
            for(i=0;i<26;i++) rep[i]=h[i]=0;
            for(i=0;i<l;i++) rep[a[i]-'A']++;
            for(i=0;i<26;i++) h[rep[i]]++;
            for(i=2;i<21;i++) for(j=0;j<h[i];j++) ans/=f[i];
            printf("Data set %d: %llu\n",n+1,ans);
	}
	return 0;
}
