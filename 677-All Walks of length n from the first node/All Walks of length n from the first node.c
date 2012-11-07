#include <stdio.h>

/*problem id-677
 *
 *language-ANSI C
 *
 */

int vis[20],adj[20][20],len,N,ans[10],cnt;

void DFS(int n,int l)
{
      int i;
      if(l==len)
      {
            printf("(1");
            for(i=0,cnt=1;i<len;i++) printf(",%d",ans[i]+1);
            printf(")\n");
            return;
      }
      vis[n]=1;
      for(i=0;i<N;i++) if(!vis[i] && adj[n][i]) { ans[l]=i; DFS(i,l+1); }
      vis[n]=0;
      return;
}

int main()
{
      freopen("in.txt","r",stdin);
	int i,j,n,x,blank=0;
	while(scanf("%d %d",&N,&len)!=EOF)
	{
	      if(blank) printf("\n");
	      blank=1;
	      memset(adj,0,20*20*sizeof(int));
		for(i=cnt=0;i<N;i++) for(j=vis[i]=0;j<N;j++) scanf("%d",&adj[i][j]);
		DFS(0,0);
		if(!cnt) printf("no walk of length %d\n",len);
		scanf("%d",&n);
	}
	return 0;
}
