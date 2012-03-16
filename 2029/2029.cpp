#include <iostream>
#include <string.h>

using namespace std;

int main()
{
     int n,l,r;
     char str[1000];
     bool is_right;

     cin>>n;
     while(n--)
     {
	  cin>>str;
	  is_right=true;
	  for(l=0,r=strlen(str)-1;l<r;l++,r--)
	       if(str[l]!=str[r])
	       {
		    is_right=false;
		    break;
	       }

	  cout<<(is_right?"yes":"no")<<endl;
     }

     return 0;
}
