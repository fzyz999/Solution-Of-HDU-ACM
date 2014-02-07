#include <iostream>

using namespace std;

unsigned long long int catalan[37];

int main()
{
     catalan[0]=1;
     catalan[1]=1;
     for(int i=2;i<37;i++)
          for(int j=1;j<i;j++)
               catalan[i]+=catalan[i-j]*catalan[j];

     for(int i=0;i<37;i++)
          catalan[i]<<=1;

     register int n,i=1;
     while(cin>>n&&n!=-1)
          cout<<i++<<' '<<n<<' '<<catalan[n+1]<<endl;
     
     return 0;
}
