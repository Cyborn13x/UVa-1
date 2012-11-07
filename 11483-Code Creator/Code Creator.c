#include <stdio.h>
#include <string.h>

/*problem id-11483
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,flag;
      char a[105];
      while(scanf("%d",&n) && n)
      {
            getchar();
            printf("Case %d:\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n",++test);
      	for(i=0;i<n;i++)
      	{
      		gets(a);
      		if(!a[0]) { i--; continue; }
      		printf("printf(\"");
      		for(j=0;a[j];j++)
      		{
      			if(a[j]=='"') printf("\\%c",a[j]);
      			else if(a[j]=='\\') printf("\\%c",a[j]);
      			else printf("%c",a[j]);
      		}
      		printf("\\n\");\n");
      	}
      	printf("printf(\"\\n\");\nreturn 0;\n}\n");
      }
	return 0;
}
