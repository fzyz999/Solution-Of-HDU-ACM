#include<iostream>

using namespace std;

int main()
{
    int i,j,s;

    while (cin>>i)
    {
          s=0;

          for (j=1;j<=i;j++)
              s+=j;

          cout<<s<<endl<<endl;
    }
    return 0;
}

