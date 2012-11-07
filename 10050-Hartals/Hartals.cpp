#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10050
 *
 *language-ANSI C
 *
 *
 */


int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
      int t;
      int day;
      int parties;
      int hp;
      int wd;
      int holy[3652];
      int week[3652];
      j=0;
      for(i=1;i<3652;i++)
      {
            j++;
      	if(j==6) holy[i]=1;
      	else if(j==7)
      	{
      	      holy[i]=1;
      	      j=0;
      	}
      	else holy[i]=0;
      }
      scanf("%d",&t);
      for(i=0;i<t;i++)
      {
            wd=0;
            for(j=1;j<3652;j++)
            {
            	week[j]=0;
            }
      	scanf("%d",&day);
      	scanf("%d",&parties);
      	for(j=0;j<parties;j++)
      	{
      		scanf("%d",&hp);
      		for(k=hp;k<=day;k+=hp)
      		{
      			week[k]=1;
      		}
      	}
      	for(j=1;j<=day;j++)
      	{
                  if(week[j] && !holy[j])
                  {
                        wd++;
                  }
      	}
      	printf("%d\n",wd);

      }
	return 0;
}
