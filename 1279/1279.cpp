#include <iostream>

using namespace std;

int main()
{
    int N;

    cin>>N;
    while(N--)
    {
	bool hasOutput=false;
	int n;
	cin>>n;
	while(n>1)
	{
	    if(n&1)
	    {
		if(hasOutput) cout<<' ';
		hasOutput = true;
		cout<<n;
		n=n*3+1;
	    }
	    else
	    {
		n>>=1;
	    }
	}
	if(!hasOutput)
	{
	    cout<<"No number can be output !";
	}
	cout<<endl;
    }
    
    return 0;
}
