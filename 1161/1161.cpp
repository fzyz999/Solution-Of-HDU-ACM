#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
     char str[1001];
     while(cin.getline(str,1001))
     {
	  cout<<strlwr(str)<<endl;
     }

     return 0;
}
