#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char a[1005][2000];


void str_rev(char *ptr)
{
      int i;
      int l=strlen(ptr)-1;
      char temp;
      for(i=0;i<=l/2;i++)
      {
            temp=ptr[i];
            ptr[i]=ptr[l-i];
            ptr[l-i]=temp;
      }
      return;
}

void add(char *ptr1,char *ptr2,char *ptr3)
{
      int len_of_a,len_of_b,i,j,counter,rem=0;
      len_of_a=strlen(ptr1);
	len_of_b=strlen(ptr2);
      if(len_of_a>=len_of_b)
	{
	      counter=len_of_a;
	}
	else
	{
	      counter=len_of_b;
	}

	str_rev(ptr1);
	str_rev(ptr2);
	for(i=0,j=0;(i<=counter-1);i++,j++)
	{

	      if(i>=len_of_a)
	      {
	            ptr1[i]='0';
	            ptr1[i]-=48;
	      }
	      else
	      {
	            ptr1[i]-=48;
	      }
	      if(j>=len_of_b)
	      {
                  ptr2[j]='0';
                  ptr2[j]-=48;
	      }
	      else
	      {
	            ptr2[j]-=48;
	      }
	      ptr3[i]=(ptr1[i]+ptr2[j]+rem)%10;
	      ptr3[i]+=48;
	      rem=(ptr1[i]+ptr2[j]+rem)/10;
	}
	if(rem!=0)
	{
	      ptr3[counter]=rem;
	      ptr3[counter]+=48;
	      ptr3[counter+1]='\0';
	}
	else
	{
	      ptr3[counter]='\0';
	}
	str_rev(ptr3);
	return;
}

int main()
{
	int i;
	int j;
	int n;
	a[0][0]='0';
	a[0][1]='\0';
	a[1][0]='1';
	a[1][1]='\0';
	char c[2000];
	char d[2000];
	for(i=2;i<1005;i++)
	{
	      strcpy(c,a[i-2]);
	      strcpy(d,a[i-1]);
		add(c,d,a[i]);
	}
      while(scanf("%d",&n)==1)
      {
      	printf("%s\n",a[n+2]);
      }
	return 0;
}
