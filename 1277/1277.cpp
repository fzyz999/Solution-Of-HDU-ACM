#include <iostream>

using namespace std;

struct Key
{
     char str[60];
     int hash;
     int first_find;
};

int involution[61];

void init()
{
     int i;
     involution[0]=1;
     for(i=1;i<61;i++)
	  involution[i]=(involution[i-1]*3)%10000000;
}

void KSort(Key key[],int low,int high)
{
     if(low<high)
     {
	  int i=low,j=high;
	  Key v=key[i];
	  while(i<j)
	  {
	       while(i<j && v.hash<=key[j].hash) j--;
	       key[i]=key[j];
	       while(i<j && v.hash>=key[i].hash) i++;
	       key[j]=key[i];
	  }
	  key[i]=v;
	  KSort(low,i-1);
	  KSort(i+1,high);
     }
     return ;
}

int main()
{
     int n,m,i,j,len,k;
     char text[60001];
     int tmp,size;
     Key key[1000];
     bool is_check;

     while(cin>>n>>m)
     {
	  size=0;
	  memset(text,0,sizeof(text));
	  while(n--)
	       cin.getline(&text[strlen(text)],60000);

	  while(scanf("[Key No. %d] %s",&tmp,key[size++].str)!=EOF&&tmp<m);

	  for(i=0;i<size;i++)
	  {
	       tmp=0;
	       for(j=0,len=strlen(key[i].str);j<l;j++)
		    tmp=(tmp+key[i].str[j])*involution[j]%10000000;
	       key[i].hash=tmp;
	       key[i].first_find=-1;
	  }

	  for(i=0;i<size;i++)
	  {
	       len=strlen(key[i].str);
	       tmp=0;
	       for(j=0;j<len-1;j++)
		    tmp=(tmp+text[j])*involution[j]%10000000;
	       for(len=strlen(text);j<len;j++)
	       {
		    tmp=(tmp+key[i].str[j])*involution[j]%10000000;
		    if(tmp==key[i].hash)
		    {
			 is_check=false;
			 for(k=j-strlen(k[i].str))
		    }
	       }
	  }
     }

     return 0;
}
