#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*problem id-10361
 *
 *language-C++
 *
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
	char s[200];
	char s1[200];
	char s2[200];
	char s3[200];
	char s4[200];
	char s5[200];
	char s6[200];
	char c;
	scanf("%d",&t);
	scanf("%c",&c);
	while(t--)
	{
	      scanf("%[^\n]",s);
	      scanf("%c",&c);
		scanf("%[^\n]",s6);
		i=0;
		j=0;
		l=strlen(s1);
		while(s[i]!='<')
		{
		      s1[j]=s[i];
		      i++;
		      j++;
		}
            s1[j]='\0';
            i++;
            j=0;
            while(s[i]!='>')
		{
		      s2[j++]=s[i];
		      i++;
		}
            s2[j]='\0';
            i++;
            j=0;
            while(s[i]!='<')
		{
		      s3[j++]=s[i];
		      i++;
		}
            s3[j]='\0';
            i++;
            j=0;
            while(s[i]!='>')
		{
		      s4[j++]=s[i];
		      i++;
		}
            s4[j]='\0';
            i++;
            j=0;
            while(s[i]!='\0')
		{
		      s5[j++]=s[i];
		      i++;
		}
            s5[j]='\0';
		s6[strlen(s6)-3]='\0';
		scanf("%c",&c);
		printf("%s%s%s%s%s\n%s%s%s%s%s\n",s1,s2,s3,s4,s5,s6,s4,s3,s2,s5);
	}
	return 0;
}
