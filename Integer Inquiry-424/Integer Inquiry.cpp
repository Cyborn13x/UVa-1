#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//------------------------------------------------------
void str_to_int(char *ptr);
void str_rev(char *ptr);
void int_to_str(char *ptr);
int IfZero(char *s);
int add(char *ptr1,char *ptr2,char *ptr3);
//------------------------------------------------------
int main()
{
	char a[1000],b[1000],c[2000];
	int len_of_a,len_of_b;
	b[0]='0';
	b[1]='\0';
	while(1)
	{
	      gets(a);
	      if(IfZero(a)==1)
	      {
                  break;
	      }
	      add(a,b,c);
	      strcpy(b,c);
	}
	printf("%s\n",c);
	return 0;
}
//------------------------------------------------------
int IfZero(char *s)
{
      if(s[0]=='0' && s[1]=='\0')
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
//------------------------------------------------------
int add(char *ptr1,char *ptr2,char *ptr3)
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
	      ptr3[counter+1]=NULL;
	}
	else
	{
	      ptr3[counter]=NULL;
	}
	str_rev(ptr3);
	return 0;
}
void str_rev(char *ptr)
{
      int i;
      char temp;
      for(i=0;i<=(strlen(ptr)-1)/2;i++)
      {
            temp=ptr[i];
            ptr[i]=ptr[strlen(ptr)-1-i];
            ptr[strlen(ptr)-1-i]=temp;
      }
}

