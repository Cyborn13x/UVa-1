#include<stdio.h>
//------------------------------------------------------
void str_rev(char *ptr);
int is_zero(char *ptr);
int str_len(char *ptr);
void str_to_int(char *ptr);
void int_to_str(char *ptr);
int add(char *ptr1,char *ptr2,char *ptr3);
//------------------------------------------------------
int main()
{
      int i,j,m;
	char a[1000],b[1000],c[2000],t;
	int len_of_a,len_of_b;
	for(;;)
	{

            gets(a);
            if(is_zero(a))
            {
                  break;
            }
            for(i=0;;i++)
            {
                  if(a[i]==' ')
                  {
                        break;
                  }
            }
            m=0;
            for(j=i+1;j<str_len(a);j++)
            {
                  t=a[j];
                  b[m]=t;
                  m++;
            }
            b[m+1]=NULL;
            printf("%d\n",add(a,b,c));
	}
	return 0;
}
//------------------------------------------------------
void str_rev(char *ptr)
{
      int i,len;
      char temp;
      len=str_len(ptr);
      for(i=0;i<=(len-1)/2;i++)
      {
            temp=ptr[i];
            ptr[i]=ptr[len-1-i];
            ptr[len-1-i]=temp;
      }
}
//------------------------------------------------------
int str_len(char *ptr)
{
      int i=0;
      while(ptr[++i]!='\0');
      return i;
}
//------------------------------------------------------
int is_zero(char *ptr)
{
      if(ptr[0]=='0'&&ptr[1]==' '&&ptr[2]=='0'&&ptr[3]==NULL)
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
      int len_of_a,len_of_b,i,j,counter,rem=0,ret_value=0;
      len_of_a=str_len(ptr1);
	len_of_b=str_len(ptr2);
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
	      if(rem==1)
	      {
	            ret_value++;
	      }
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
	return ret_value;
}
