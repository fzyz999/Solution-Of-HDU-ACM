#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
  int t,n,i;
  long long s,l,m;
  char n_str[200];

  cin>>t;
  while(t--)
    {
      cin>>n_str>>m;
      n=m-1;
      if(strlen(n_str)<=7)
	sscanf(n_str,"%d",&n);
      
      s=1;
      l=1;
      n=n<m?n:m-1;
      for(i=1;i<=n;i++)
	{
	  l*=i;
	  l%=m;
	  s+=l;
	  s%=m;
	}
      
      cout<<s%m<<endl;
    }

  return 0;
}
