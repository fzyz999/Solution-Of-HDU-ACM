#include <iostream>

using namespace std;

struct Node
{
     int num;
     Node *next;
     
     Node(){next=NULL;}
};

int main()
{
     int n,N;
     cin>>N;

     while(N--)
     {
          cin>>n;
          
          int i,size=n;
          Node* head,*start;

          head=new Node;
          start=head;
          head->num=1;
          for(i=0;i<n-1;i++)
          {
               head->next=new Node;
               head=head->next;
               head->num=i+2;
          }

          while(size>3)
          {
               Node *prev=start;
               head=start->next;
               for(i=1;i<n && head!=NULL;i++)
               {
                    if(i&1)
                    {
                         prev->next=head->next;
                         delete head;
                         head=prev->next;
                         size--;
                    }
                    else
                    {
                         prev=head;
                         head=head->next;
                    }
               }

               if(size<=3)
                    break;

               int count;
               prev=start;
               head=start->next;
               for(i=1,count=1;i<n && head!=NULL;i++)
               {
                    count++;
                    if(count==3)
                    {
                         prev->next=head->next;
                         delete head;
                         head=prev->next;
                         size--;
                         count=0;
                    }
                    else
                    {
                         prev=head;
                         head=head->next;
                    }
               }
          }

          cout<<start->num;
          for(head=start->next;head!=NULL;head=head->next)
               cout<<' '<<head->num;
          cout<<endl;
     }

     return 0;
}
