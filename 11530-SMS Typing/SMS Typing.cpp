#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int TestCase,i,len,n;
	char a[1001];
	scanf("%d",&TestCase);
	fflush(stdin);
	for(i=0;i<TestCase;i++)
	{
	    n=0;
		gets(a);
		len=strlen(a);
		for(int j=0;j<len;j++)
		{
			if(a[j]=='a' || a[j]=='d' || a[j]=='g' || a[j]=='j' || a[j]=='m' || a[j]=='p' || a[j]=='t' || a[j]=='w' || a[j]==' ' || a[j]=='A' || a[j]=='D' || a[j]=='G' || a[j]=='J' || a[j]=='M' || a[j]=='P' || a[j]=='T' || a[j]=='W')
			{
			    n+=1;
			}
			else if(a[j]=='b' || a[j]=='e' || a[j]=='h' || a[j]=='k' || a[j]=='n' || a[j]=='q' || a[j]=='u' || a[j]=='x' || a[j]=='B' || a[j]=='E' || a[j]=='H' || a[j]=='K' || a[j]=='N' || a[j]=='Q' || a[j]=='U' || a[j]=='X')
			{
			    n+=2;
			}
			else if(a[j]=='c' || a[j]=='f' || a[j]=='i' || a[j]=='l' || a[j]=='o' || a[j]=='r' || a[j]=='v' || a[j]=='y' || a[j]=='C' || a[j]=='F' || a[j]=='I' || a[j]=='L' || a[j]=='O' || a[j]=='R' || a[j]=='V' || a[j]=='Y')
			{
			    n+=3;
			}
			else if(a[j]=='s' || a[j]=='z' || a[j]=='S' || a[j]=='Z')
			{
			    n+=4;
			}
			else
			{
			    n+=1;
			}
		}
		printf("Case #%d: %d\n",i+1,n);
	}
	return 0;
}
