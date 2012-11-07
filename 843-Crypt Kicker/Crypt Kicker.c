#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*problem id-843
 *
 *language-ANSI C
 *
 *
 */

int main()
{
      freopen("in.txt","r",stdin);//Don't know why with freopen it gets AC but without it gets RE.
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int x;
    int y;
    int flag;
    int word;
    int found;
    int vis[102];
    int key[200];
    int len[102];
    char *p;
    char line[100];
    char copy[100];
    char a[102][20];
    scanf("%d",&word);
    for(i=0;i<word;i++)
    {
        scanf("%s",a[i]);
        len[i]=strlen(a[i]);
    }getchar();
    while(gets(line)!=NULL)
    {
        memset(key,0,sizeof(key));
        memset(vis,0,sizeof(vis));
        strcpy(copy,line);flag=1;
    	p=strtok(line," ");
    	while(p!=NULL && flag)
    	{
    		x=strlen(p);
    		for(i=found=0;i<word && !found;i++)
    		{
    			if(x==len[i] && !vis[i])
    			{
    			    for(j=0;j<x && flag;j++)
    			    {
                        key[p[j]]==0 ? (key[p[j]]=a[i][j]) : (flag=(key[p[j]]==a[i][j]));
    			    }
    			    found=vis[i]=1;
    			}
    		}
    		p=strtok(NULL," ");
    	}
    	if(!flag) for(i=0;copy[i];i++) printf("%c",copy[i]==' ' ? ' ' : '*');
    	else for(i=0;copy[i];i++) printf("%c",copy[i]==' ' ? ' ' : key[copy[i]]);
    	printf("\n");
    }
    return 0;
}
