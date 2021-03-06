#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define MAX_N 105

using namespace std;
    
struct Node
{
    int x,y;
    int deep;
};

bool operator < (const Node &a, const Node &b)
{
    return (a.deep>b.deep);
}

int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char map[MAX_N][MAX_N];
char dir[MAX_N][MAX_N];
bool isVisited[MAX_N][MAX_N];

int printRoute(const int x,const int y)
{
    if(dir[x][y]==-1)
    {
        if(map[x][y]!='.')
        {
            for(int i= 0;i<map[x][y]-'0';i++)
            {
                printf("%ds:FIGHT AT (%d,%d)\n",i+1,x-1,y-1);
            }
            return map[x][y]-'0';
        }
        else
            return 0;
    }
    
    int deep=printRoute(x-direction[(int)dir[x][y]][0],y-direction[(int)dir[x][y]][1]);
    
    printf("%ds:(%d,%d)->(%d,%d)\n",
           deep+1,
           x-direction[(int)dir[x][y]][0]-1,
           y-direction[(int)dir[x][y]][1]-1,
           x-1,
           y-1);
    
    deep++;
    if(map[x][y]!='.')
    {
        for(int i= deep;i<deep+map[x][y]-'0';i++)
        {
            printf("%ds:FIGHT AT (%d,%d)\n",i+1,x-1,y-1);
        }
        deep+=map[x][y]-'0';
    }
    
                
    return deep;
}

int main()
{
    int n,m,i,j;
    bool has_ans;

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        priority_queue<Node> pq;
        has_ans=false;

        for(i=0; i<=n+1; i++)
        {
            if(!(i==0||j==0||i==n+1||j==m+1))
                getchar();
            for(j=0; j<=m+1; j++)
            {
                dir[i][j]=-1;
                isVisited[i][j]=0;
                if(i==0||j==0||i==n+1||j==m+1)
                    map[i][j]='X';
                else
                    map[i][j]=getchar();
            }
        }

        Node tmp;
        tmp.x=1;
        tmp.y=1;
        tmp.deep=(map[tmp.x][tmp.y]=='.'?0:map[tmp.x][tmp.y]-'0');
        dir[1][1]=-1;
        isVisited[1][1]=1;
        pq.push(tmp);
        while(!pq.empty())
        {
            if(pq.top().x==n&&pq.top().y==m)
            {
                has_ans=true;
                printf("It takes %d seconds to reach the target position, let me show you the way.\n",
                printRoute(pq.top().x,pq.top().y));
                break;
            }

            
            Node top;
            top=pq.top();
            pq.pop();
            isVisited[top.x][top.y]=1;
            for(i=0;i<4;i++)
            {
                if(!isVisited[top.x+direction[i][0]][top.y+direction[i][1]] &&
                   map[top.x+direction[i][0]][top.y+direction[i][1]]!='X')
                {
                    tmp.x=top.x+direction[i][0];
                    tmp.y=top.y+direction[i][1];
                    tmp.deep=top.deep+1+(map[tmp.x][tmp.y]=='.'?
                                         0:map[tmp.x][tmp.y]-'0');
                    dir[tmp.x][tmp.y]=i;
                    pq.push(tmp);
                    isVisited[tmp.x][tmp.y]=1;
                }
            }
        }

        if(!has_ans)
        {
            printf("God please help our poor hero.\n");
        }
        printf("FINISH\n");
    }
}
