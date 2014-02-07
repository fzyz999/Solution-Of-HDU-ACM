#include <cstdio>
#include <cstring>
#define MAX_N 2001

int p[MAX_N],h[MAX_N],c[MAX_N],f[110];

int main()
{
    int C,n,m;
    
    scanf("%d",&C);
    while(C--)
    {
        memset(f,0,sizeof(f));
        scanf("%d %d",&n,&m);
       
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&p[i],&h[i],&c[i]);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int k=0;k<c[i];k++)
                for(int j=n;j>=p[i];j--)
                    f[j]=f[j]>f[j-p[i]]+h[i]?f[j]:f[j-p[i]]+h[i];
        }
        
        int Max=0;
        for(int i=0;i<=n;i++)
            Max=Max>f[i]?Max:f[i];
        printf("%d\n",Max);
    }

    return 0;
}
