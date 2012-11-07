#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10921
 *
 *language-C++
 *
 */

char Expression[40];
char TelephoneNumber[40];

void FindTelephoneNumber()
{
      int l=strlen(Expression);
      for(int i=0;i<=l;i++)
      {
      	if(Expression[i]>=65 && Expression[i]<=67)TelephoneNumber[i]='2';
      	else if(Expression[i]>=68 && Expression[i]<=70)TelephoneNumber[i]='3';
      	else if(Expression[i]>=71 && Expression[i]<=73)TelephoneNumber[i]='4';
      	else if(Expression[i]>=74 && Expression[i]<=76)TelephoneNumber[i]='5';
      	else if(Expression[i]>=77 && Expression[i]<=79)TelephoneNumber[i]='6';
      	else if(Expression[i]>=80 && Expression[i]<=83)TelephoneNumber[i]='7';
      	else if(Expression[i]>=84 && Expression[i]<=86)TelephoneNumber[i]='8';
      	else if(Expression[i]>=86 && Expression[i]<=90)TelephoneNumber[i]='9';
      	else TelephoneNumber[i]=Expression[i];
      }
      return;
}

int main()
{
	int i;
	int j;
	int n;
	while(gets(Expression))
	{
            FindTelephoneNumber();
            printf("%s\n",TelephoneNumber);
	}
	return 0;
}
