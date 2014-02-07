#include <iostream>

#define MAX_N 15

using namespace std;

class Stack
{
     int topPos;
     int s[MAX_N];

public:
     Stack(){topPos = -1;}
     int top(){return s[topPos];}
     int pop();
     void push(const int& value);
};

inline int Stack::pop()
{
     return s[topPos--];
}

inline void Stack::push(const int& value)
{
     s[++topPos]=value;
}


int main()
{
     int n;
     char o1[100],o2[100];

     while(cin>>n)
     {
          Stack _stack;
          int _pO1=1,_pO2=0;
          bool _ans[100];
          int _pAns=1;
          cin>>o1>>o2;

          _stack.push(o1[0]);
          _ans[0]=0;
          for(;_pO2<n && _pO1<=n;)
          {
               if(_stack.top()!=o2[_pO2])
               {
                    if(_pO1>=n)
                    {
                         break;
                    }
                    _stack.push(o1[_pO1++]);
                    _ans[_pAns++]=0;
               }
               else
               {
                    _stack.pop();
                    _ans[_pAns++]=1;
                    _pO2++;
               }
          }

          if(_pO2>=n)
          {
               cout<<"Yes."<<endl;
               for(int i=0;i<_pAns;i++)
                    cout<<((_ans[i])?"out":"in")<<endl;
               cout<<"FINISH"<<endl;
          }
          else
               cout<<"No.\nFINISH"<<endl;
          
     }

     return 0;
}