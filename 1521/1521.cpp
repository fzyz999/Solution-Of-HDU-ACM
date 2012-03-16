#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int factorial[12]={1,1,2,6,24,120,720,5040,40320,362880,3628800,3991680};

int main()
{
     int i,j,n,m,a,k,p;
     double modulus[2][12];

     while(cin>>n>>m)
     {
	  p=0;
	  memset(modulus,0,sizeof(modulus));
	  cin>>a;
	  for(i=0;i<=a;i++)
	       modulus[p][i]=1.0/double(factorial[i]);

	  for(i=1;i<n;i++)
	  {
	       cin>>a;
	       for(j=0;j<=n;j++)
		    for(k=0;k<=a;k++)
			 if(j+k<12)
			      modulus[p^1][j+k]+=modulus[p][j]/double(factorial[k]);
	       p^=1;
	       for(j=0;j<12;j++)
		    modulus[p^1][j]=0;
	  }

	  cout<<fixed<<setprecision(0)<<modulus[p][m]*double(factorial[m])<<endl;
     }

     return 0;
}
