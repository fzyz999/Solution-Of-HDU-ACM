#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
     int n,tmp;
     map<int,int> fu,m_sort;
     set<int> im;
     map<int,int>::iterator it;

     while(cin>>n&&n)
     {
          fu.clear();
          m_sort.clear();
          while(n--)
          {
               cin>>tmp;
               if(im.find(tmp)==im.end())
                    fu[tmp]=n;
               
               while(tmp!=1)
               {
                    if(tmp&1)
                         tmp=3*tmp+1;
                    tmp>>=1;
                    
                    it=fu.find(tmp);
                    if(it!=fu.end())
                         fu.erase(it);
                    im.insert(tmp);
               }
          }

          for(it=fu.begin();it!=fu.end();it++)
               m_sort[(*it).second]=(*it).first;
          
          cout<<(*m_sort.begin()).second;
          for(it=m_sort.begin(),it++;it!=m_sort.end();it++)
               cout<<' '<<(*it).second;
          cout<<endl;
     }

     return 0;
}
