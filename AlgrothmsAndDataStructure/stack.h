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
