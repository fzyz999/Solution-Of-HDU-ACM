#include <cstdio>
#include <cstdlib>
#include <cmath>

int
main()
{
  int t,n,i,ans;
  bool is_ans;

  scanf("%d",&t);
  while(t--)
    {
      is_ans=false;
      scanf("%d",&n);
      for(i=(int)sqrt(double(n));i>0;i--)
	{
	  while(n%i!=0 && i>0) i--;
	  if(i>0 && n%i==0)
	    {
	      ans=n/i-i;
	      if((ans&1)==0 && ans>0)
		{
		  is_ans=true;
		  printf("%d\n",(ans>>1));
		  break;
		}
	    }
	}

      if(!is_ans)
	printf("-1\n");
    }

  return 0;
}
