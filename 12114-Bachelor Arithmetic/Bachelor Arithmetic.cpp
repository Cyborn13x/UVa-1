#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-12114
 *
 *lnguage-C++
 *
 *
 */

using namespace std;

double min(double a,double b)
{
    return (a<b?a:b);
}

int main()
{
	int i;
	int j;
	int n=0;
	double s;
	double b;
	double PastPro;
	double PresentPro;
	while(cin>>b>>s && (s || b))
	{
	      cout<<"Case "<<++n<<": ";
	      if(b==1.0)
	      {
	            cout<<":-\\"<<endl;
	            continue;
	      }
		PastPro=min(s/b,1.0);
		PresentPro=min((s-1.0)/(b-1.0),1.0);
		if(PresentPro>PastPro) cout<<":-)"<<endl;
		else if(PresentPro<PastPro) cout<<":-("<<endl;
		else cout<<":-|"<<endl;
	}
	return 0;
}
