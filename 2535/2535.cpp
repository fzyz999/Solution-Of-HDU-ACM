#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
     int n,i,s,a[102];
     
     while(cin>>n&&n)
     {
          s=0;
          for(i=0;i<n;i++)
               cin>>a[i];

          sort(a,a+n);

          n=(n>>1)+1;
          
          for(i=0;i<n;i++)
               s+=(a[i]>>1)+1;

          cout<<s<<endl;
     }     
     
     return 0;
}
