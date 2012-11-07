#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 100010

/*problem id-11495
 *
 *language-ANSI C
 *
 *
 */

int a[N];
int b[N];
long int c;

void MergeSort(int *a,int Start,int End)
{
      int mid;
      if(Start<End)
      {
            mid=(Start+End)/2;
            MergeSort(a,Start,mid);
            MergeSort(a,mid+1,End);
            Merge(a,Start,mid,End);
      }
      return;
}

void Merge(int *a,int Start,int mid,int End)
{
      int i=Start;
      int j=mid+1;
      int k=Start;
      while(i<=mid && j<=End)
      {
      	if(a[i]<=a[j]) b[k++]=a[i++];
      	else
      	{

      	      b[k++]=a[j++];
      	      c+=(mid-i+1);
      	}
      }
      while(i<=mid) b[k++]=a[i++];
      while(j<=End) b[k++]=a[j++];
      for(i=Start;i<=End;i++)a[i]=b[i];
      return;
}

int main()
{
	int i;
	int j;
	int n;
	while(scanf("%d",&n)==1 && n)
	{
	      c=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		MergeSort(a,0,n-1);
		if(c%2) printf("Marcelo\n");
		else printf("Carlos\n");

	}
	return 0;
}
