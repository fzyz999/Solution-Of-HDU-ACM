#include <iostream>

using namespace std;

int main()
{
     int n,i,j,k,t;
     int num[100][100],sum[100][100];

     int s,Max;

     while(cin>>n)
     {
	  for(i=0;i<n;i++)
	       for(j=0;j<n;j++)
		    cin>>num[i][j];

	  for(i=0;i<n;i++)
	  {
	       sum[i][0]=num[i][0];
	       for(j=1;j<n;j++)
		    sum[i][j]=sum[i][j-1]+num[i][j];
	  }

	  Max=-0xfffffff;
	  for(i=0;i<n;i++)
	  {
	       for(j=0;j<n;j++)
	       {
		    for(k=j;k<n;k++)
		    {
			 s=sum[i][k]-sum[i][j]+num[i][j];
			 for(t=i+1;s>0&&t<n;t++)
			 {
			      s+=sum[t][k]-sum[t][j]+num[t][j];
			      Max=Max>s?Max:s;
			 }
		    }
	       }
	  }
	  
	  cout<<Max<<endl;
     }

     return 0;
}
