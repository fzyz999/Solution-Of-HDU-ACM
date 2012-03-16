#include <iostream>
#include <string.h>

using namespace std;

int
main()
{
  unsigned char ans[200001];
  int t,i,l,n;
  int tmp;

  while(cin>>n)
    {
      memset(ans,0,sizeof(ans));

      ans[0]=1;
      l=1;
      for(t=2;t<=n;t++)
	{
	  tmp=0;
	  if(t==255)
	    cout<<"stop"<<endl;
	  for(i=0;i<l;i++)
	    {
	      ans[i]*=t;
	      ans[i]+=tmp;
	      if(ans[i]>=10)
		{
		  tmp=ans[i]/10;
		  ans[i]%=10;
		}
	      else
		tmp=0;
	    }
	  while(tmp)
	    {
	      ans[i++]=tmp%10;
	      tmp/=10;
	    }

	  l=i;
	}

      for(i=l-1;i>=0;i--)
	cout<<(int)ans[i];
      cout<<endl;
    }
  

  return 0;
}


