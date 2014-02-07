#include <iostream>

using namespace std;

int a[100001];

void Sort(int a[],int low,int high,const int &m)
{
     if(low<high)
     {
          int v=a[low],i=low,j=high;
          while(i<j)
          {
               while(i<j && v>=a[j]) j--;
               a[i]=a[j];
               while(i<j && v<=a[i]) i++;
               a[j]=a[i];
          }
          a[i]=v;
          Sort(a,low,i-1,m);
          if(m>i)
               Sort(a,i+1,high,m);
     }
     
     return ;
}

int main()
{
     int n,m,i;

     while(cin>>n>>m && (n!=0||m!=0))
     {
          for(i=0;i<n;i++)
               cin>>a[i];

          Sort(a,0,n-1,m);

          cout<<a[0];
          for(i=1;i<m;i++)
               cout<<' '<<a[i];
          cout<<endl;
     }

     return 0;
}
