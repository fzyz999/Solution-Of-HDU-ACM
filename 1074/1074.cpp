#include <iostream>

using namespace std;

struct Homework
{
     int d,c;
};

Homework h[15];
int final_ans[15],f[65536],flag[15];

void search(int k, int cost, int day, const int &n,int p,int ans[], bool has_used[], int &Min)
{
     if(cost>=Min)
	  return ;
     if(k>=n)
     {
	  if(cost<Min)
	  {
	       Min=cost;
	       for(int i=0;i<n;i++)
		    final_ans[i]=ans[i];
	  }

	  return ;
     }

     if(cost>=f[p])
	  return ;
     else
	  f[p]=cost;

     int i;
     for (i=0;i<n;i++)
	  if(!has_used[i])
	  {
	       has_used[i]=true;
	       ans[k]=i;
	       if(day+h[i].c<=h[i].d)
		    search(k+1,cost,day+h[i].c,n,p|flag[i],ans,has_used,Min);
	       else
		    search(k+1,cost+day+h[i].c-h[i].d,day+h[i].c,n,p|flag[i], ans,has_used,Min);
	       has_used[i]=false;
	  }

     return ;
}

int main()
{
     int t,n,i,Min;
     char name[15][101];
     int ans[15];
     bool has_used[15];

     //init
     for(i=0;i<15;i++)
	  flag[i]=(1<<i);
     //

     cin>>t;
     while(t--)
     {
	  cin>>n;
	  for(i=0;i<n;i++)
	  {
	       has_used[i]=false;
	       cin>>name[i]>>h[i].d>>h[i].c;
	  }

	  for(i=(1<<n);i>=0;i--)
	       f[i]=0xfffffff;

	  Min=0xfffffff;
	  search(0,0,0,n,0,ans,has_used,Min);
	  cout<<Min<<endl;
	  for(i=0;i<n;i++)
	       cout<<name[final_ans[i]]<<endl;
     }


     return 0;
}
