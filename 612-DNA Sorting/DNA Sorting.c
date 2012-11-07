#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*Problem id-612
 *
 *Language-ANSI C
 *
 */

typedef struct
{
      int SwapNumber;
      char ptr[110];
}Properties;

void SwapC(char *Number1,char *Number2)
{
      char temp;
      temp=(*Number1);
      *Number1=*Number2;
      *Number2=temp;
      return;
}

void SwapI(Properties *Number1,Properties *Number2)
{
      Properties temp;
      temp=(*Number1);
      *Number1=*Number2;
      *Number2=temp;
      return;
}

int BubbleSortC(char *ptr,int NumberOfElement)
{
    int NumberOfSwap=0,i,j;
    for(i=0;i<NumberOfElement;i++)
	{
		for(j=0;j<(NumberOfElement-1);j++)
		{
			if(ptr[j]>ptr[j+1])
			{
			      SwapC(&ptr[j],&ptr[j+1]);
			      NumberOfSwap++;
			}
		}
	}
	return NumberOfSwap;
}

void BubbleSortI(Properties *ptr,int NumberOfElement)
{
    int i,j;
    for(i=0;i<NumberOfElement;i++)
	{
		for(j=0;j<(NumberOfElement-1);j++)
		{
			if(ptr[j].SwapNumber>ptr[j+1].SwapNumber)
			{
			      SwapI(&ptr[j],&ptr[j+1]);
			}
		}
	}
	return;
}

int main()
{
	int i,j,NumberOfStrings,LengthOfString,TestCase;
	char Strings[100][51],DummyStrings[51],c;
	Properties p[100];
	scanf("%d",&TestCase);
	for(i=0;i<TestCase;i++)
	{
	    scanf("%c",&c);
		scanf("%d %d",&LengthOfString,&NumberOfStrings);
		for(j=0;j<NumberOfStrings;j++)
		{
		    scanf("%c",&c);
			scanf("%[^\n]",Strings[j]);
			strcpy(DummyStrings,Strings[j]);
			p[j].SwapNumber=BubbleSortC(DummyStrings,LengthOfString);
			strcpy(p[j].ptr,Strings[j]);
		}
		BubbleSortI(p,NumberOfStrings);
		for(j=0;j<NumberOfStrings;j++) printf("%s\n",p[j].ptr);
		if(i<TestCase-1) printf("\n");
	}
	return 0;
}
