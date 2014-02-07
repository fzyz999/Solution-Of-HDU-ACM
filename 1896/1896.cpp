#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
     int pos;
     int d;
     
     bool operator < (const Node& a) const;
     bool operator > (const Node& a) const;
};

inline bool Node::operator < (const Node& a) const
{
     if(pos != a.pos)
          return pos<a.pos;
     else
          return d<a.d;
}

inline bool Node::operator > (const Node& a) const
{
     if(pos != a.pos)
          return pos>a.pos;
     else
          return d>a.d;
}

class Heap
{     
public:
     Heap(){size=0;}
     void push(const Node& value);
     Node top(){return _heap[1];}
     Node pop();
     bool isEmpty(){return size==0;}

private:
     Node _heap[100101];
     int size;

     void heapify_down(const int& pos);
     void heapify_up(const int& pos);
};



inline void Heap::push(const Node& value)
{     
     _heap[++size]=value;
     heapify_up(size);
}

inline Node Heap::pop()
{
     Node ret=_heap[1];
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
     int T,n;
     int p,d;

     scanf("%d",&T);
     while(T--)
     {
          //clear heap
          while(!heap.isEmpty())
               heap.pop();
          /////
          
          scanf("%d",&n);
          while(n--)
          {
               scanf("%d %d",&p,&d);

               Node tmp;
               tmp.pos=p;
               tmp.d=d;
               heap.push(tmp);
          }

          int max=0;

          for(int count=1;!heap.isEmpty();count++)
          {
               Node topValue=heap.pop();
               if(count&1)
               {                    
                    topValue.pos+=topValue.d;
                    heap.push(topValue);
               }
               
               max=max>topValue.pos?max:topValue.pos;
          }

          printf("%d\n",max);
     }

     return 0;
}
