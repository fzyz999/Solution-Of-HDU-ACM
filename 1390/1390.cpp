#include <iostream>

using namespace std;

int main()
{
     int d,n,i,tmp;
     bool is_first;

     cin>>d;
     while(d--)
     {
	  is_first=true;
	  cin>>n;
	  for(tmp=1,i=0;i<32;i++)
	  {
	       if(n&(tmp<<i))
		    if(is_first)
		    {
			 is_first=false;
			 cout<<i;
		    }
		    else
		    {
			 cout<<' '<<i;
		    }
	  }
	  cout<<endl;
     }


     return 0;
}
