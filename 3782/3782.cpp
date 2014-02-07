#include <iostream>

using namespace std;

int main()
{
     int n,s;
     while(cin>>n&&n)
     {
          for(s=0;n!=1;n>>=1,s++)
               if(n&1)
                    n=3*n+1;

          cout<<s<<endl;
     }
     
     return 0;
}
