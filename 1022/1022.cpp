/*
  一道纯模拟题。如果想让火车由进入顺序变化为出站顺序，只需判断当前停在站台最外侧的火车是否是应当出站的那辆，如果是，则直接开出，如果不是，则让下一列车开入站中。这是典型的先进后出顺序。所以使用栈来模拟题目中的站台即可。
 */
#include <iostream>
#include <string.h>

using namespace std;

//此处使用了一个自己手写的栈而非STL，目的是学习栈的原理及实现，也方便深入理解这道题。
//使用模板是为方便下次再次使用栈。
//将实现部分和定义部分分开，方便阅读代码。
template <typename T>
class Stack
{
     int top,size;
     T *s;

public:
     Stack(int len){s=new T[len];size=len;clear();}
     void clear(){top=0;};
     bool push(T &num);
     bool pop();
     bool isEmpty(){return !(top>0);};
     T Top(){return s[top-1];};
     int lenth(){return top;};
};

int main()
{
     int deep,i,p1,p2,pa,l1,l2;

     Stack<char> o1(100);
     char str1[100],ans[100],str2[100];

     bool ShouldBreak;

     while(cin>>deep>>str1>>str2)
     {
	  l1=strlen(str1);
	  l2=strlen(str2);
	  o1.clear();

	  pa=0;
	  ShouldBreak=false;

	  for(p1=0,p2=0;p2<l2;)
	  {
	       while(str2[p2]!=o1.Top())
	       {
		    if(p1>=l1)
		    {
			 ShouldBreak=true;
      			 break;
		    }
		    
		    o1.push(str1[p1++]);
		    ans[pa++]='i';
	       }
	       
	       if(!ShouldBreak)
	       {
		    p2++;
		    o1.pop();
		    ans[pa++]='o';
	       }
	       else
		    break;
	  }
	       
	  if(o1.isEmpty())
	  {
	       cout<<"Yes."<<endl;
	       for(i=0;i<pa;i++)
		    if(ans[i]=='i')
			 cout<<"in"<<endl;
		    else
			 cout<<"out"<<endl;
	  }
	  else
	       cout<<"No."<<endl;
	  cout<<"FINISH"<<endl;
	  
     }
     

     return 0;
}

//Stack 实现部分
template <typename T>
bool Stack<T>::push(T &num)
{
     if(top+1<size)
     {
	  s[top++]=num;

	  return true;
     }

     return false;
}

template <typename T>
bool Stack<T>::pop()
{
     if(top>0)
     {
	  top--;
	  
	  return true;
     }

     return false;
}
