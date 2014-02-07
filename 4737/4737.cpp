#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
	int result;
	int range_l,range_h;
};

Node tree[1<<17];

int build_tree(int array[],int root, int low, int high)
{		
	tree[root].range_l=low;
	tree[root].range_h=high;
	
	int res=0;
	if(high!=low)
	{
	}
	else
		res=array[high];

	res
}

int main()
{
	return 0;
}