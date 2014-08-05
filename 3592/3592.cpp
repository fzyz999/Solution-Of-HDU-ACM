#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <cstring>


#define MAX_N 10010
#define INF 0xfffffff

using namespace std;

struct Edge
{
    int to;
    int cost;
    Edge(){}
    Edge(int _to,int _cost):
	to(_to),
	cost(_cost){}
};

list<Edge> graph[MAX_N];
bool inQueue[MAX_N];
int d[MAX_N],cnt[MAX_N];

int spfa(int n)
{
    queue<int> q;
    q.push(1);
    d[1]=0;
    bool flag=true;
    while (!q.empty() && flag) {
	int v=q.front();
	for (list<Edge>::iterator i = graph[v].begin();
	     i != graph[v].end();
	     ++i)
	{
	    if(d[v]+i->cost<d[i->to])
	    {
		d[i->to]=d[v]+i->cost;
		if(!inQueue[i->to])
		{
		    inQueue[i->to]=true;
		    q.push(i->to);
		    cnt[i->to]++;
		    if(cnt[i->to]>n)
		    {
			flag=false;
			break;
		    }
		}
	    }
	}
	inQueue[v]=false;
	q.pop();
    }

    if(!flag)
    {
	return -1;
    }
    else
    {
	return (d[n]==INF)?-2:d[n];
    }
}

int main()
{
    int T;

    scanf("%d", &T);
    while (T--) {
	int n,x,y,i;
	
	memset(inQueue,0,sizeof(inQueue));
	
	scanf("%d%d%d", &n,&x,&y);

	for (i = 0; i <= n; i++) {
	    graph[i].clear();
	    d[i]=INF;
	    cnt[i]=0;
	}


	for (i=0; i < x; i++) {
	    int a,b,c;
	    scanf("%d%d%d", &a,&b,&c);
	    graph[a].push_back(Edge(b,c));
	}

	for (i = 0; i < y; i++) {
	    int a,b,c;
	    scanf("%d%d%d", &a,&b,&c);
	    graph[b].push_back(Edge(a,-c));
	}

	for (i = 1; i < n; i++) {
	    graph[i+1].push_back(Edge(i,0));
	}

	printf("%d\n", spfa(n));
    }
    
    return 0;
}
