#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

/*problem id-452
 *
 *language-C++
 *
 */

using namespace std;

int dis[26],total,mx;
bool used[26],vis[26],top[26];
vector<int> AdjList[26],TopoSort;

void TopoDFS(int n)
{
    if(vis[n]) return;
    vis[n]=1;
    for(int i=0,l=AdjList[n].size();i<l;i++) TopoDFS(AdjList[n][i]);
    TopoSort.push_back(n);
    return;
}

void DFS(int n)
{
    total+=dis[n];
    if(total>mx) mx=total;
    for(int i=0,l=AdjList[n].size();i<l;i++)
    {
    	DFS(AdjList[n][i]);
    	total-=dis[AdjList[n][i]];
    }
    return;
}

int main()
{
    int i,j,k,l,m,n,x,y,t,test=0,blank=0;
    char b[100],a[100],c,*p;
    scanf("%d",&t);
    gets(a);
    gets(a);
    while(t--)
    {
        if(blank) printf("\n");
        blank=1;
        for(i=0;i<26;i++) AdjList[i].clear(), dis[i]=0;
        memset(used,0,sizeof(bool)*26);
        memset(vis,0,sizeof(bool)*26);
        memset(top,0,sizeof(bool)*26);
    	while(gets(b)!=NULL && b[0])
    	{
    	    used[c-'A']=1, a[0]=0;
    		y=sscanf(b,"%c %d %s",&c,&x,a);
    		dis[c-'A']=x;
    		if(y==2) continue;
    		for(i=0;a[i];i++) used[a[i]-'A']=1, AdjList[a[i]-'A'].push_back(c-'A');
    	}
    	for(i=0,TopoSort.clear();i<26;i++) if(used[i] && !vis[i]) top[i]=1, TopoDFS(i);
        for(i=TopoSort.size()-1,mx=0;i>=0;i--)
        {
        	if(top[TopoSort[i]])
        	{
        	    total=0;
        	    DFS(TopoSort[i]);
        	}
        }
        printf("%d\n",mx);
    }
    return 0;
}
