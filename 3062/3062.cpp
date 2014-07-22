#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_N 2010

struct Node
{
    int to;
    Node *next;
    Node():next(NULL){}
    Node(int _to,Node* _next):
	to(_to),
	next(_next){}
};

Node *graph[MAX_N];

void addEdge(int a,bool c1,int b,bool c2)
{
    int from=(a<<1)+c1;
    int to=(b<<1)+c2;
    Node *tmp=graph[from];
    graph[from]=new Node(to,tmp);
}

int dfn[MAX_N],low[MAX_N],blg[MAX_N],blg_size,step,g_stack[MAX_N],stack_top;
bool instack[MAX_N];

void tarjan(int u)
{
    dfn[u]=low[u]=step++;
    g_stack[stack_top++]=u;
    instack[u]=true;
    for (Node *tmp=graph[u]; tmp!=NULL; tmp=tmp->next) {
	if(dfn[tmp->to]==-1)
	{
	    tarjan(tmp->to);
	    low[u]=low[u]<low[tmp->to]?low[u]:low[tmp->to];
	}
	else if(instack[tmp->to])
	{
	    low[u]=low[u]<dfn[tmp->to]?low[u]:dfn[tmp->to];
	}
    }

    if(dfn[u] == low[u])
    {
	blg_size++;
	int v;
	do
	{
	    v=g_stack[--stack_top];
	    instack[v]=false;
	    blg[v]=blg_size;
	}while(v!=u);
    }
}

void init(int n)
{
    step=0;
    blg_size=0;
    memset(graph,0,sizeof(graph));
    memset(dfn,-1,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
}

int main()
{
    int n,m;
    while(scanf("%d", &n)!=EOF){
	init(n);	
	
	scanf("%d",&m);
	int i;
	for (i = 0; i < m; i++) {
	    int a1,a2,c1,c2;
	    scanf("%d%d%d%d", &a1,&a2,&c1,&c2);
	    addEdge(a1,c1,a2,1^c2);
	    addEdge(a2,c2,a1,1^c1);
	}

	for (i = 0; i < (n<<1); i++) {
	    if(dfn[i]==-1)
	    {
		tarjan(i);
	    }
	}

	bool ans=true;
	for (i = 0; i < n; i++) {
	    if(blg[(i<<1)]==blg[(i<<1)+1])
	    {
		ans=false;
		break;
	    }
	}
	printf("%s\n", ans?"YES":"NO");
    }
    
    return 0;
}
