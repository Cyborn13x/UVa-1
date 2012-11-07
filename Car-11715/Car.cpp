#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void s_a(float u,float v,float t,float *s,float *a);
void s_t(float u,float v,float a,float *s,float *t);
void v_t(float u,float a,float s,float *v,float *t);
void u_t(float v,float a,float s,float *u,float *t);

int main()
{
	int Option,i;
	float u,v,a,t,s;
	u=v=a=t=s=0;
	i=0;
	while(1)
	{
	      i++;
	      scanf("%d",&Option);
	      if(!Option)
	      {
	            break;
	      }
            else if(Option==1)
            {
                  scanf("%f %f %f",&u,&v,&t);
                  s_a(u,v,t,&s,&a);
                  printf("Case %d: %.3f %.3f\n",i,s,a);
            }
            else if(Option==2)
            {
                  scanf("%f %f %f",&u,&v,&a);
                  s_t(u,v,a,&s,&t);
                  printf("Case %d: %.3f %.3f\n",i,s,t);
            }
            else if(Option==3)
            {
                  scanf("%f %f %f",&u,&a,&s);
                  v_t(u,a,s,&v,&t);
                  printf("Case %d: %.3f %.3f\n",i,v,t);
            }
            else
            {
                  scanf("%f %f %f",&v,&a,&s);
                  u_t(v,a,s,&u,&t);
                  printf("Case %d: %.3f %.3f\n",i,u,t);
            }
      }
	return 0;
}

void s_a(float u,float v,float t,float *s,float *a)
{
      *a=(v-u)/t;
      *s=u*t+(*a)*t*t/2;
      return;
}

void s_t(float u,float v,float a,float *s,float *t)
{
      *t=(v-u)/a;
      *s=(v*v-u*u)/(2*a);
      return;
}

void v_t(float u,float a,float s,float *v,float *t)
{
      *v=sqrt(u*u+2*a*s);
      *t=((*v)-u)/a;
      return;
}

void u_t(float v,float a,float s,float *u,float *t)
{
      *u=sqrt(v*v-2*a*s);
      *t=(v-(*u))/a;
      return;
}





