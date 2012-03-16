#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
     long long int a,b;
     char c1[20],c2[20];
     while(scanf("%s %s",c1,c2)!=EOF)
     {
	  if(c1[0]=='-'||c1[0]=='+')
	       sscanf(&c1[1],"%I64X",&a);
	  else
	       sscanf(c1,"%I64X",&a);
	  if(c1[0]=='-')
	       a*=-1;
	  if(c2[0]=='-'||c2[0]=='+')
	       sscanf(&c2[1],"%I64X",&b);
	  else
	       sscanf(c2,"%I64X",&b);
	  if(c2[0]=='-')
	       b*=-1;

	  a+=b;
	  if(a<0)
	  {
	       cout<<'-';
	       a*=-1;
	  }
	  printf("%I64X",a);
	  cout<<endl;
     }

     return 0;
}
