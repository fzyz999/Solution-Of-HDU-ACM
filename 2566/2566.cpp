/*
  a+2*b+5*c=m;
  a+b+c=n;
  a=n-b-c;
  n-b-c+2*b+5*c=m;
  n+b+4*c=m;
  b=m-n-4*c;

  b=m-n-4*c;
  a=n-b-c;
 */
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main()
{
     int n,m,a,b,c,s,t;

     cin>>t;
     while(t--)
     {
	  s=0;
	  cin>>n>>m;
	  
	  for(c=m/5;c>=0;c--)
	  {
	       b=m-n-4*c;
	       a=n-b-c;
	       if(a>=0&&a<=n&&b>=0&&b<=n&&c<=n&&a+b*2+c*5==m)
		    s++;
	  }
	  cout<<s<<endl;
     }

     return 0;
}
