#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
     int n,i,tmp;
     vector<int> a;

     while(cin>>n)
     {
	  for(i=0;i<n;i++)
	  {
	       cin>>tmp;
	       a.push_back(tmp);
	  }

	  sort(a.begin(),a.end());
	  cout<<a[n>>1]<<endl;
     }

     return 0;
}
