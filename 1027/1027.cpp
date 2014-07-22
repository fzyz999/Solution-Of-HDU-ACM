#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int
main()
{
    int n,m,i;
    vector<int> num;

    while(cin>>n>>m)
    {
	num.clear();
	for(i=1;i<=n;i++)
	num.push_back(i);

	for(i=1;i<m;i++)
	next_permutation(num.begin(),num.end());

	cout<<num[0];
	for(i=1;i<n;i++)
	cout<<' '<<num[i];
	cout<<endl;
    }

    return 0;
}
