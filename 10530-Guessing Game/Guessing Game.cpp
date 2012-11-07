#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10530
 *
 *language-C++
 *
 */

int GreaterNumbers[20],SmallerNumbers[20],la,lb;

void Refresh()
{
    for(int i=0;i<20;i++)
    {
    	GreaterNumbers[i]=-1;
    	SmallerNumbers[i]=-1;
    }
    return;
}

int check(int n)
{
      for(int i=0;i<la;i++)
      {
      	if(GreaterNumbers[i]<=n) return 0;
      }
      for(int i=0;i<lb;i++)
      {
      	if(SmallerNumbers[i]>=n) return 0;
      }
      return 1;
}
int main()
{
	int i,n,RightAns,a,flag;
	char Response[10];
	Refresh();
	la=0;
	lb=0;
	while(scanf("%d %s %s",&n,Response,Response)==3)
	{
		if(Response[0]=='h')
		{
		    GreaterNumbers[la]=n;
		    la++;
		}
		else if(Response[0]=='l')
		{
		    SmallerNumbers[lb]=n;
		    lb++;
		}
		else if(Response[0]=='o')
		{
		    RightAns=n;
		    a=check(n);
		    if(a) printf("Stan may be honest\n");
		    else printf("Stan is dishonest\n");
		    la=0;
		    lb=0;
		    Refresh();
		}
	}
	return 0;
}
