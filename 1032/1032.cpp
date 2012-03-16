#include <iostream>

using namespace std;

int main()
{
     int i,j,Max,n,s;

     while(cin>>i>>j)
     {
	  Max=0;
	  cout<<i<<' '<<j<<' ';

	  if(i>j)
	  {
	       i^=j;
	       j^=i;
	       i^=j;
	  }

	  for(;i<=j;i++)
	  {
	       s=1;
	       for(n=i;n!=1;)
	       {
		    s++;
		    if(n&1)
			 n=3*n+1;
		    else
			 n>>=1;
	       }
	       Max=Max>s?Max:s;
	  }
	  cout<<Max<<endl;
     }

     return 0;
}
