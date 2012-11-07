#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char a[100000000];

void Decoder()
{
      int i,l=strlen(a);
      for(i=0;i<l;i++)
      {
      	a[i]-=7;
      }
      return;
}

int main()
{
	int i,j;
	while(gets(a))
	{
            Decoder();
            printf("%s\n",a);
	}
	return 0;
}
