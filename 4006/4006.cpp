#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Heap
{     
public:
     Heap(){size=0;}
     void push(const int& value);
     int top(){return _heap[1];}
     int pop();
     bool isEmpty(){return size==0;}
     int _heap[1000101];
     int size;

private:
     

     void heapify_down(const int& pos);
     void heapify_up(const int& pos);
};



inline void Heap::push(const int& value)
{     
     _heap[++size]=value;
     heapify_up(size);
}

inline int Heap::pop()
{
     int ret=_heap[1];
     _heap[1]=_heap[size--];
     heapify_down(1);
     
     return ret;
}

void Heap::heapify_down(const int& pos)
{
     for(register int i=pos;(i<<1)<=size;)
     {
          register int s=i<<1,r=(i<<1)+1;
          if(r<=size && _heap[r]<_heap[s])
               s=r;
          
          if(_heap[i]>_heap[s])
          {
               swap(_heap[i],_heap[s]);
               i=s;
          }
          else
               break;
     }
}

void Heap::heapify_up(const int& pos)
{
     for(register int i=pos;i>1;)
     {
          register int s=i>>1;
          if(_heap[i]<_heap[s])
          {
               swap(_heap[i],_heap[s]);
               i=s;
          }
          else
               break;
     }
}

Heap heap;

int main()
{
     int n,k;

     while(cin>>n>>k)
     {
          while(!heap.isEmpty())
               heap.pop();
          
          while(n--)
          {
               char input;
          
               cin>>input;
               if(input=='I')
               {
                    int num;
                    cin>>num;

                    heap.push(num);
               }
               else if(input=='Q')
               {
                    printf("%d\n",heap.top());
               }
               
               while(heap.size>k)
               {
                    heap.pop();
               }
          }
     }

     return 0;
}
