#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node
{
     char str_command[25];
     int parameter;
     int priority;
     int index;
     
     bool operator < (const Node& a) const;
     bool operator > (const Node& a) const;
};

inline bool Node::operator < (const Node& a) const
{
     if(priority != a.priority)
          return priority<a.priority;
     else
          return index<a.index;
}

inline bool Node::operator > (const Node& a) const
{
     if(priority != a.priority)
          return priority>a.priority;
     else
          return index>a.index;
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
     Node _heap[5001];
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
     char buf[25];
     int index=0;

     while(scanf("%s",buf)!=EOF)
     {
          if(strcmp("GET",buf)==0)
          {
               if(heap.isEmpty())
                    printf("EMPTY QUEUE!\n");
               else
               {
                    Node output=heap.pop();
                    printf("%s %d\n",output.str_command,output.parameter);
               }
          }
          else
          {
               index++;
               int par,pri;
               scanf("%s %d %d\n",buf,&par,&pri);
               Node in;
               strcpy(in.str_command,buf);
               in.parameter=par;
               in.priority=pri;
               in.index=index;
               heap.push(in);
          }
     }

     return 0;
}
