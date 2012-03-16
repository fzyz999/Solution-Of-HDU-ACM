#include <iostream>

using namespace std;

int main()
{
     unsigned long long fibonacci[51];
     int i;
     fibonacci[0]=0;
     fibonacci[1]=1;
     for(i=2;i<=50;i++)
	  fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];

     while(cin>>i&&i!=-1)
	  cout<<fibonacci[i]<<endl;

     return 0;
}
