/*
  a simple short-path problem
  I using spfa to solve it.


  FixMe:I don't know why this is wrong when your compile it using (MS)c++ instead of g++;
 */
#include <iostream>

using namespace std;

struct LNode
{
     int x;
     LNode *next;
     LNode(){next=NULL;}
};

struct Edge
{
     int to;
     int cost;
     Edge *next;
     Edge(){next=NULL;}
};

Edge *v[201];

int spfa(const int &n,const int &s,const int &t)
{
     int d[n],i;
     bool bl[n];
     for(i=0;i<n;i++)
     {
	  d[i]=0xfffffff;
	  bl[i]=false;
     }
     d[s]=0;

     LNode *h,*e,*l;
     Edge *tmp;

     h=new LNode;
     h->x=s;
     l=h;
     while(h!=NULL)
     {
	  bl[h->x]=false;
	  for(tmp=v[h->x];tmp!=NULL;tmp=tmp->next)
	       if(d[tmp->to]>d[h->x]+tmp->cost)
	       {
		    d[tmp->to]=d[h->x]+tmp->cost;
		    if(!bl[tmp->to])
		    {
			 l->next=new LNode;
			 l=l->next;
			 l->x=tmp->to;
			 bl[tmp->to]=true;
		    }
	       }
	  e=h;
	  h=h->next;
	  delete e;
     }

     int ret=(d[t]==0xfffffff)?-1:d[t];

     return ret;
}

int main()
{
     int n,m,a,b,c,s,t,i;
     Edge *tmp,*tmp2;
     while(cin>>n>>m)
     {
	  i=m;
	  while(i--)
	  {
	       cin>>a>>b>>c;
	       tmp=new Edge;
	       tmp->next=v[a];
	       tmp->to=b;
	       tmp->cost=c;
	       v[a]=tmp;
	       tmp=new Edge;
	       tmp->next=v[b];
	       tmp->to=a;
	       tmp->cost=c;
	       v[b]=tmp;
	  }
	  cin>>s>>t;

	  cout<<spfa(n,s,t)<<endl;

	  //free
	  while(m--)
	  {
	       for(tmp=v[m];tmp!=NULL;)
	       {
		    tmp2=tmp;
		    tmp=tmp->next;
		    delete tmp2;
	       }
	       v[m]=NULL;
	  }
	  //
     }

     return 0;
}
