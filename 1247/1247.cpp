#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
     string word[50001],*p=word;
     int i,j;
     map<string,bool> dic;

     while(cin>>*p)
     {
	  dic[*p]=true;
	  p++;
     }

     for(i=0;&word[i]<p;i++)
     {
	  for(j=word[i].size()-1;j>=0;j--)
	  {
	       if(dic.find(word[i].substr(0,j))!=dic.end() && dic.find(word[i].substr(j))!=dic.end())
	       {
		    cout<<word[i]<<endl;
		    break;
	       }
	  }
     }

     return 0;
}
