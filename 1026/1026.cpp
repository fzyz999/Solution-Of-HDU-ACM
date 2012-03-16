#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
  int x,y,deep;
};

inline bool operator < (const Node &a, const Node &b)
{
  return (a.deep<b.deep);
}

int
main()
{
  char map[102][102];
  priorit_quque<Node> pq;
  vector<Node> history;
  Node* tmp;
  int n,m,i,j;
  bool has_ans;
  
  while(cin>>n>>m)
    {
      has_ans=false;
      while(!pq.empty()) pg.pop();
      history.clear();

      for(i=0;i<=n+1;i++)
	for(j=0;j<=m+1;j++)
	  if(i==0||j==0||i==n+1||j=m+1)
	    map[i][j]='X';
	  else
	    cin>>map[i][j];
      
      tmp=new Node;
      tmp->x=1;
      tmp->y=1;
      tmp->deep=1;
      while(!pq.empty())
	{
	  if(pq.top().x==n&&pq.top().y==m)
	    {
	      has_ans=true;
	      cout<<"It takes "<<pq.top().deep<<" seconds to reach the target position, let me show you the way."<<endl;
	      break;
	    }
	  
	  
	}
      
    }
}
