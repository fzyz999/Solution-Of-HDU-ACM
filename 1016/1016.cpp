#include <cstdio>
#include <cstdlib>
#include <cstring>

bool isPrime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0};
bool isUsed[21]={0};
int ans[21];

void search(int n,const int N)
{
    if (n==N)
    {
        if(isPrime[ans[n-1]+1])
        {
            printf("%d",ans[0]);
            for(int i=1;i<n;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
        return ;
    }
    
    for(int i=2;i<=N;i++)
    {
        if(!isUsed[i] && isPrime[ans[n-1]+i])
        {
            isUsed[i]=true;
            ans[n]=i;
            search(n+1,N);
            isUsed[i]=false;
        }
    }
}

int main()
{
    
    int n,t=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        memset(isUsed,0,sizeof(isUsed));
        isUsed[1]=1;
        ans[0]=1;
        printf("Case %d:\n",t);
            
        search(1,n);
        printf("\n");
        t++;
    }
    
    return 0;
}
