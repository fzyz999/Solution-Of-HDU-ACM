#include <iostream>

using namespace std;

int
main()
{
  int t,y;
  char x;

  cin>>t;
  while(t--)
    {
      cin>>x>>y;

      register int tmp;     
      if(x<'a')
	tmp=x-'A'+1;
      else
	tmp='a'-x-1;

      tmp+=y;
      cout<<tmp<<endl;
    }

  return 0;
}
