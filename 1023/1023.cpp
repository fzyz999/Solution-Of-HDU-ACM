#include <iostream>
#include <string.h>
#define MAX_LENTH 500

using namespace std;

class Int
{
     int num[MAX_LENTH];
     int size;

public:
     Int(){size=1;memset(num,0,sizeof(num));//初始值为0
     void operator =(int n);
     void operator *=(int n);

     friend ostream& << (ostream& os, Int &n);
};
     
int main()
{
     Int a,b;

     a=1;
     b=2;
     
     
     return 0;
}

void Int::operator = (int n)
{
     int i;

     for(i=0;n>0;i++)
     {
	  num[i]=n%10000;
	  n/=10000;
     }

     if(i>size)
	  size=i;
}

void Int::operator *= (int n)
{
     int i,j;
     long long tmp;//防止n过大，导致乘积超过int范围

     for(i=0;i<size;i++)
     {
	  tmp=num[i]*n;
	 
	  num[i]=tmp%10000;
	  tmp/=10000;
	  for(j=i+1;tmp>0;j++)
	  {
	       num[j]+=tmp%10000;
	       tmp/=10000;
	  }
	  if(j>size)
	       size=j;
     }

     return ;
}

ostream& << (ostream& os, Int& n)
{
     int i;
     for(i=size-1;i>=0;i++)
	  cout<<num[i];
     cout<<endl;

     return os;
}
