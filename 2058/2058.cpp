#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
     int n,m;

     while(cin>>n>>m && (n!=0 || m!=0))
     {
	  for (register int i=int(sqrt(double(m<<1)))+1;i>0;i--)
	  {
	       if((m<<1)%i==0 && (((m<<1)/i-i+1)&1)==0)
	       {
		    register int tmp=((((m<<1)/i-i+1))>>1);
		    if(tmp>0 && tmp<=n)
			 printf("[%d,%d]\n",tmp,tmp+i-1);
	       }
	  }

	  printf("\n");
     }

     return 0;
}
