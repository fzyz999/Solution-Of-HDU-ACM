#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

map<string,string> adt;

int main()
{
  string tmp1,tmp2;

  //reading dictionary
  cin>>tmp1;//reading START
  while(cin>>tmp1)
    {
      if(tmp1.compare("END")==0)
	break;
     
      cin>>tmp2;
      adt[tmp2]=tmp1;
    }

  map<string,string>::iterator it;
  char *p,*e,str[3001],tmp;
  gets(str);
  gets(str);
  for(;;)
    {
      gets(str);
      if(strcmp(str,"END")==0)
	break;

      for(p=e=str;*e!=0;e++)
	if(!(*e>='a' && *e<='z'))
	  {
	    tmp=*e;
	    *e=0;
	    it=adt.find(string(p));
	    if(it!=adt.end())
	      cout<<it->second<<tmp;
	    else
	      cout<<p<<tmp;

	    p=e+1;
	  }
      cout<<endl;
    }
  

  return 0;
}
