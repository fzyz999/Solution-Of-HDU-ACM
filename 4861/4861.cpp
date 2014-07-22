#include <cstdio>

using namespace std;

int main()
{
    int k,p;
    while(scanf("%d%d",&k,&p)!=EOF)
    {
        printf("%s\n",(k/(p-1))&1?"YES":"NO");
    }

    return 0;
}
