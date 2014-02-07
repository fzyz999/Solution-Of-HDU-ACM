#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Sticks
{
    int w,l;
    bool flag;
};

bool operator < (const Sticks& a,const Sticks& b)
{
    return a.l<b.l || (a.l==b.l && a.w<b.w);
}

bool operator <= (const Sticks& a,const Sticks& b)
{
    return a.l<=b.l && a.w<=b.w;
}

int main()
{
    int T,n,i;
    Sticks sticks[5000];
    memset(sticks,0,sizeof(sticks));
    
    cin>>T;
    while(T--)
    {
        cin>>n;
        
        for(i=0;i<n;i++)
            cin>>sticks[i].l>>sticks[i].w;
        
        sort(sticks,sticks+n);
        
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(!sticks[i].flag)
            {
                ans++;
                sticks[i].flag=1;
            
                register int tmp=i;
                for(register int j=i+1;j<n;j++)
                    if(!sticks[j].flag && sticks[tmp]<=sticks[j])
                    {
                        sticks[j].flag=1;
                        tmp=j;
                    }
            }
        }
        
        cout<<ans<<endl;
        
        memset(sticks,0,sizeof(Sticks)*n);
    }
    
    return 0;
}
