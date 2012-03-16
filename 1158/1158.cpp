#include <iostream>
#include <string.h>

using namespace std;

int n,fire_cost,hire_cost,s_cost,min_workers[13],max_workers;
int f[13][500000];

int search(int month, int w)
{
     if(f[month][w]!=-1)
	  return f[month][w];

     if(month==n)
	  return 0;

     int i,Min=0xfffffff,ret;
     for(i=min_workers[month+1];i<=max_workers;i++)
     {
	  ret=search(month+1,i);
	  if(i<w)
	       ret+=fire_cost*(w-i);
	  else
	       ret+=hire_cost*(i-w);
	  Min=Min<ret?Min:ret;
     }

     return f[month][w]=Min+w*s_cost;
}

int main()
{
     int i,j,Min,ret;
     while(cin>>n && n!=0)
     {
	  for(i=0;i<13;i++)
	       for(j=0;j<500000;j++)
		    f[i][j]=-1;

	  Min=0xfffffff;
	  max_workers=0;
	  cin>>hire_cost>>s_cost>>fire_cost;

	  for(i=0;i<n;i++)
	  {
	       cin>>min_workers[i];
	       max_workers=max_workers>min_workers[i]?max_workers:min_workers[i];
	  }

	  for(i=min_workers[0];i<=max_workers;i++)
	  {
	       ret=search(0,i)+i*hire_cost;
	       Min=Min<ret?Min:ret;
	  }

	  cout<<Min<<endl;
     }
     
     return 0;
}
