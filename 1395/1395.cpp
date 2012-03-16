/*
两处优化，解决超时问题：
1、算到n被2^x整除时，不必再算，因为2^x%n=0则2^(x+k)%n=0。
2、n为偶数时不可能有解。
3、同余定理，处理i超过int32范围问题。
 */
#include <iostream>

using namespace std;

int main()
{
     unsigned int n,ans,i;
     bool has_ans;

     while(cin>>n)
     {
	  has_ans=false;
	  if(n&1)
	  {
	       for(i=2,ans=1;i!=0;i<<=1,ans++)
	       {
		    if(i%n==1)
		    {
			 has_ans=true;
			 cout<<"2^"<<ans<<" mod "<<n<<" = 1"<<endl;
			 break;
		    }
		    i%=n;
	       }
	  }
	  if(!has_ans)
	       cout<<"2^? mod "<<n<<" = 1"<<endl;
     }

     return 0;
}
