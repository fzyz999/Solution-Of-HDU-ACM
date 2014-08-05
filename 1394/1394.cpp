#include <cstdio>
#include <cstdlib>

#define MAX_N 5010
#define LSON(X) ((X)<<1)
#define RSON(X) (((X)<<1)+1)

struct Node
{
    int l,r;
    int sum;
};

Node sgt[MAX_N<<2];

void build(int root,int l,int r)
{
    sgt[root].l=l;
    sgt[root].r=r;
    sgt[root].sum=0;
    if(l!=r)
    {
	build(LSON(root),l,(l+r)>>1);
	build(RSON(root), ((l+r)>>1)+1, r);
    }
}

void push_up(int root)
{
    sgt[root].sum=sgt[LSON(root)].sum+sgt[RSON(root)].sum;
}

void update(int root, int pos)
{
    if(sgt[root].l==sgt[root].r && sgt[root].l==pos)
    {
	sgt[root].sum++;
	return ;
    }
    if(pos<=sgt[LSON(root)].r) update(LSON(root), pos);
    else update(RSON(root), pos);
    push_up(root);
}

int query(int root,int L, int R)
{
    if(sgt[root].l>=L && sgt[root].r<=R){
	return sgt[root].sum;
    }
    register int mid=(sgt[root].l+sgt[root].r)>>1;
    int ret=0;
    if(L<=mid) ret+=query(LSON(root), L, R);
    if(R>mid) ret+=query(RSON(root), L, R);
    return ret;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
	int i,x[MAX_N];
	int sum=0;
	build(1, 0, n-1);
	for (i = 0; i < n; i++) {
	    scanf("%d", x+i);
	    sum+=query(1, x[i], n-1);
	    update(1, x[i]);
	}
	int _min=sum;
	for (i = 0; i < n; i++) {
	    sum+=n-x[i]-x[i]-1;
	    _min=_min<sum?_min:sum;
	}
	printf("%d\n", _min);
    }
    
    return 0;
}
