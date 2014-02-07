#include <cstdio>
#include <cstdlib>

int main()
{
     int n,i,mask;
     char tmp[40];
     
     while(scanf("%d",&n)!=EOF)
     {
          mask=1;
          for(i=0;i<32;mask<<=1,i++)
               tmp[i]='0'+bool(n&mask);

          for(i=31;i>=0;i--)
               if(tmp[i]!='0')
                    break;
          i=i<0?0:i;
          for(;i>=0;i--)
               printf("%c",tmp[i]);
          printf("\n");
     }
     
     return 0;
}
















