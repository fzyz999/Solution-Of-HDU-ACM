#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int> adt;

int main()
{
  int n,Max,t,tmp;
  string str;

  while(cin>>n)
    {
      adt.clear();
      Max=0;
      getline(cin,str);

      while(n--)
	{
	  getline(cin,str);
	  t=str.find_first_not_of("0");
	  if(t==-1)
	    tmp=++adt[string("0")];
	  else
	    tmp=++adt[str.substr(t)];
	  Max=Max>tmp?Max:tmp;
	}
      
      cout<<Max<<endl;
    }

  return 0;
}
