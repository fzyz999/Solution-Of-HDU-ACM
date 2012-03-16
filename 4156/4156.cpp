#include <iostream>

using namespace std;

int
main()
{
  register int a,b,c;

  while(cin>>a>>b>>c && (a!=0||b!=0||c!=0))
    {
      if(a>b)
	{
	  a^=b;
	  b^=a;
	  a^=b;
	}
      if(a>c)
	{
	  a^=c;
	  c^=a;
	  a^=c;
	}
      if(b>c)
	{
	  b^=c;
	  c^=b;
	  b^=c;
	}

      if(a*a+b*b==c*c)
	cout<<"right"<<endl;
      else
	cout<<"wrong"<<endl;
    }

  return 0;
}
