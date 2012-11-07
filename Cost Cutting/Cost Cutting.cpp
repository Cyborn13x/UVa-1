#include<stdio.h>
//---------------------------------------------
int middle(int a,int b,int c);
//---------------------------------------------
int main()
{
	int test_case,a,b,c;
	scanf("%d",&test_case);
	for(int i=1;i<=test_case;i++)
	{
	      scanf("%d %d %d",&a,&b,&c);
	      printf("Case %d: %d\n",i,middle(a,b,c));
	}
	return 0;
}
//---------------------------------------------
int middle(int a,int b,int c)
{
      if(a<b&&a<c)
      {
            if(b<c)
            {
                  return b;
            }
            else
            {
                  return c;
            }
      }
      else if(b<a&&b<c)
      {
            if(a<c)
            {
                  return a;
            }
            else
            {
                  return c;
            }
      }
      else
      {
            if(a<b)
            {
                  return a;
            }
            else
            {
                  return b;
            }
      }
}
